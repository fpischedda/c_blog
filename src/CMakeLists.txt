cmake_minimum_required(VERSION 2.8)

find_package(LibMicroHTTPD REQUIRED)
include_directories(${LibMicroHTTPD_INCLUDE_DIRS})
set(LIBS ${LIBS} ${LibMicroHTTPD_LIBRARIES})

add_executable(c_blog main.c view/layout.c models/page.c models/layout.c utils/file_utils.c utils/url_utils.c)

target_link_libraries(c_blog microhttpd)