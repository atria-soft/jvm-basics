/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#ifndef __JVM_BASICS_H__
#define __JVM_BASICS_H__

namespace jvm_basics {
	JavaVM*& getJavaVM();
	std::mutex& getMutexJavaVM();
	void checkExceptionJavaVM(JNIEnv* _env);
}

#endif