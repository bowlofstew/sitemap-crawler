SET(CMAKE_EXE_LINKER_FLAGS  "-lcrypto" )
find_library(OPENSSL_LIB ssl $ENV{OPENSSL_LIB_PATH})

include_directories(. ../inc ../thirdparty/netlib)
add_executable (sitemap-crawler main.cc)
target_link_libraries(sitemap-crawler
        ${Boost_LIBRARIES}
        ${OPENSSL_LIB}
        ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/netlib/libs/network/src/libcppnetlib-client-connections.a
        ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/netlib/libs/network/src/libcppnetlib-server-parsers.a
        ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/netlib/libs/network/src/libcppnetlib-uri.a
)


