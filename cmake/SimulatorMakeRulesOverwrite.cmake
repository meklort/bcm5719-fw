list(APPEND CMAKE_CXX_SOURCE_FILE_EXTENSIONS c)

set(DOES_BUILD True)

# Simulator build
set(SIMULATOR True)

#Don't install the gtest libraries - we will link directly as needed.
SET(INSTALL_GTEST False CACHE BOOL "Disable GTest Install")
SET(INSTALL_GMOCK False CACHE BOOL "Disable GMock Install")
