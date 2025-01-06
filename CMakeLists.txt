cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CPCD VERSION 0.1.0 LANGUAGES CXX)

if(_WIN32)
    set(OS_TYPE "Windows")
elseif(UNIX)
    set(OS_TYPE "Unix")
elseif(LINUX)
    set(OS_TYPE "Linux")
endif()

add_executable(CPCD WIN32 main.cpp)

if(WIN32)
    add_compile_options(/O2 /GL)
    add_link_options(/LTCG)
else()
    add_compile_options(-O2 -march=native)
endif()

if(WIN32)
    set_target_properties(CPCD PROPERTIES OUTPUT_NAME "CPCD")
    target_link_libraries(CPCD -static-libgcc -static-libstdc++ -static)
elseif(LINUX)
    set_target_properties(CPCD PROPERTIES OUTPUT_NAME "CPCD")
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
