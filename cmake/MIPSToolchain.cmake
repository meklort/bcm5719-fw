

SET(CMAKE_SYSTEM_NAME Generic)

SET(CMAKE_C_COMPILER mips64-linux-gnu-gcc)
SET(CMAKE_CXX_COMPILER mips64-linux-gnu-gcc)

include (CMakeForceCompiler)
CMAKE_FORCE_C_COMPILER   (mips64-linux-gnu-gcc gcc)
CMAKE_FORCE_CXX_COMPILER (mips64-linux-gnu-gcc gcc)

set (CMAKE_C_FLAGS "-nostdlib -nodefaultlibs -fomit-frame-pointer -march=mips2 -mabi=32 -mfp32 -msoft-float -mno-mad -mno-check-zero-division ")
set (CMAKE_ASM_FLAGS "-nostdlib -nodefaultlibs -fomit-frame-pointer -march=mips2 -mabi=32 -mfp32 -msoft-float -mno-mad -mno-check-zero-division ")

add_definitions(
    -I${CMAKE_CURRENT_SOURCE_DIR}/include/mips/
)

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
