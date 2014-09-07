enable_testing()
include_directories(. ../inc ../src ../thirdparty/gtest/include)
add_executable (sitemap-tests sitemap-tests.cc)
add_dependencies(sitemap-tests googletest)
target_link_libraries(sitemap-tests
        ${Boost_LIBRARIES}
        ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/gtest/libgtest.a
        ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/gtest/libgtest_main.a
)
add_test(sitemap-tests ${CMAKE_CURRENT_BINARY_DIR}/sitemaps-tests)