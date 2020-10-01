project(bcmflash)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
    nvm.cpp
    fileio.cpp

    bcmflash.h
)

simulator_add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam VPD simulator OptParse)

format_target_sources(${PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)
