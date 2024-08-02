cmake_minimum_required(VERSION 3.10)

# Project name
project(sfzero)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)

option(SFZERO_ENABLE_TESTING "Enable testing for soundfont module" ON)



if (NOT SFZERO_ENABLE_TESTING)
    if("${JUCE_MODULES_DIR}" STREQUAL "")
        message(STATUS "Can't use this outside of JUCE")

    else()
        message(STATUS "Adding SFZero JUCE modules...")
        juce_add_module(

                SFZPlayer/sfzero_juce/sfzero_juce.h
        ALIAS_NAMESPACE sfzero)
        endif()
else()
        list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
        list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/test)


        if(SFZERO_ENABLE_TESTING)
            enable_testing()
            add_subdirectory(tests)
        endif ()
endif()

# Useful for testing with address sanitizer:
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")



## Add library
#add_library(sfzero STATIC ${SOURCES} ${HEADERS})
#
## Optionally, specify the library's include directories
#target_include_directories(sfzero PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/sf2-chunks ${CMAKE_CURRENT_LIST_DIR}/vendor/surge)
