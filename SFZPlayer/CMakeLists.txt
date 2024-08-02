cmake_minimum_required(VERSION 3.10)

# Project name
project(sfzero)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/sf2-chunks
        ${CMAKE_CURRENT_LIST_DIR}/vendor/surge
)

# Source files
set(SOURCES
        RIFF.cpp
        SampleBuffer.cpp
        SF2.cpp
        SF2Generator.cpp
        SF2Reader.cpp
        SF2Sound.cpp
        SFZEG.cpp
        SFZReader.cpp
        SFZRegion.cpp
        SFZSample.cpp
        SFZSound.cpp
        SFZSynth.cpp
        SFZVoice.cpp
        WAVReader.cpp
)

# Header files
set(HEADERS
        sf2-chunksgenerators.h
        sf2-chunks/bag.h
        sf2-chunks/igen.h
        sf2-chunks/imod.h
        sf2-chunks/inst.h
        sf2-chunks/iver.h
        sf2-chunks/pbag.h
        sf2-chunks/pgen.h
        sf2-chunks/phdr.h
        sf2-chunks/pmod.h
        sf2-chunks/shdr.h
        vendor/surge/Tunings.h
        vendor/surge/TuningsImpl.h
        Decibels.h
        MIDINoteFrequency.h
        OutBuffer.h
        RIFF.h
        SampleBuffer.h
        SF2.h
        SF2Generator.h
        SF2Reader.h
        SF2Sound.h
        SFZEG.h
        SFZFloat.h
        SFZReader.h
        SFZRegion.h
        SFZSample.h
        SFZSound.h
        SFZSynth.h
        SFZVoice.h
        WAVReader.h
        WinTypes.h
)

# Add library
add_library(sfzero STATIC ${SOURCES} ${HEADERS})

# Optionally, specify the library's include directories
target_include_directories(sfzero PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/sf2-chunks ${CMAKE_CURRENT_LIST_DIR}/vendor/surge)
