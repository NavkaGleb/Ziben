cmake_minimum_required(VERSION 3.19)
project(Ziben)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Sandbox)             # Subdirectory to test Ziben GameEngine
add_subdirectory(ZibenEditor)         # Ziben Editor
add_subdirectory(ZibenEngine)         # Ziben GameEngine

set(ZIBEN_ENABLE_PROFILING FALSE CACHE BOOL "ZibenEngine Param" FORCE)