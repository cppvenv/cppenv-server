Getting Started
===============

.. note:: This guide is a work in progress.

Prerequisites
-------------

- CMake 3.20 or newer
- A C++17-capable compiler
- Perl (required by OpenSSL's configure script)
- pkg-config

Building documentation requires additional tools:

- Python 3 with ``pip install -r docs/requirements-docs.txt``
- Graphviz (for class and call graphs) — ``brew install graphviz`` on macOS,
  ``apt install graphviz`` on Debian/Ubuntu

Building
--------

.. code-block:: bash

   git clone --recurse-submodules https://github.com/cppvenv/cppenv-server
   cd cppenv-server
   cmake -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
   cmake --build build

To skip the PostgreSQL client for a lightweight build:

.. code-block:: bash

   cmake -B build -DCPPENV_ENABLE_POSTGRES=OFF

Running
-------

.. code-block:: bash

   ./build/cppenv-server --config server.yaml
