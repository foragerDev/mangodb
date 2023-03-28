include_directories(${PROJECT_SOURCE_DIR}/include/mangodb)

enable_testing()
SET(TEST_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/)
message(TEST_SOURCE_DIR)

file(GLOB SOURCES ${TEST_SOURCE_DIR}/*.cpp)
add_executable(
  mangodb_tests
  test_database.cpp
)
target_link_libraries(
  mangodb_tests
  GTest::gtest_main
)
message(${CMAKE_SOURCE_DIR})
target_sources(mangodb_tests PRIVATE ${SOURCES})

include(GoogleTest)
gtest_discover_tests(mangodb_tests)
