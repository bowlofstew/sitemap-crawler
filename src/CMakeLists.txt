include_directories(. ../inc)
add_executable (sitemap-crawler main.cc)
target_link_libraries(sitemap-crawler
        ${Boost_LIBRARIES}
)


