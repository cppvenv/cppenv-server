cppenv-server
=============

**Bundle server for the cppenv C++ package manager.**

cppenv-server is the shared artifact cache and bundle store for teams.
It exposes a REST API for publishing, searching, and downloading pre-built
C++ bundles, backed by either SQLite (single-node) or PostgreSQL (team).

.. grid:: 2
   :gutter: 3

   .. grid-item-card:: API Reference
      :link: api/index
      :link-type: doc

      C++ classes and types — generated from ``///`` Doxygen comments
      in the server source headers.

   .. grid-item-card:: REST API
      :link: rest-api/index
      :link-type: doc

      HTTP endpoints, request/response formats, authentication, and
      bundle query parameters.

   .. grid-item-card:: Deployment
      :link: deployment/index
      :link-type: doc

      Configuration, storage backends, logging, and self-hosting guide.

   .. grid-item-card:: Guides
      :link: guides/index
      :link-type: doc

      Getting started, publishing bundles, and team setup.

.. toctree::
   :hidden:
   :maxdepth: 2

   api/index
   rest-api/index
   deployment/index
   guides/index
