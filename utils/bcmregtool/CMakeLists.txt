project(bcmregtool)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam)

target_link_libraries(${PROJECT_NAME} PRIVATE simulator)
