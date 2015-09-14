project(mymathlib)

set(MyMathLib_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${MyMathLib_DIR})

set(MyMathLib_HEAD ${MyMathLib_DIR}/SamMathsMatrices.h
		   ${MyMathLib_DIR}/SamMathsVectors.h)

set(MyMathLib_SRC ${MyMathLib_DIR}/SamMathsMatrices.cpp
		  ${MyMathLib_DIR}/SamMathsVectors.cpp)

add_library(mymathlib STATIC ${MyMathLib_HEAD} ${MyMathLib_SRC})