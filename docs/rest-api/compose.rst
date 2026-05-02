Compose
=======

.. note:: This reference is a work in progress.

Bundle composition allows the server to assemble a bundle from multiple
sources into a single artifact. Requires Builder role.

``POST /compose``
-----------------

Start a composition job. Returns a ``job_id``.

``GET /compose/{job_id}``
-------------------------

Poll the status of a running composition job.
