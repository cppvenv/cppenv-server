#pragma once

/**
 * @file ServerException.hpp
 * @brief Base exception class for all cppenv-server exceptions.
 * @author Nikola Radovanovic
 *
 * Extends @c cppenv::Exception with HTTP-specific behaviour:
 * - @c httpStatus() maps the failure code to an HTTP status code.
 * - @c toJson()     produces a safe JSON error envelope for HTTP responses.
 *
 * The internal detail is never included in @c toJson() output — it goes
 * to the log only.
 */

#include <cppenv/exception/Exception.hpp>
#include <cppenv/json.hpp>

namespace cppenv::server {

/**
 * @brief Base class for all server-layer exceptions.
 *
 * Adds @c httpStatus() and @c toJson() on top of @c cppenv::Exception so
 * HTTP handlers can produce well-formed error responses without knowing
 * the concrete exception type.
 */
class ServerException : public cppenv::Exception {
public:
    /**
     * @brief Construct a server exception.
     * @param code           Failure category.
     * @param publicMessage  Caller-safe description — included in @c toJson().
     * @param internalDetail Full context for logging — never serialised.
     */
    ServerException(Code code, std::string publicMessage, std::string internalDetail)
        : Exception(code, std::move(publicMessage), std::move(internalDetail))
    {}

    /**
     * @brief Returns the HTTP status code corresponding to the failure category.
     *
     * Mapping:
     * - @c NotFound       → 404
     * - @c InvalidRequest → 400
     * - @c StorageError   → 500
     * - @c DatabaseError  → 500
     * - @c InternalError  → 500
     */
    int httpStatus() const {
        switch (code()) {
            case Code::NotFound:       return 404;
            case Code::InvalidRequest: return 400;
            case Code::StorageError:   return 500;
            case Code::DatabaseError:  return 500;
            case Code::InternalError:  return 500;
        }
        return 500;
    }

    /**
     * @brief Returns a JSON error envelope safe to send to callers.
     *
     * The envelope contains the HTTP status code and the public message only.
     * Internal detail is never included.
     *
     * @code{.json}
     * { "status": 404, "error": "Not Found", "message": "..." }
     * @endcode
     */
    cppenv::json_t toJson() const {
        return {
            {"status",  httpStatus()},
            {"error",   httpStatusText()},
            {"message", publicMessage()}
        };
    }

private:
    /** @brief Returns the standard HTTP reason phrase for the current status. */
    std::string httpStatusText() const {
        switch (code()) {
            case Code::NotFound:       return "Not Found";
            case Code::InvalidRequest: return "Bad Request";
            case Code::StorageError:   return "Internal Server Error";
            case Code::DatabaseError:  return "Internal Server Error";
            case Code::InternalError:  return "Internal Server Error";
        }
        return "Internal Server Error";
    }
};

} // namespace cppenv::server
