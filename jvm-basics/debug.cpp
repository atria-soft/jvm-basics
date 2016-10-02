/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <jvm-basics/debug.hpp>

int32_t jvm_basics::getLogId() {
	static int32_t g_val = elog::registerInstance("jvm-basics");
	return g_val;
}
