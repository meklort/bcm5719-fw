project(bcmflash)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
    nvm.cpp
    fileio.cpp

    bcmflash.h

    # Support files for initializing the firmware header
    create_header.cpp     create_header.h
    nvm_talos2.c
    nvm_blackbird.c
    nvm_kh08p.c
)

IF(CONFIG_HAVE_LINUX_ETHTOOL_H)
    LIST(APPEND SOURCES
        ethtool.c     ethtool.h
    )
ENDIF()

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam VPD simulator OptParse)
target_compile_options(${PROJECT_NAME} PRIVATE -DCXX_SIMULATOR)

format_target_sources(${PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)

ADD_ENDIANNESS_DEFINES(${PROJECT_NAME})
ADD_ETHTOOL_DEFINES(${PROJECT_NAME})
