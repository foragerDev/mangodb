include_directories(${PROJECT_SOURCE_DIR}/include/mangodb)

enable_testing()

add_executable(
  mangodb_tests
  test_database.cpp
)
target_link_libraries(
  mangodb_tests
  GTest::gtest_main
)
message(${CMAKE_SOURCE_DIR})
target_sources(mangodb_tests PRIVATE ${CMAKE_SOURCE_DIR}/src/database.cpp)

include(GoogleTest)
gtest_discover_tests(mangodb_tests)