#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "heylib/hello.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: scikit_build_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

	py::class_<hey::Hey>(m, "Hey", R"pbdoc(
		Example of integrating a third-party C++ lib with Pybind11
		)pbdoc")
		.def(py::init<int, std::string&>())
		.def_readwrite("count", &hey::Hey::count)
		.def_readwrite("greeting", &hey::Hey::greeting);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
