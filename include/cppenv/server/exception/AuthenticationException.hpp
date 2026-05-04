#pragma once

/**
 * @file AuthenticationException.hpp
 * @brief Exception thrown when a request cannot be authenticated.
 * @author Nikola Radovanovic
 */

#include "ServerException.hpp"

namespace cppenv::server {

/**
 * @brief Thrown when authentication fails (missing or invalid credentials).
 *
 * Maps to HTTP 401. Overrides @c httpStatus() and @c httpStatusText() so
 * the base @c toJson() produces the correct status automatically.
 */
class AuthenticationException : public ServerException {
public:
    /**
     * @brief Construct an authentication exception.
     * @param publicMessage  Caller-safe description.
     * @param internalDetail Full context for logging.
     */
    AuthenticationException(std::string publicMessage, std::string internalDetail)
        : ServerException(Code::InvalidRequest, std::move(publicMessage), std::move(internalDetail))
    {}

    /** @brief Returns 401 Unauthorized. */
    int httpStatus() const { return 401; }
};

} // namespace cppenv::server
