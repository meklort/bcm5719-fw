project(bcmflash)

# Import the CHECK_INCLUDE_FILES macros
include(CheckIncludeFiles)
CHECK_INCLUDE_FILES("endian.h" ENDIANNESS_CONFIG_HAVE_ENDIAN_H)
CHECK_INCLUDE_FILES("sys/endian.h" ENDIANNESS_CONFIG_HAVE_SYS_ENDIAN_H)
CHECK_INCLUDE_FILES("linux/ethtool.h" CONFIG_HAVE_LINUX_ETHTOOL_H)

add_definitions(-Wall -Werror)
set(SOURCES
    main.cpp
    nvm.cpp
    fileio.cpp

    bcmflash.h

    # Support files for initializing the firmware header
    create_header.c     create_header.h
    nvm_talos2.c
    nvm_blackbird.c
    nvm_kh08p.c
)

IF(CONFIG_HAVE_LINUX_ETHTOOL_H)
    LIST(APPEND SOURCES
        ethtool.c     ethtool.h
    )
ENDIF()

simulator_add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE NVRam VPD simulator OptParse)

format_target_sources(${PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)

IF(ENDIANNESS_CONFIG_HAVE_ENDIAN_H)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "-DENDIANNESS_CONFIG_HAVE_ENDIAN_H=1")
ENDIF()

IF(ENDIANNESS_CONFIG_HAVE_SYS_ENDIAN_H)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "-DENDIANNESS_CONFIG_HAVE_SYS_ENDIAN_H=1")
ENDIF()

IF(CONFIG_HAVE_LINUX_ETHTOOL_H)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "-DCONFIG_HAVE_LINUX_ETHTOOL_H=1")
ENDIF()
