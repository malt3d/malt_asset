//
// Created by fatih on 5/16/17.
//

#pragma once

#include <memory>
#include <cstdint>
#include <string>
#include <malt/engine_defs.hpp>
#include <malt_asset/assets_def.hpp>

namespace malt
{
    namespace asset
    {
        template <class T>
        using asset_ptr = std::shared_ptr<T>;
    }

    namespace impl
    {
        template <class AssetT>
        struct asset_adapter
        {
            static asset::asset_ptr<AssetT> load(const char* path) MALT_WEAK_SYMBOL;
        };
    }

    namespace asset
    {
        template <class AssetT>
        asset_ptr<AssetT> load(path_type path)
        {
            return impl::asset_adapter<AssetT>::load(path);
        }

        template <class AssetT>
        auto load(const std::string& path)
        {
            return load<AssetT>(path.c_str());
        }
    }
}
