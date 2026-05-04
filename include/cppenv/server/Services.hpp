#pragma once

/**
 * @file Services.hpp
 * @brief Convenience header — includes all service types.
 * @author Nikola Radovanovic
 *
 * Include this header to pull in every service class in one line.
 * Prefer including individual service headers in headers that only
 * need one type — include this only in translation units that use
 * the full set.
 */

#include <cppenv/server/services/Service.hpp>
#include <cppenv/server/services/BundleService.hpp>
