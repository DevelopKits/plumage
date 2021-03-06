cmake_minimum_required(VERSION 2.6)

PROJECT(plumage)

message(${CMAKE_SYSTEM})
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    include_directories(/usr/include ./)
    link_directories(/usr/lib)
    add_definitions(-DUNIX)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    include_directories(/opt/local/include /usr/include ./)
    link_directories(/opt/local/lib /usr/lib)
    add_definitions(-DMAC_OSX)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

ADD_LIBRARY(sample_plugin SHARED
    plugin/sample_plugin.cpp
    )

set(CMAKE_CXX_FLAGS_DEBUG "-g")

ADD_EXECUTABLE(plumage_sample sample.cpp)

set_target_properties(sample_plugin plumage_sample PROPERTIES COMPILE_FLAGS "-Wall -I ../include -std=c++11 -stdlib=libc++")

set_target_properties(sample_plugin PROPERTIES LINK_FLAGS "-L ../lib -lplumage -ldl -lc++")
set_target_properties(plumage_sample PROPERTIES LINK_FLAGS "-L ../lib -lplumage -ldl -lc++")

