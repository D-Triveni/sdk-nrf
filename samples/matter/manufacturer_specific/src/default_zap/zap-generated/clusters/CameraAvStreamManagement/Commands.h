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
// This file is generated from clusters-Commands.h.zapt

#pragma once

#include <app/data-model/DecodableList.h>
#include <app/data-model/Encode.h>
#include <app/data-model/List.h>
#include <app/data-model/NullObject.h>
#include <app/data-model/Nullable.h>
#include <lib/core/DataModelTypes.h>
#include <lib/core/Optional.h>
#include <lib/core/TLV.h>
#include <lib/support/BitMask.h>

#include <clusters/shared/Enums.h>
#include <clusters/shared/Structs.h>

#include <clusters/CameraAvStreamManagement/ClusterId.h>
#include <clusters/CameraAvStreamManagement/CommandIds.h>
#include <clusters/CameraAvStreamManagement/Enums.h>
#include <clusters/CameraAvStreamManagement/Structs.h>

#include <cstdint>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		namespace CameraAvStreamManagement
		{
			namespace Commands
			{
				// Forward-declarations so we can reference these later.

				namespace AudioStreamAllocate
				{
					struct Type;
					struct DecodableType;
				} // namespace AudioStreamAllocate

				namespace AudioStreamAllocateResponse
				{
					struct Type;
					struct DecodableType;
				} // namespace AudioStreamAllocateResponse

				namespace AudioStreamDeallocate
				{
					struct Type;
					struct DecodableType;
				} // namespace AudioStreamDeallocate

				namespace VideoStreamAllocate
				{
					struct Type;
					struct DecodableType;
				} // namespace VideoStreamAllocate

				namespace VideoStreamAllocateResponse
				{
					struct Type;
					struct DecodableType;
				} // namespace VideoStreamAllocateResponse

				namespace VideoStreamModify
				{
					struct Type;
					struct DecodableType;
				} // namespace VideoStreamModify

				namespace VideoStreamDeallocate
				{
					struct Type;
					struct DecodableType;
				} // namespace VideoStreamDeallocate

				namespace SnapshotStreamAllocate
				{
					struct Type;
					struct DecodableType;
				} // namespace SnapshotStreamAllocate

				namespace SnapshotStreamAllocateResponse
				{
					struct Type;
					struct DecodableType;
				} // namespace SnapshotStreamAllocateResponse

				namespace SnapshotStreamModify
				{
					struct Type;
					struct DecodableType;
				} // namespace SnapshotStreamModify

				namespace SnapshotStreamDeallocate
				{
					struct Type;
					struct DecodableType;
				} // namespace SnapshotStreamDeallocate

				namespace SetStreamPriorities
				{
					struct Type;
					struct DecodableType;
				} // namespace SetStreamPriorities

				namespace CaptureSnapshot
				{
					struct Type;
					struct DecodableType;
				} // namespace CaptureSnapshot

				namespace CaptureSnapshotResponse
				{
					struct Type;
					struct DecodableType;
				} // namespace CaptureSnapshotResponse

			} // namespace Commands

			namespace Commands
			{
				namespace AudioStreamAllocate
				{
					enum class Fields : uint8_t {
						kStreamUsage = 0,
						kAudioCodec = 1,
						kChannelCount = 2,
						kSampleRate = 3,
						kBitRate = 4,
						kBitDepth = 5,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::AudioStreamAllocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						Globals::StreamUsageEnum streamUsage =
							static_cast<Globals::StreamUsageEnum>(0);
						AudioCodecEnum audioCodec = static_cast<AudioCodecEnum>(0);
						uint8_t channelCount = static_cast<uint8_t>(0);
						uint32_t sampleRate = static_cast<uint32_t>(0);
						uint32_t bitRate = static_cast<uint32_t>(0);
						uint8_t bitDepth = static_cast<uint8_t>(0);

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = Clusters::CameraAvStreamManagement::Commands::
							AudioStreamAllocateResponse::DecodableType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::AudioStreamAllocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						Globals::StreamUsageEnum streamUsage =
							static_cast<Globals::StreamUsageEnum>(0);
						AudioCodecEnum audioCodec = static_cast<AudioCodecEnum>(0);
						uint8_t channelCount = static_cast<uint8_t>(0);
						uint32_t sampleRate = static_cast<uint32_t>(0);
						uint32_t bitRate = static_cast<uint32_t>(0);
						uint8_t bitDepth = static_cast<uint8_t>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace AudioStreamAllocate
				namespace AudioStreamAllocateResponse
				{
					enum class Fields : uint8_t {
						kAudioStreamID = 0,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::AudioStreamAllocateResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t audioStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Encode(DataModel::FabricAwareTLVWriter &aWriter,
								  TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::AudioStreamAllocateResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t audioStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace AudioStreamAllocateResponse
				namespace AudioStreamDeallocate
				{
					enum class Fields : uint8_t {
						kAudioStreamID = 0,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::AudioStreamDeallocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t audioStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::AudioStreamDeallocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						uint16_t audioStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace AudioStreamDeallocate
				namespace VideoStreamAllocate
				{
					enum class Fields : uint8_t {
						kStreamUsage = 0,
						kVideoCodec = 1,
						kMinFrameRate = 2,
						kMaxFrameRate = 3,
						kMinResolution = 4,
						kMaxResolution = 5,
						kMinBitRate = 6,
						kMaxBitRate = 7,
						kMinKeyFrameInterval = 8,
						kMaxKeyFrameInterval = 9,
						kWatermarkEnabled = 10,
						kOSDEnabled = 11,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamAllocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						Globals::StreamUsageEnum streamUsage =
							static_cast<Globals::StreamUsageEnum>(0);
						VideoCodecEnum videoCodec = static_cast<VideoCodecEnum>(0);
						uint16_t minFrameRate = static_cast<uint16_t>(0);
						uint16_t maxFrameRate = static_cast<uint16_t>(0);
						Structs::VideoResolutionStruct::Type minResolution;
						Structs::VideoResolutionStruct::Type maxResolution;
						uint32_t minBitRate = static_cast<uint32_t>(0);
						uint32_t maxBitRate = static_cast<uint32_t>(0);
						uint16_t minKeyFrameInterval = static_cast<uint16_t>(0);
						uint16_t maxKeyFrameInterval = static_cast<uint16_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = Clusters::CameraAvStreamManagement::Commands::
							VideoStreamAllocateResponse::DecodableType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamAllocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						Globals::StreamUsageEnum streamUsage =
							static_cast<Globals::StreamUsageEnum>(0);
						VideoCodecEnum videoCodec = static_cast<VideoCodecEnum>(0);
						uint16_t minFrameRate = static_cast<uint16_t>(0);
						uint16_t maxFrameRate = static_cast<uint16_t>(0);
						Structs::VideoResolutionStruct::DecodableType minResolution;
						Structs::VideoResolutionStruct::DecodableType maxResolution;
						uint32_t minBitRate = static_cast<uint32_t>(0);
						uint32_t maxBitRate = static_cast<uint32_t>(0);
						uint16_t minKeyFrameInterval = static_cast<uint16_t>(0);
						uint16_t maxKeyFrameInterval = static_cast<uint16_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace VideoStreamAllocate
				namespace VideoStreamAllocateResponse
				{
					enum class Fields : uint8_t {
						kVideoStreamID = 0,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamAllocateResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t videoStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Encode(DataModel::FabricAwareTLVWriter &aWriter,
								  TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamAllocateResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t videoStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace VideoStreamAllocateResponse
				namespace VideoStreamModify
				{
					enum class Fields : uint8_t {
						kVideoStreamID = 0,
						kWatermarkEnabled = 1,
						kOSDEnabled = 2,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamModify::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t videoStreamID = static_cast<uint16_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamModify::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						uint16_t videoStreamID = static_cast<uint16_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace VideoStreamModify
				namespace VideoStreamDeallocate
				{
					enum class Fields : uint8_t {
						kVideoStreamID = 0,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamDeallocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t videoStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::VideoStreamDeallocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						uint16_t videoStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace VideoStreamDeallocate
				namespace SnapshotStreamAllocate
				{
					enum class Fields : uint8_t {
						kImageCodec = 0,
						kMaxFrameRate = 1,
						kMinResolution = 2,
						kMaxResolution = 3,
						kQuality = 4,
						kWatermarkEnabled = 5,
						kOSDEnabled = 6,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamAllocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						ImageCodecEnum imageCodec = static_cast<ImageCodecEnum>(0);
						uint16_t maxFrameRate = static_cast<uint16_t>(0);
						Structs::VideoResolutionStruct::Type minResolution;
						Structs::VideoResolutionStruct::Type maxResolution;
						uint8_t quality = static_cast<uint8_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = Clusters::CameraAvStreamManagement::Commands::
							SnapshotStreamAllocateResponse::DecodableType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamAllocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						ImageCodecEnum imageCodec = static_cast<ImageCodecEnum>(0);
						uint16_t maxFrameRate = static_cast<uint16_t>(0);
						Structs::VideoResolutionStruct::DecodableType minResolution;
						Structs::VideoResolutionStruct::DecodableType maxResolution;
						uint8_t quality = static_cast<uint8_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace SnapshotStreamAllocate
				namespace SnapshotStreamAllocateResponse
				{
					enum class Fields : uint8_t {
						kSnapshotStreamID = 0,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamAllocateResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t snapshotStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Encode(DataModel::FabricAwareTLVWriter &aWriter,
								  TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamAllocateResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t snapshotStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace SnapshotStreamAllocateResponse
				namespace SnapshotStreamModify
				{
					enum class Fields : uint8_t {
						kSnapshotStreamID = 0,
						kWatermarkEnabled = 1,
						kOSDEnabled = 2,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamModify::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t snapshotStreamID = static_cast<uint16_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamModify::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						uint16_t snapshotStreamID = static_cast<uint16_t>(0);
						Optional<bool> watermarkEnabled;
						Optional<bool> OSDEnabled;

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace SnapshotStreamModify
				namespace SnapshotStreamDeallocate
				{
					enum class Fields : uint8_t {
						kSnapshotStreamID = 0,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamDeallocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						uint16_t snapshotStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::SnapshotStreamDeallocate::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						uint16_t snapshotStreamID = static_cast<uint16_t>(0);

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace SnapshotStreamDeallocate
				namespace SetStreamPriorities
				{
					enum class Fields : uint8_t {
						kStreamPriorities = 0,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::SetStreamPriorities::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						DataModel::List<const Globals::StreamUsageEnum> streamPriorities;

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::SetStreamPriorities::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						DataModel::DecodableList<Globals::StreamUsageEnum> streamPriorities;

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace SetStreamPriorities
				namespace CaptureSnapshot
				{
					enum class Fields : uint8_t {
						kSnapshotStreamID = 0,
						kRequestedResolution = 1,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::CaptureSnapshot::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						DataModel::Nullable<uint16_t> snapshotStreamID;
						Structs::VideoResolutionStruct::Type requestedResolution;

						CHIP_ERROR Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const;

						using ResponseType = Clusters::CameraAvStreamManagement::Commands::
							CaptureSnapshotResponse::DecodableType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::CaptureSnapshot::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}
						static constexpr bool kIsFabricScoped = false;

						DataModel::Nullable<uint16_t> snapshotStreamID;
						Structs::VideoResolutionStruct::DecodableType requestedResolution;

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace CaptureSnapshot
				namespace CaptureSnapshotResponse
				{
					enum class Fields : uint8_t {
						kData = 0,
						kImageCodec = 1,
						kResolution = 2,
					};

					struct Type {
					public:
						// Use GetCommandId instead of commandId directly to avoid naming
						// conflict with CommandIdentification in ExecutionOfACommand
						static constexpr CommandId GetCommandId()
						{
							return Commands::CaptureSnapshotResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						chip::ByteSpan data;
						ImageCodecEnum imageCodec = static_cast<ImageCodecEnum>(0);
						Structs::VideoResolutionStruct::Type resolution;

						CHIP_ERROR Encode(DataModel::FabricAwareTLVWriter &aWriter,
								  TLV::Tag aTag) const;

						using ResponseType = DataModel::NullObjectType;

						static constexpr bool MustUseTimedInvoke() { return false; }
					};

					struct DecodableType {
					public:
						static constexpr CommandId GetCommandId()
						{
							return Commands::CaptureSnapshotResponse::Id;
						}
						static constexpr ClusterId GetClusterId()
						{
							return Clusters::CameraAvStreamManagement::Id;
						}

						chip::ByteSpan data;
						ImageCodecEnum imageCodec = static_cast<ImageCodecEnum>(0);
						Structs::VideoResolutionStruct::DecodableType resolution;

						CHIP_ERROR Decode(TLV::TLVReader &reader);
					};
				}; // namespace CaptureSnapshotResponse
			} // namespace Commands
		} // namespace CameraAvStreamManagement
	} // namespace Clusters
} // namespace app
} // namespace chip
