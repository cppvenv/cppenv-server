include_guard(GLOBAL)

include(${CMAKE_CURRENT_LIST_DIR}/../cppenv-core/cmake/Dependencies.cmake)

# ---------------------------------------------------------------------------
# cpp-httplib — single-header HTTP/HTTPS server and client.
# ---------------------------------------------------------------------------
build_dep_cmake(
    NAME        cpp-httplib
    VERSION     0.43.2
    PKG_NAME    httplib
    HASH        SHA256=c2aba52598df7b2169a0510497fdd95c843421040b0997db82fefa22f9d50a5b
    URL         https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.43.2.tar.gz
    BUILD_OPTS
        -DHTTPLIB_REQUIRE_OPENSSL=ON
)

# ---------------------------------------------------------------------------
# PostgreSQL client — required for the postgres backend.
# Disable with -DCPPENV_ENABLE_POSTGRES=OFF for lightweight dev/CI builds
# that only need the SQLite backend.
# ---------------------------------------------------------------------------
option(CPPENV_ENABLE_POSTGRES "Build and install the PostgreSQL client (libpq)" ON)

if(CPPENV_ENABLE_POSTGRES)
    build_postgres_cli(
        NAME        libpq
        VERSION     15.4
        PKG_NAME    libpq
        HASH        SHA256=0e11eee723dd7e59a634052bc1bfc9be605e55c1cca3f66e9fc25d3a394fb030
        URL         https://ftp.postgresql.org/pub/source/v15.4/postgresql-15.4.tar.gz
        BUILD_OPTS
            --with-openssl
            --with-zlib
            --without-lz4
            --without-zstd
            --without-readline
    )
endif()