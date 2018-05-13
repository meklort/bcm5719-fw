
project(MII)

add_library(${PROJECT_NAME} STATIC
			mii.c)

target_include_directories(${PROJECT_NAME} PUBLIC ../../include)
target_include_directories(${PROJECT_NAME} PUBLIC include)

IF(SIMULATOR)
    target_link_libraries(${PROJECT_NAME} PRIVATE simulator)
ENDIF(SIMULATOR)