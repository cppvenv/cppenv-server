Health
======

``GET /health``
---------------

Returns ``200 OK`` if the server is running. No authentication required.
Suitable for load balancer health checks.

.. code-block:: http

   GET /health HTTP/1.1

.. code-block:: json

   { "status": "ok" }
