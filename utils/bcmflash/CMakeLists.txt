project(bcmflash)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
)

simulator_add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam)
target_link_libraries(${PROJECT_NAME} PRIVATE VPD)

target_link_libraries(${PROJECT_NAME} PRIVATE simulator)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION .)
