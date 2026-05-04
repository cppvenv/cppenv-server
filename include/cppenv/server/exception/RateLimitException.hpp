#pragma once

/**
 * @file RateLimitException.hpp
 * @brief Exception thrown when a caller exceeds the request rate limit.
 * @author Nikola Radovanovic
 */

#include "ServerException.hpp"

namespace cppenv::server {

/**
 * @brief Thrown when a caller exceeds the allowed request rate.
 *
 * Maps to HTTP 429 Too Many Requests.
 */
class RateLimitException : public ServerException {
public:
    /**
     * @brief Construct a rate-limit exception.
     * @param publicMessage  Caller-safe description.
     * @param internalDetail Full context for logging.
     */
    RateLimitException(std::string publicMessage, std::string internalDetail)
        : ServerException(Code::InvalidRequest, std::move(publicMessage), std::move(internalDetail))
    {}

    /** @brief Returns 429 Too Many Requests. */
    int httpStatus() const { return 429; }
};

} // namespace cppenv::server
