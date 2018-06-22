cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME asg7)
project(${PROJECT_NAME})

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static")
endif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES asg7.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    if (WIN32)
        target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    else()
        target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
    endif()
endif()