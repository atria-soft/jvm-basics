/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <jni.h>
#include <pthread.h>
#include <ethread/Mutex.hpp>
#include <jvm-basics/debug.hpp>
#include <jvm-basics/jvm-basics.hpp>

// jni doc : /usr/lib/jvm/java-1.6.0-openjdk/include

// Global JVM (can only have 1)
JavaVM*& jvm_basics::getJavaVM() {
	static JavaVM* g_JavaVM=nullptr; // global acces on the unique JVM !!!
	return g_JavaVM;
}
ethread::Mutex& jvm_basics::getMutexJavaVM() {
	static ethread::Mutex g_jvmMutex;
	return g_jvmMutex;
}

void jvm_basics::checkExceptionJavaVM(JNIEnv* _env) {
	if (_env->ExceptionOccurred()) {
		JVMB_ERROR("C->java : EXEPTION ...");
		_env->ExceptionDescribe();
		_env->ExceptionClear();
	}
}

extern "C" {
	// JNI onLoad
	JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* _jvm, void* _reserved) {
		// get the java virtual machine handle ...
		std::unique_lock<ethread::Mutex> lock(jvm_basics::getMutexJavaVM());
		jvm_basics::getJavaVM() = _jvm;
		JVMB_INFO("JNI-> load the jvm ..." );
		return JNI_VERSION_1_6;
	}
	// JNI onUnLoad
	JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* _vm, void *_reserved) {
		std::unique_lock<ethread::Mutex> lock(jvm_basics::getMutexJavaVM());
		jvm_basics::getJavaVM() = nullptr;
		JVMB_INFO("JNI-> Un-load the jvm ..." );
	}
}

