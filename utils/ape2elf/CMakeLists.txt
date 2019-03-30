project(ape2elf)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
)

include_directories(elfio)

simulator_add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam VPD simulator OptParse Compress elfio)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION .)
