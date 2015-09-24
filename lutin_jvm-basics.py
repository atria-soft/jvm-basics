#!/usr/bin/python
import lutin.module as module
import lutin.tools as tools

def get_desc():
	return "jvm basis call for all element who have jvm access"

def create(target):
	# module name is 'edn' and type binary.
	my_module = module.Module(__file__, 'jvm-basics', 'LIBRARY')
	my_module.add_module_depend(['etk'])
	# add extra compilation flags :
	my_module.add_extra_compile_flags()
	# add the file to compile:
	my_module.add_src_file([
		'jvm-basics/debug.cpp',
		'jvm-basics/jvm-basics.cpp'
		])
	my_module.add_header_file([
		'jvm-basics/jvm-basics.h'
		])
	my_module.compile_version_XX(2011)
	my_module.add_path(tools.get_current_path(__file__))
	return my_module


