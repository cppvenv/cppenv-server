Bundles
=======

.. note:: This reference is a work in progress.

Bundle identifier
-----------------

Every bundle is uniquely identified by five path parameters:

.. list-table::
   :header-rows: 1
   :widths: 20 20 60

   * - Parameter
     - Example
     - Notes
   * - ``name``
     - ``zlib``
     - Exact match. No wildcards.
   * - ``version``
     - ``1.3.1``
     - Semantic version string.
   * - ``platform``
     - ``linux``, ``macos``, ``windows``
     - Opaque string — the server stores and matches it as-is.
   * - ``arch``
     - ``x86_64``, ``arm64``
     - Target architecture.
   * - ``compiler``
     - ``gcc13``, ``clang16``, ``msvc2022``
     - Compiler family + major version. Major version determines ABI.

Endpoints
---------

``GET /bundles``
~~~~~~~~~~~~~~~~

Search for bundles. All query parameters are optional.

.. code-block:: http

   GET /bundles?name=zlib&platform=linux&arch=x86_64&compiler=gcc13 HTTP/1.1

``GET /bundles/{name}/{version}/{platform}/{arch}/{compiler}``
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Retrieve metadata for a specific bundle.

``GET /bundles/{name}/{version}/{platform}/{arch}/{compiler}/download``
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Download the bundle tarball.

``POST /bundles``
~~~~~~~~~~~~~~~~~

Publish a new bundle. Requires Builder role.

``DELETE /bundles/{id}``
~~~~~~~~~~~~~~~~~~~~~~~~

Delete a bundle by its internal ID. Requires Builder role.
