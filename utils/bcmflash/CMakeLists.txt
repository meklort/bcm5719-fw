project(bcmflash)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
    nvm.cpp
    fileio.cpp

    bcmflash.h
    ethtool.c     ethtool.h

    # Support files for initializing the firmware header
    create_header.c     create_header.h
    nvm_talos2.c
    nvm_blackbird.c
    nvm_kh08p.c
)

simulator_add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam VPD simulator OptParse)

format_target_sources(${PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)
