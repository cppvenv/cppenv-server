Configuration
=============

.. note:: This reference is a work in progress.

cppenv-server is configured via a single YAML file.

.. code-block:: bash

   ./cppenv-server --config /etc/cppenv/server.yaml

.. code-block:: yaml

   database:
     backend: sqlite          # sqlite | postgres
     path: /var/lib/cppenv/cppenv.db

   storage:
     backend: local           # local | s3
     path: /var/lib/cppenv/bundles

   server:
     host: 0.0.0.0
     port: 8080

PostgreSQL backend
------------------

.. code-block:: yaml

   database:
     backend: postgres
     host: localhost
     port: 5432
     name: cppenv
     user: cppenv
     password: secret

S3-compatible storage
---------------------

.. code-block:: yaml

   storage:
     backend: s3
     bucket: my-cppenv-bundles
     endpoint: https://s3.amazonaws.com
