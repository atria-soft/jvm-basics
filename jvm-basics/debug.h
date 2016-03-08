/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <elog/log.h>

namespace jvm_basics {
	int32_t getLogId();
}
#define JVMB_BASE(info,data) ELOG_BASE(jvm_basics::getLogId(),info,data)

#define JVMB_PRINT(data)         JVMB_BASE(-1, data)
#define JVMB_CRITICAL(data)      JVMB_BASE(1, data)
#define JVMB_ERROR(data)         JVMB_BASE(2, data)
#define JVMB_WARNING(data)       JVMB_BASE(3, data)
#ifdef DEBUG
	#define JVMB_INFO(data)          JVMB_BASE(4, data)
	#define JVMB_DEBUG(data)         JVMB_BASE(5, data)
	#define JVMB_VERBOSE(data)       JVMB_BASE(6, data)
	#define JVMB_TODO(data)          JVMB_BASE(4, "TODO : " << data)
#else
	#define JVMB_INFO(data)          do { } while(false)
	#define JVMB_DEBUG(data)         do { } while(false)
	#define JVMB_VERBOSE(data)       do { } while(false)
	#define JVMB_TODO(data)          do { } while(false)
#endif

#define JVMB_ASSERT(cond,data) \
	do { \
		if (!(cond)) { \
			JVMB_CRITICAL(data); \
			assert(!#cond); \
		} \
	} while (0)

