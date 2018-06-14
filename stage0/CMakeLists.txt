
project(stage0)

add_executable(${PROJECT_NAME}
            init_hw.c
            main.c)

target_link_libraries(${PROJECT_NAME} NVRam MII)

IF(SIMULATOR)
    target_link_libraries(${PROJECT_NAME} simulator)
ELSE()
	target_compile_options(${PROJECT_NAME} PRIVATE -nodefaultlibs -nostartfiles)

ENDIF(SIMULATOR)