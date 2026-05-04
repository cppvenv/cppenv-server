#pragma once

/**
 * @file AuthorizationException.hpp
 * @brief Exception thrown when a request is authenticated but not authorised.
 * @author Nikola Radovanovic
 */

#include "ServerException.hpp"

namespace cppenv::server {

/**
 * @brief Thrown when an authenticated user lacks the required role.
 *
 * Maps to HTTP 403. Distinct from @c AuthenticationException (401) —
 * the caller is known but does not have permission for the requested action.
 */
class AuthorizationException : public ServerException {
public:
    /**
     * @brief Construct an authorisation exception.
     * @param publicMessage  Caller-safe description.
     * @param internalDetail Full context for logging.
     */
    AuthorizationException(std::string publicMessage, std::string internalDetail)
        : ServerException(Code::InvalidRequest, std::move(publicMessage), std::move(internalDetail))
    {}

    /** @brief Returns 403 Forbidden. */
    int httpStatus() const { return 403; }
};

} // namespace cppenv::server
