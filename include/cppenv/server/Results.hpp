#pragma once

/**
 * @file Results.hpp
 * @brief Convenience header — includes all service result types.
 * @author Nikola Radovanovic
 *
 * Include this header to pull in every result class in one line.
 * Prefer including individual result headers in headers that only
 * need one type — include this only in translation units that use
 * the full set.
 */

#include <cppenv/server/result/Result.hpp>
#include <cppenv/server/result/BundleResult.hpp>
