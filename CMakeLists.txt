cmake_minimum_required(VERSION 3.22.1)
set(CXX_STANDARD_REQUIRED 20)

set(MANGODB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/mangodb)
# message(${MANGODB_INCLUDE_DIR})

project("mangoDB")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${MANGDB_INCLUDE_DIR})
add_subdirectory(src)
add_subdirectory(tests)
