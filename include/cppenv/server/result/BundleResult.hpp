#pragma once

/**
 * @file BundleResult.hpp
 * @brief Result object returned by bundle service operations.
 * @author Nikola Radovanovic
 *
 * Carries the data the HTTP handler needs to respond to bundle queries.
 * The handler calls @c toJson() and forwards the output verbatim — no
 * field-level knowledge of bundles is required above the service layer.
 */

#include "Result.hpp"

#include <string>

namespace cppenv::server {

/**
 * @brief Holds metadata for a single bundle returned by the service layer.
 *
 * Immutable after construction.  All five bundle-identity fields are
 * mandatory — the bundle identifier has no optional components.
 */
class BundleResult : public Result {
public:
    /**
     * @brief Construct a bundle result.
     * @param name      Bundle name (e.g. @c "zlib").
     * @param version   Semantic version string (e.g. @c "1.3.1").
     * @param platform  Target platform (e.g. @c "linux").
     * @param arch      Target architecture (e.g. @c "x86_64").
     * @param compiler  Compiler family + major version (e.g. @c "gcc13").
     * @param downloadUrl  Pre-signed or local URL the client fetches to get the bundle archive.
     */
    BundleResult(std::string name,
                 std::string version,
                 std::string platform,
                 std::string arch,
                 std::string compiler,
                 std::string downloadUrl)
        : m_name{std::move(name)}
        , m_version{std::move(version)}
        , m_platform{std::move(platform)}
        , m_arch{std::move(arch)}
        , m_compiler{std::move(compiler)}
        , m_downloadUrl{std::move(downloadUrl)}
    {}

    /** @brief Bundle name. */
    const std::string& name()        const { return m_name; }

    /** @brief Semantic version string. */
    const std::string& version()     const { return m_version; }

    /** @brief Target platform string. */
    const std::string& platform()    const { return m_platform; }

    /** @brief Target architecture string. */
    const std::string& arch()        const { return m_arch; }

    /** @brief Compiler family + major version string. */
    const std::string& compiler()    const { return m_compiler; }

    /** @brief URL the client uses to download the bundle archive. */
    const std::string& downloadUrl() const { return m_downloadUrl; }

    /**
     * @brief Serialise to a JSON object.
     *
     * @code{.json}
     * {
     *   "name":        "zlib",
     *   "version":     "1.3.1",
     *   "platform":    "linux",
     *   "arch":        "x86_64",
     *   "compiler":    "gcc13",
     *   "downloadUrl": "https://..."
     * }
     * @endcode
     */
    cppenv::json_t toJson() const override {
        return {
            {"name",        m_name},
            {"version",     m_version},
            {"platform",    m_platform},
            {"arch",        m_arch},
            {"compiler",    m_compiler},
            {"downloadUrl", m_downloadUrl}
        };
    }

private:
    const std::string m_name;        /**< Bundle name. */
    const std::string m_version;     /**< Semantic version string. */
    const std::string m_platform;    /**< Target platform string. */
    const std::string m_arch;        /**< Target architecture string. */
    const std::string m_compiler;    /**< Compiler family + major version. */
    const std::string m_downloadUrl; /**< URL for the bundle archive download. */
};

} // namespace cppenv::server
