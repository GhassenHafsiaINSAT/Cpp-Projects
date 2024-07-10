cmake_minimum_required(VERSION 3.29)
project(Perceptron)

# default build is for release 
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# disallow in-source builds
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# enable optimization for release
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# For STL Libraries 
set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED On)
set(CXX_EXTENSIONS On)

# if it is release build enable LTO (link time optimisation) 
if(CMAKE_BUILD_TYPE EQUAL  Release)

    include(CheckIPOSupported)
    check_ipo_supported(RESULT supported OUTPUT error)

    if( supported )
        message(STATUS "IPO / LTO enabled")

        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(STATUS "IPO / LTO not supported: <${error}>")
    endif()

endif()