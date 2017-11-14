cmake_minimum_required(VERSION 3.7)

project(effective_cmake)

add_executable(program
	main.cxx
)

target_sources(program PRIVATE main.h)