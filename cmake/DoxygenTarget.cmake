#[=======================================================================[.rst:
DoxygenTarget
-------------

Adds an optional ``docs`` build target that runs Doxygen and Sphinx to
produce HTML documentation for ``cppenv-server``.

The pipeline mirrors the one in ``cppenv-core``:

1. Doxygen reads ``include/`` and ``src/``, writes XML to
   ``<build>/doxygen/xml/``.  ``cppenv-core/`` is excluded — its API
   is documented separately and linked via intersphinx.
2. Sphinx reads ``docs/`` RST sources and the Doxygen XML via Breathe.
3. Furo theme produces the final HTML site in ``<build>/sphinx/html/``.

.. note::
   The ``docs`` target is off by default.  Enable with ``-DBUILD_DOCS=ON``.

.. code-block:: bash

   pip install -r docs/requirements-docs.txt
   cmake -B build -DBUILD_DOCS=ON
   cmake --build build --target docs
   open build/sphinx/html/index.html

#]=======================================================================]

include_guard(GLOBAL)

option(BUILD_DOCS "Build API and narrative documentation (Doxygen + Sphinx)" OFF)

if(NOT BUILD_DOCS)
    return()
endif()

find_package(Doxygen REQUIRED OPTIONAL_COMPONENTS dot)

find_program(SPHINX_BUILD_EXECUTABLE
    NAMES sphinx-build
    DOC   "Path to the sphinx-build executable"
)
if(NOT SPHINX_BUILD_EXECUTABLE)
    message(FATAL_ERROR
        "[cppenv] sphinx-build not found. "
        "Run: pip install -r docs/requirements-docs.txt"
    )
endif()

set(DOXYGEN_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/doxygen")
set(SPHINX_CONF_DIR    "${CMAKE_CURRENT_BINARY_DIR}/docs")
set(SPHINX_OUTPUT_DIR  "${CMAKE_CURRENT_BINARY_DIR}/sphinx/html")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
    @ONLY
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/docs/conf.py.in"
    "${SPHINX_CONF_DIR}/conf.py"
    @ONLY
)

add_custom_target(docs
    COMMAND
        ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
    COMMAND
        ${SPHINX_BUILD_EXECUTABLE}
            -b html
            -c "${SPHINX_CONF_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}/docs"
            "${SPHINX_OUTPUT_DIR}"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    COMMENT "Building documentation: Doxygen → XML → Breathe → Sphinx + Furo"
    VERBATIM
)

message(STATUS "[cppenv] BUILD_DOCS=ON — 'docs' target enabled")
message(STATUS "[cppenv]   Output: ${SPHINX_OUTPUT_DIR}/index.html")
