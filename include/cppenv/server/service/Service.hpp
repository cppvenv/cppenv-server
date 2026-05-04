#pragma once

/**
 * @file Service.hpp
 * @brief Abstract base class for all service layer implementations.
 * @author Nikola Radovanovic
 *
 * All concrete services (e.g. @c BundleService, @c UserService) inherit from
 * @c Service.  The base carries no shared methods — domain operations differ
 * too much to factor up — but a common base makes dependency injection and
 * test mocking uniform across the handler layer.
 */

namespace cppenv::server {

/**
 * @brief Abstract base for all service implementations.
 *
 * Inherit from this class to participate in the service layer.
 * Concrete subclasses define their own operation methods; the handler
 * layer holds them via the concrete type or a domain-specific interface.
 */
class Service {
public:
    virtual ~Service() = default;

protected:
    /**
     * @brief Protected constructor — prevents direct instantiation.
     *
     * Only subclasses may construct.  There is no shared state to initialise;
     * the constructor exists solely to enforce this constraint.
     */
    Service() = default;
};

} // namespace cppenv::server
