cmake_minimum_required(VERSION 3.12)
project(tcpserver VERSION 0.1.0 LANGUAGES C CXX)


# target_include_directories(${PROJECT_NAME}
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

add_executable(${PROJECT_NAME} 
    include/socket.hpp
    include/socketclient.hpp
    include/socketserver.hpp
    include/tcpserver.hpp
    include/tcpclient.hpp
    include/connection_manager.hpp
    include/client_manager.hpp
    src/tcpserver.cpp
    src/tcpclient.cpp
    src/socket.cpp
    src/socketserver.cpp
    src/socketclient.cpp
    src/connection_manager.cpp
    src/client_manager.cpp
    main.cpp
)


