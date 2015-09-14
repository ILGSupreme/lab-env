#--------------------------------------------------------------------------
# grafiklabb project
#--------------------------------------------------------------------------

PROJECT(labb1)

SET(ENGINE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/code)

FILE(GLOB APP_HEAD ${ENGINE_DIR}/*.h)
FILE(GLOB APP_SOURCE ${ENGINE_DIR}/*.cc)

SET(ENGINE_FILES ${APP_HEAD} ${APP_SOURCE}) 
SOURCE_GROUP("labb1" FILES ${ENGINE_FILES})

ADD_EXECUTABLE(labb1 ${ENGINE_FILES})
TARGET_LINK_LIBRARIES(labb1 core render exts mymathlib Adon_Interface adonengine)
ADD_DEPENDENCIES(labb1 core render exts mymathlib Adon_Interface adonengine)