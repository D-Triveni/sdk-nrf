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
// This file is generated from clusters-Commands.ipp.zapt

#include <clusters/Channel/Commands.h>

#include <app/data-model/Decode.h>
#include <app/data-model/StructDecodeIterator.h>
#include <app/data-model/WrappedStructEncoder.h>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		namespace Channel
		{
			namespace Commands
			{
				namespace ChangeChannel
				{

					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kMatch), match);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kMatch)) {
								err = DataModel::Decode(reader, match);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace ChangeChannel.
				namespace ChangeChannelResponse
				{

					CHIP_ERROR Type::Encode(DataModel::FabricAwareTLVWriter &aWriter,
								TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kStatus), status);
						encoder.Encode(to_underlying(Fields::kData), data);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kStatus)) {
								err = DataModel::Decode(reader, status);
							} else if (__context_tag == to_underlying(Fields::kData)) {
								err = DataModel::Decode(reader, data);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace ChangeChannelResponse.
				namespace ChangeChannelByNumber
				{

					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kMajorNumber), majorNumber);
						encoder.Encode(to_underlying(Fields::kMinorNumber), minorNumber);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kMajorNumber)) {
								err = DataModel::Decode(reader, majorNumber);
							} else if (__context_tag ==
								   to_underlying(Fields::kMinorNumber)) {
								err = DataModel::Decode(reader, minorNumber);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace ChangeChannelByNumber.
				namespace SkipChannel
				{

					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kCount), count);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kCount)) {
								err = DataModel::Decode(reader, count);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace SkipChannel.
				namespace GetProgramGuide
				{

					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kStartTime), startTime);
						encoder.Encode(to_underlying(Fields::kEndTime), endTime);
						encoder.Encode(to_underlying(Fields::kChannelList), channelList);
						encoder.Encode(to_underlying(Fields::kPageToken), pageToken);
						encoder.Encode(to_underlying(Fields::kRecordingFlag), recordingFlag);
						encoder.Encode(to_underlying(Fields::kExternalIDList), externalIDList);
						encoder.Encode(to_underlying(Fields::kData), data);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kStartTime)) {
								err = DataModel::Decode(reader, startTime);
							} else if (__context_tag == to_underlying(Fields::kEndTime)) {
								err = DataModel::Decode(reader, endTime);
							} else if (__context_tag ==
								   to_underlying(Fields::kChannelList)) {
								err = DataModel::Decode(reader, channelList);
							} else if (__context_tag == to_underlying(Fields::kPageToken)) {
								err = DataModel::Decode(reader, pageToken);
							} else if (__context_tag ==
								   to_underlying(Fields::kRecordingFlag)) {
								err = DataModel::Decode(reader, recordingFlag);
							} else if (__context_tag ==
								   to_underlying(Fields::kExternalIDList)) {
								err = DataModel::Decode(reader, externalIDList);
							} else if (__context_tag == to_underlying(Fields::kData)) {
								err = DataModel::Decode(reader, data);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace GetProgramGuide.
				namespace ProgramGuideResponse
				{

					CHIP_ERROR Type::Encode(DataModel::FabricAwareTLVWriter &aWriter,
								TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kPaging), paging);
						encoder.Encode(to_underlying(Fields::kProgramList), programList);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag == to_underlying(Fields::kPaging)) {
								err = DataModel::Decode(reader, paging);
							} else if (__context_tag ==
								   to_underlying(Fields::kProgramList)) {
								err = DataModel::Decode(reader, programList);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace ProgramGuideResponse.
				namespace RecordProgram
				{

					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kProgramIdentifier),
							       programIdentifier);
						encoder.Encode(to_underlying(Fields::kShouldRecordSeries),
							       shouldRecordSeries);
						encoder.Encode(to_underlying(Fields::kExternalIDList), externalIDList);
						encoder.Encode(to_underlying(Fields::kData), data);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag ==
							    to_underlying(Fields::kProgramIdentifier)) {
								err = DataModel::Decode(reader, programIdentifier);
							} else if (__context_tag ==
								   to_underlying(Fields::kShouldRecordSeries)) {
								err = DataModel::Decode(reader, shouldRecordSeries);
							} else if (__context_tag ==
								   to_underlying(Fields::kExternalIDList)) {
								err = DataModel::Decode(reader, externalIDList);
							} else if (__context_tag == to_underlying(Fields::kData)) {
								err = DataModel::Decode(reader, data);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace RecordProgram.
				namespace CancelRecordProgram
				{

					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kProgramIdentifier),
							       programIdentifier);
						encoder.Encode(to_underlying(Fields::kShouldRecordSeries),
							       shouldRecordSeries);
						encoder.Encode(to_underlying(Fields::kExternalIDList), externalIDList);
						encoder.Encode(to_underlying(Fields::kData), data);
						return encoder.Finalize();
					}

					CHIP_ERROR DecodableType::Decode(TLV::TLVReader &reader)
					{
						detail::StructDecodeIterator __iterator(reader);
						while (true) {
							uint8_t __context_tag = 0;
							CHIP_ERROR err = __iterator.Next(__context_tag);
							VerifyOrReturnError(err != CHIP_ERROR_END_OF_TLV,
									    CHIP_NO_ERROR);
							ReturnErrorOnFailure(err);

							if (__context_tag ==
							    to_underlying(Fields::kProgramIdentifier)) {
								err = DataModel::Decode(reader, programIdentifier);
							} else if (__context_tag ==
								   to_underlying(Fields::kShouldRecordSeries)) {
								err = DataModel::Decode(reader, shouldRecordSeries);
							} else if (__context_tag ==
								   to_underlying(Fields::kExternalIDList)) {
								err = DataModel::Decode(reader, externalIDList);
							} else if (__context_tag == to_underlying(Fields::kData)) {
								err = DataModel::Decode(reader, data);
							}

							ReturnErrorOnFailure(err);
						}
					}
				} // namespace CancelRecordProgram.
			} // namespace Commands
		} // namespace Channel
	} // namespace Clusters
} // namespace app
} // namespace chip
