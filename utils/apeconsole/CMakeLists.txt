project(apeconsole)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
)

simulator_add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE APE )
target_link_libraries(${PROJECT_NAME} PRIVATE simulator OptParse elfio)

format_target_sources(${PROJECT_NAME})

ADD_ENDIANNESS_DEFINES(${PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)
