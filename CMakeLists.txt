cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project (sitemap-crawler)
enable_testing()
include(ExternalProject)

if(UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

set(LIBPREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}")
set(LIBSUFFIX "${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(sitemap-crawler_VERSION_MAJOR 1)
set(sitemap-crawler_VERSION_MINOR 0)
set(Boost_FIND_REQUIRED TRUE)
set(Boost_FIND_QUIETLY TRUE)
set(Boost_DEBUG TRUE)
set(Boost_USE_MULTITHREADED TRUE)
set(CMAKE_VERBOSE_MAKEFILE on)

find_package(Boost REQUIRED COMPONENTS
	iostreams
	filesystem
	date_time
	system
	program_options
)

add_definitions (-DBoost_USE_STATIC_LIBS=ON)
add_subdirectory(src)
add_subdirectory(test)