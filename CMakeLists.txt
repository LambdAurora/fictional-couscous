cmake_minimum_required(VERSION 3.12)
project(fictional_couscous)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(utils/CompileUtility)
include(utils/InstallUtility)
include(utils/VersionUtility)

set(CMAKE_CXX_STANDARD 17)

# Options
option(FICTIONAL_COUSCOUS_INSTALL "Generate installation target" ON)

# Version
set(FICTIONAL_COUSCOUS_VERSION_MAJOR 1)
set(FICTIONAL_COUSCOUS_VERSION_MINOR 0)
set(FICTIONAL_COUSCOUS_VERSION_PATCH 0)
set(FICTIONAL_COUSCOUS_VERSION_TYPE "indev")

# Generate compile flags.
generate_flags(FICTIONAL_COUSCOUS_COMPILE_FLAGS "native" 2 true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${FICTIONAL_COUSCOUS_COMPILE_FLAGS}")

# Find libraries.
find_package(lambdacommon REQUIRED)

include_directories(${LAMBDACOMMON_INCLUDE_DIRS})

# All files:
# There is the C++ header files:
set(HEADER_WORLD src/world/world.h)
set(HEADER_FILES ${HEADER_WORLD})
# There is the C++ source files:
set(SOURCE_FILES src/main.cpp)

# Now build the executable.
add_executable(fictional_couscous ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(fictional_couscous AperLambda::lambdacommon)

# Generate the version header and include it.
generate_version_header("FICTIONAL_COUSCOUS" "fictional_couscous" ${FICTIONAL_COUSCOUS_VERSION_MAJOR} ${FICTIONAL_COUSCOUS_VERSION_MINOR} ${FICTIONAL_COUSCOUS_VERSION_PATCH} "${FICTIONAL_COUSCOUS_VERSION_TYPE}")
include_directories(fictional_couscous PUBLIC ${CMAKE_BINARY_DIR}/exports)

# Install if the option is on.
