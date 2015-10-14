#!/usr/bin/python
import lutin.module as module
import lutin.tools as tools
import os


def get_type():
	return "LIBRARY"

def get_desc():
	return "jvm basis call for all element who have jvm access"

def get_licence():
	return "APACHE-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return ["Mr DUPIN Edouard <yui.heero@gmail.com>"]

def get_version():
	return [1,0]

def create(target, module_name):
	my_module = module.Module(__file__, module_name, get_type())
	my_module.add_module_depend(['etk'])
	my_module.add_extra_compile_flags()
	my_module.add_src_file([
		'jvm-basics/debug.cpp',
		'jvm-basics/jvm-basics.cpp'
		])
	my_module.add_header_file([
		'jvm-basics/jvm-basics.h'
		])
	my_module.compile_version("c++", 2011)
	my_module.add_path(tools.get_current_path(__file__))
	return my_module


