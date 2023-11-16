cmake_minimum_required(VERSION 3.0.0)
project(lecturenote VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
include_directories(./include)
add_library(MyLibrary SHARED strVector.cpp Student.cpp wikiscraper.cpp)
target_include_directories(MyLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
enable_testing()

add_executable(lecturenote main.cpp)
target_link_libraries(lecturenote PRIVATE MyLibrary)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
