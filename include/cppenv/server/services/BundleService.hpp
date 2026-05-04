#pragma once

/**
 * @file BundleService.hpp
 * @brief Service responsible for all bundle operations.
 * @author Nikola Radovanovic
 *
 * @c BundleService is the single entry point for bundle-related business
 * logic.  Handlers call its methods and receive typed @c Result objects or
 * catch @c ServerException subclasses — no storage or database details leak
 * past this layer.
 */

#include "Service.hpp"

#include <cppenv/server/requests/BundleId.hpp>
#include <cppenv/server/results/BundleResult.hpp>

namespace cppenv::server {

/**
 * @brief Handles bundle lookup, download, publish, and deletion.
 *
 * Depends on @c Repository for metadata persistence and @c Storage for
 * the bundle archive. Both are injected at construction so the service
 * is testable without a real database or filesystem.
 *
 * All methods throw @c ServerException subclasses on failure — callers
 * should not catch lower-level exceptions.
 */
class BundleService : public Service {
public:
    virtual ~BundleService() = default;

    /**
     * @brief Return metadata for a bundle.
     *
     * Maps to @c GET /bundles/{...}/manifest.
     *
     * @param id  The bundle to look up.
     * @return    Metadata for the requested bundle.
     * @throws cppenv::server::NotFoundException if no matching bundle exists.
     */
    virtual BundleResult get(const BundleId& id) = 0;

    /**
     * @brief Stream the bundle archive to the caller.
     *
     * Maps to @c GET /bundles/{...}/download.  The storage backend (local,
     * S3, etc.) is hidden from the caller — bytes always flow through the
     * server so the client never needs to know where the archive lives.
     *
     * @param id  The bundle to download.
     * @return    A @c BundleResult populated with transfer metadata.
     * @throws cppenv::server::NotFoundException if no matching bundle exists.
     */
    virtual BundleResult download(const BundleId& id) = 0;

    /**
     * @brief Publish a new bundle to the store.
     *
     * Maps to @c POST /bundles.  Requires Builder role.
     *
     * @param id  Identity of the bundle being published.
     * @return    The stored bundle as confirmation.
     * @throws cppenv::server::InvalidRequestException if the bundle already exists.
     */
    virtual BundleResult publish(const BundleId& id) = 0;

    /**
     * @brief Remove a bundle from the store.
     *
     * Maps to @c DELETE /bundles/{...}.  Requires Builder role.
     *
     * @param id  The bundle to delete.
     * @throws cppenv::server::NotFoundException if no matching bundle exists.
     */
    virtual void remove(const BundleId& id) = 0;
};

} // namespace cppenv::server
