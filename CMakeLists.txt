cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project (sitemap-crawler)
enable_testing()
include(ExternalProject)

ExternalProject_Add(
  chromium-net
  GIT_REPOSITORY https://chromium.googlesource.com/chromium/src/net
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/chromium/net
  PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/chromium/net
  CONFIGURE_COMMAND ./configure --prefix=${CMAKE_BINARY_DIR}
  TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}//tmp/chromium/net
  STAMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}//stamp/chromium/net
  LOG_DOWNLOAD 1
  LOG_UPDATE 1
  LOG_CONFIGURE 1
  LOG_BUILD 1
  LOG_TEST 1
  LOG_INSTALL 1
)

ExternalProject_Add(
    googletest
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/gtest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r 690
    TIMEOUT 10
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    INSTALL_COMMAND ""
    TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp/gtest
    STAMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/stamp/gtest
    LOG_DOWNLOAD 1
    LOG_UPDATE 1
    LOG_CONFIGURE 1
    LOG_BUILD 1
    LOG_TEST 1
    LOG_INSTALL 1
    BUILD_IN_SOURCE 1
)

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
add_subdirectory(inc)
add_subdirectory(test)