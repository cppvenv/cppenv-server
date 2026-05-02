Users
=====

.. note:: This reference is a work in progress.

All user management endpoints require Builder role.

Roles
-----

- **Consumer** — search and download bundles. Read-only.
- **Builder** — Consumer + publish bundles, delete bundles, manage users.

Endpoints
---------

``GET /users``
~~~~~~~~~~~~~~

List all users.

``POST /users``
~~~~~~~~~~~~~~~

Create a new user.

``PUT /users/{id}``
~~~~~~~~~~~~~~~~~~~

Update a user (role, password).

``DELETE /users/{id}``
~~~~~~~~~~~~~~~~~~~~~~

Delete a user.
