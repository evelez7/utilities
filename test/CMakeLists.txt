project(util_test)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(util_test strings_test.cpp)
target_link_libraries(util_test GTest::gtest_main)
target_link_libraries(util_test util)

include(GoogleTest)
gtest_discover_tests(util_test)

