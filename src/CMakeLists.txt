cmake_minimum_required(VERSION 3.5)

add_executable(fishing main.cpp ${MY_INCLUDE_DIR}/field.h field.cpp ${MY_INCLUDE_DIR}/fish.h fish.cpp
    ${MY_INCLUDE_DIR}/fcaught.h fcaught.cpp ${MY_INCLUDE_DIR}/bcaught.h bcaught.cpp ${MY_INCLUDE_DIR}/boot.h boot.cpp)

target_include_directories(fishing PUBLIC ${MY_INCLUDE_DIR})
