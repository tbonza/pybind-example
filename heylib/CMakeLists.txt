# Example of including a library with pybind11 and skbuild

add_library(
	hey-lib #cmake-format: sort
	internal/greeting.h
	internal/greeting.cc
	hello.h
	hello.cc)

target_include_directories(
  hey-lib PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                 $<INSTALL_INTERFACE:include>)

if(HEY_BUILD_TESTS)

	find_package(GoogleTest REQUIRED)

	set(HEY_TEST_SRC_FILES
    internal/greeting_test.cc
    hello_test.cc)

  add_executable(hey_test ${HEY_TEST_SRC_FILES})
  target_link_libraries(hey_test PRIVATE
    gtest_main
    hey-lib
  )

  # Defines `gtest_discover_tests()`. 
  include(GoogleTest)
  gtest_discover_tests(hey_test)

endif(HEY_BUILD_TESTS)
