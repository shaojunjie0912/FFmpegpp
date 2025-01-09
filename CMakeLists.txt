cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(FFmpegpp LANGUAGES CXX)

find_package(FFMPEG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(TARGET_CORE "ffmpegpp-core")
add_subdirectory(FFmpegpp)
set(TARGET_TESTS "ffmpegpp-tests")
add_subdirectory(tests)
