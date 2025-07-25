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
// This file is generated from clusters-Attributes.h.zapt

#pragma once

#include <app/ConcreteAttributePath.h>
#include <app/data-model/DecodableList.h>
#include <app/data-model/List.h>
#include <app/data-model/Nullable.h>
#include <app/util/basic-types.h>
#include <lib/core/TLV.h>
#include <lib/support/BitMask.h>

#include <clusters/shared/Attributes.h>
#include <clusters/shared/Enums.h>
#include <clusters/shared/Structs.h>

#include <clusters/OperationalCredentials/AttributeIds.h>
#include <clusters/OperationalCredentials/ClusterId.h>
#include <clusters/OperationalCredentials/Enums.h>
#include <clusters/OperationalCredentials/Structs.h>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		namespace OperationalCredentials
		{
			namespace Attributes
			{

				namespace NOCs
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::List<
							const chip::app::Clusters::OperationalCredentials::Structs::
								NOCStruct::Type>;
						using DecodableType = chip::app::DataModel::DecodableList<
							chip::app::Clusters::OperationalCredentials::Structs::
								NOCStruct::DecodableType>;
						using DecodableArgType = const chip::app::DataModel::DecodableList<
							chip::app::Clusters::OperationalCredentials::Structs::
								NOCStruct::DecodableType> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::NOCs::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace NOCs
				namespace Fabrics
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::List<
							const chip::app::Clusters::OperationalCredentials::Structs::
								FabricDescriptorStruct::Type>;
						using DecodableType = chip::app::DataModel::DecodableList<
							chip::app::Clusters::OperationalCredentials::Structs::
								FabricDescriptorStruct::DecodableType>;
						using DecodableArgType = const chip::app::DataModel::DecodableList<
							chip::app::Clusters::OperationalCredentials::Structs::
								FabricDescriptorStruct::DecodableType> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::Fabrics::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace Fabrics
				namespace SupportedFabrics
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::SupportedFabrics::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace SupportedFabrics
				namespace CommissionedFabrics
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::CommissionedFabrics::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace CommissionedFabrics
				namespace TrustedRootCertificates
				{
					struct TypeInfo {
						using Type = chip::app::DataModel::List<const chip::ByteSpan>;
						using DecodableType =
							chip::app::DataModel::DecodableList<chip::ByteSpan>;
						using DecodableArgType =
							const chip::app::DataModel::DecodableList<chip::ByteSpan> &;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::TrustedRootCertificates::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace TrustedRootCertificates
				namespace CurrentFabricIndex
				{
					struct TypeInfo {
						using Type = uint8_t;
						using DecodableType = uint8_t;
						using DecodableArgType = uint8_t;

						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
						static constexpr AttributeId GetAttributeId()
						{
							return Attributes::CurrentFabricIndex::Id;
						}
						static constexpr bool MustUseTimedWrite() { return false; }
					};
				} // namespace CurrentFabricIndex
				namespace GeneratedCommandList
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::GeneratedCommandList::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
					};
				} // namespace GeneratedCommandList
				namespace AcceptedCommandList
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::AcceptedCommandList::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
					};
				} // namespace AcceptedCommandList
				namespace AttributeList
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::AttributeList::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
					};
				} // namespace AttributeList
				namespace FeatureMap
				{
					struct TypeInfo : public Clusters::Globals::Attributes::FeatureMap::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
					};
				} // namespace FeatureMap
				namespace ClusterRevision
				{
					struct TypeInfo
						: public Clusters::Globals::Attributes::ClusterRevision::TypeInfo {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}
					};
				} // namespace ClusterRevision

				struct TypeInfo {
					struct DecodableType {
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::OperationalCredentials::Id;
						}

						CHIP_ERROR Decode(TLV::TLVReader &reader,
								  const ConcreteAttributePath &path);

						Attributes::NOCs::TypeInfo::DecodableType NOCs;
						Attributes::Fabrics::TypeInfo::DecodableType fabrics;
						Attributes::SupportedFabrics::TypeInfo::DecodableType supportedFabrics =
							static_cast<uint8_t>(0);
						Attributes::CommissionedFabrics::TypeInfo::DecodableType
							commissionedFabrics = static_cast<uint8_t>(0);
						Attributes::TrustedRootCertificates::TypeInfo::DecodableType
							trustedRootCertificates;
						Attributes::CurrentFabricIndex::TypeInfo::DecodableType
							currentFabricIndex = static_cast<uint8_t>(0);
						Attributes::GeneratedCommandList::TypeInfo::DecodableType
							generatedCommandList;
						Attributes::AcceptedCommandList::TypeInfo::DecodableType
							acceptedCommandList;
						Attributes::AttributeList::TypeInfo::DecodableType attributeList;
						Attributes::FeatureMap::TypeInfo::DecodableType featureMap =
							static_cast<uint32_t>(0);
						Attributes::ClusterRevision::TypeInfo::DecodableType clusterRevision =
							static_cast<uint16_t>(0);
					};
				};
			} // namespace Attributes
		} // namespace OperationalCredentials
	} // namespace Clusters
} // namespace app
} // namespace chip
