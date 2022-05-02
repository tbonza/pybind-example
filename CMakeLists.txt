cmake_minimum_required(VERSION 3.15...3.22)

project(scikit_build_example VERSION "0.0.1")

option(HEY_BUILD_TESTS "Build Hey's unit tests" ON)
option(HEY_BUILD_PYTHON "Build Hey's python package" ON)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if(HEY_BUILD_TESTS)
	# Enable testing in this directory so we can do a top-level `make test`. 
  # This also includes the BUILD_TESTING option, which is on by default.
  include(CTest)

  enable_testing()

endif(HEY_BUILD_TESTS)

add_subdirectory(heylib)

if(HEY_BUILD_PYTHON)

if(SKBUILD)
  # Scikit-Build does not add your site-packages to the search path
  # automatically, so we need to add it _or_ the pybind11 specific directory
  # here.
  execute_process(
    COMMAND "${PYTHON_EXECUTABLE}" -c
            "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE _tmp_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
  list(APPEND CMAKE_PREFIX_PATH "${_tmp_dir}")
endif()


# Now we can find pybind11
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(_core MODULE src/main.cpp)

target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS _core DESTINATION .)

endif(HEY_BUILD_PYTHON)
