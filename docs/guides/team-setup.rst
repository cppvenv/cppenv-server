Team Setup
==========

.. note:: This guide is a work in progress.

Setting up a shared cppenv-server for a team involves:

1. Deploying the server binary with a PostgreSQL backend.
2. Creating Builder accounts for CI pipelines that publish bundles.
3. Creating Consumer accounts (or a shared token) for developer machines.
4. Pointing each developer's ``cppenv.yaml`` at the server URL.
