project(bcmregtool)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
)

simulator_add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam VPD MII)
target_link_libraries(${PROJECT_NAME} PRIVATE simulator OptParse)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION .)
