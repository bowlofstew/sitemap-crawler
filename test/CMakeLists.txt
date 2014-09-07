enable_testing()
ExternalProject_Add(
    googletest
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/gtest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r 690
    TIMEOUT 10
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    INSTALL_COMMAND ""
    TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../tmp/gtest
    STAMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../stamp/gtest
    LOG_DOWNLOAD 1
    LOG_UPDATE 1
    LOG_CONFIGURE 1
    LOG_BUILD 1
    LOG_TEST 1
    LOG_INSTALL 1
    BUILD_IN_SOURCE 1
)

include_directories(. ../inc ../src ../thirdparty/gtest/include)
add_executable (sitemap-tests sitemap-tests.cc)
add_dependencies(sitemap-tests googletest)
target_link_libraries(sitemap-tests
        ${Boost_LIBRARIES}
        ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/gtest/libgtest.a
        ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/gtest/libgtest_main.a
)
add_test(sitemap-tests ${CMAKE_CURRENT_BINARY_DIR}/sitemaps-tests)