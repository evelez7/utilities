project(util_test)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(util_test.exe strings_test.cpp files_test.cpp)
target_link_libraries(util_test.exe GTest::gtest_main)
target_link_libraries(util_test.exe util)

include(GoogleTest)
gtest_discover_tests(util_test.exe)

