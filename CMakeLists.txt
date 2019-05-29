cmake_minimum_required(VERSION 3.0.0)
project(image VERSION 0.1.0)

include(CTest)
enable_testing()

# make main project
set(SOURCES
    Blending.cpp
    ImageValue.cpp
    Histogram.cpp
    main.cpp)

set(HEADER
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