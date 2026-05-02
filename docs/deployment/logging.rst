Logging
=======

cppenv-server writes two log streams via spdlog:

- **Console** — human-readable format for interactive use and systemd journals.
- **File** — JSON format, 50 MB per file, 5 files retained.

The JSON format is intentionally plain so Fluent Bit (or any log shipper)
can forward it to any observability backend — Datadog, Loki, Elasticsearch,
CloudWatch — without requiring changes to the server binary.

There is no direct integration with any observability vendor. Output JSON,
let the log shipper handle the rest.
