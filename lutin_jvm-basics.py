#!/usr/bin/python
import lutin.module as module
import lutin.tools as tools

def get_desc():
	return "jvm basis call for all element who have jvm access"

def create(target):
	# module name is 'edn' and type binary.
	myModule = module.Module(__file__, 'jvm-basics', 'LIBRARY')
	myModule.add_module_depend(['etk'])
	# add extra compilation flags :
	myModule.add_extra_compile_flags()
	# add the file to compile:
	myModule.add_src_file([
		'jvm-basics/debug.cpp',
		'jvm-basics/jvm-basics.cpp'
		])
	myModule.add_header_file([
		'jvm-basics/jvm-basics.h'
		])
	myModule.compile_version_XX(2011)
	myModule.add_path(tools.get_current_path(__file__))
	return myModule


