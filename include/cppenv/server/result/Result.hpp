#pragma once

/**
 * @file Result.hpp
 * @brief Base class for all service layer result objects.
 * @author Nikola Radovanovic
 *
 * All values returned from @c IService methods inherit from @c Result.
 * The @c toJson() contract ensures every result can be serialised to a
 * JSON HTTP response by the handler layer without knowing the concrete type.
 */

#include <cppenv/json.hpp>

namespace cppenv::server {

/**
 * @brief Abstract base for all service result types.
 *
 * Enforces the @c toJson() contract so HTTP handlers can serialise any
 * result uniformly via @c send_ok(res, result).
 */
class Result {
public:
    virtual ~Result() = default;

    /**
     * @brief Serialise the result to a JSON value.
     * @return A @c json_t object safe to include in an HTTP response body.
     */
    virtual cppenv::json_t toJson() const = 0;
};

} // namespace cppenv::server
