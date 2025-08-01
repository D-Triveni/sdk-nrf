/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP
// This file is generated from clusters-Structs.h.zapt

#pragma once

#include <app/data-model/DecodableList.h>
#include <app/data-model/List.h>
#include <app/data-model/Nullable.h>
#include <lib/core/DataModelTypes.h>
#include <lib/core/Optional.h>
#include <lib/core/TLV.h>
#include <lib/support/BitMask.h>

#include <clusters/shared/Structs.h>

#include <cstdint>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		namespace Binding
		{
			namespace Structs
			{
				namespace TargetStruct
				{
					enum class Fields : uint8_t {
						kNode = 1,
						kGroup = 2,
						kEndpoint = 3,
						kCluster = 4,
						kFabricIndex = 254,
					};

					struct Type {
					public:
						Optional<chip::NodeId> node;
						Optional<chip::GroupId> group;
						Optional<chip::EndpointId> endpoint;
						Optional<chip::ClusterId> cluster;
						chip::FabricIndex fabricIndex = static_cast<chip::FabricIndex>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);

						static constexpr bool kIsFabricScoped = true;

						auto GetFabricIndex() const { return fabricIndex; }

						void SetFabricIndex(chip::FabricIndex fabricIndex_)
						{
							fabricIndex = fabricIndex_;
						}

						CHIP_ERROR EncodeForWrite(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;
						CHIP_ERROR EncodeForRead(TLV::TLVWriter &aWriter, TLV::Tag aTag,
									 FabricIndex aAccessingFabricIndex) const;

					private:
						CHIP_ERROR
						DoEncode(TLV::TLVWriter &aWriter, TLV::Tag aTag,
							 const Optional<FabricIndex> &aAccessingFabricIndex) const;
					};

					using DecodableType = Type;

				} // namespace TargetStruct
			} // namespace Structs
		} // namespace Binding
	} // namespace Clusters
} // namespace app
} // namespace chip
