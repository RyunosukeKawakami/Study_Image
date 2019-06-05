cmake_minimum_required(VERSION 3.0.0)
project(image VERSION 0.1.0)

include(CTest)
enable_testing()
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# make main project
set(SOURCES
    Filtering.cpp
    Blending.cpp
    ImageValue.cpp
    Histogram.cpp
    main.cpp)

set(HEADER
    Filtering.h
    Blending.h
    ImageValue.h
    Histogram.h)
    
add_executable(image ${SOURCES} ${HEADER})

#Find Opencv
find_package(OpenCV 3.2.0 REQUIRED)
if(OpenCV_FOUND)
    target_include_directories(image PUBLIC ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(image ${OpenCV_LIBS})
    message(${OpenCV_INCLUDE_DIRS})
else()
    message("Can not find Lib.")
endif()