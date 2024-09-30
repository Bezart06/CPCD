cmake_minimum_required(VERSION 3.10)

project(CPCD)

if (WIN32)
    set(OS_TYPE "Windows")
elseif (UNIX)
    set(OS_TYPE "Linux")
elseif (LINUX)
    set(OS_TYPE "Linux")
endif ()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()

add_executable(CPCD WIN32 main.cpp)

if(OS_TYPE STREQUAL "Windows")
    set_target_properties(CPCD PROPERTIES OUTPUT_NAME "CPCD_executable")
    target_link_libraries(CPCD -static-libgcc -static-libstdc++ -static)
elseif(OS_TYPE STREQUAL "Linux")
    set_target_properties(CPCD PROPERTIES OUTPUT_NAME "CPCD_executable")
endif()

if(OS_TYPE STREQUAL "Windows")
    add_custom_command(TARGET CPCD
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E echo "Executable built for Windows"
    )
elseif(OS_TYPE STREQUAL "Linux")
    add_custom_command(TARGET CPCD
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E echo "Executable built for Linux"
            COMMAND sudo chmod +x $<TARGET_FILE:CPCD>
    )
endif()
