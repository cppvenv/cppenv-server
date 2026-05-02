Storage Backends
================

.. note:: This reference is a work in progress.

Local filesystem
----------------

The default backend. Bundles are stored as files under ``storage.path``.
Suitable for single-node deployments.

S3-compatible
-------------

Supports AWS S3, MinIO, and Backblaze B2. Credentials are read from
standard ``AWS_ACCESS_KEY_ID`` and ``AWS_SECRET_ACCESS_KEY`` environment
variables.
