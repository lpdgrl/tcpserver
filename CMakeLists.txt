cmake_minimum_required(VERSION 3.12)
project(tcpserver VERSION 0.1.0 LANGUAGES C CXX)


# target_include_directories(${PROJECT_NAME}
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

add_executable(${PROJECT_NAME} 
    src/tcpserver.cpp
    src/socket.cpp
    src/socketserver.cpp
)


