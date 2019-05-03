#!/usr/bin/python
import realog.debug as debug
import lutin.tools as tools
import os


def get_type():
	return "LIBRARY"

def get_desc():
	return "jvm basis call for all element who have jvm access"

def get_licence():
	return "MPL-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return ["Mr DUPIN Edouard <yui.heero@gmail.com>"]

def get_version():
	return [1,2,0,"dev"]

def configure(target, my_module):
	my_module.add_depend(['etk'])
	my_module.add_extra_flags()
	my_module.add_src_file([
	    'jvm-basics/debug.cpp',
	    'jvm-basics/jvm-basics.cpp'
	    ])
	my_module.add_header_file([
	    'jvm-basics/jvm-basics.hpp'
	    ])
	my_module.compile_version("c++", 2011)
	my_module.add_path(".")
	return True


