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
// This file is generated from clusters-Structs.ipp.zapt

#include <clusters/UnitTesting/Structs.h>

#include <app/data-model/StructDecodeIterator.h>
#include <app/data-model/WrappedStructEncoder.h>

namespace chip
{
namespace app
{
	namespace Clusters
	{
		namespace UnitTesting
		{
			namespace Structs
			{

				namespace SimpleStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kA), a);
						encoder.Encode(to_underlying(Fields::kB), b);
						encoder.Encode(to_underlying(Fields::kC), c);
						encoder.Encode(to_underlying(Fields::kD), d);
						encoder.Encode(to_underlying(Fields::kE), e);
						encoder.Encode(to_underlying(Fields::kF), f);
						encoder.Encode(to_underlying(Fields::kG), g);
						encoder.Encode(to_underlying(Fields::kH), h);
						encoder.Encode(to_underlying(Fields::kI), i);
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

							if (__context_tag == to_underlying(Fields::kA)) {
								err = DataModel::Decode(reader, a);
							} else if (__context_tag == to_underlying(Fields::kB)) {
								err = DataModel::Decode(reader, b);
							} else if (__context_tag == to_underlying(Fields::kC)) {
								err = DataModel::Decode(reader, c);
							} else if (__context_tag == to_underlying(Fields::kD)) {
								err = DataModel::Decode(reader, d);
							} else if (__context_tag == to_underlying(Fields::kE)) {
								err = DataModel::Decode(reader, e);
							} else if (__context_tag == to_underlying(Fields::kF)) {
								err = DataModel::Decode(reader, f);
							} else if (__context_tag == to_underlying(Fields::kG)) {
								err = DataModel::Decode(reader, g);
							} else if (__context_tag == to_underlying(Fields::kH)) {
								err = DataModel::Decode(reader, h);
							} else if (__context_tag == to_underlying(Fields::kI)) {
								err = DataModel::Decode(reader, i);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace SimpleStruct

				namespace TestFabricScoped
				{
					CHIP_ERROR Type::EncodeForWrite(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						return DoEncode(aWriter, aTag, NullOptional);
					}

					CHIP_ERROR Type::EncodeForRead(TLV::TLVWriter &aWriter, TLV::Tag aTag,
								       FabricIndex aAccessingFabricIndex) const
					{
						return DoEncode(aWriter, aTag, MakeOptional(aAccessingFabricIndex));
					}

					CHIP_ERROR
					Type::DoEncode(TLV::TLVWriter &aWriter, TLV::Tag aTag,
						       const Optional<FabricIndex> &aAccessingFabricIndex) const
					{
						bool includeSensitive = !aAccessingFabricIndex.HasValue() ||
									(aAccessingFabricIndex.Value() == fabricIndex);

						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };

						if (includeSensitive) {
							encoder.Encode(to_underlying(Fields::kFabricSensitiveInt8u),
								       fabricSensitiveInt8u);
						}
						if (includeSensitive) {
							encoder.Encode(
								to_underlying(Fields::kOptionalFabricSensitiveInt8u),
								optionalFabricSensitiveInt8u);
						}
						if (includeSensitive) {
							encoder.Encode(
								to_underlying(Fields::kNullableFabricSensitiveInt8u),
								nullableFabricSensitiveInt8u);
						}
						if (includeSensitive) {
							encoder.Encode(
								to_underlying(
									Fields::kNullableOptionalFabricSensitiveInt8u),
								nullableOptionalFabricSensitiveInt8u);
						}
						if (includeSensitive) {
							encoder.Encode(
								to_underlying(Fields::kFabricSensitiveCharString),
								fabricSensitiveCharString);
						}
						if (includeSensitive) {
							encoder.Encode(to_underlying(Fields::kFabricSensitiveStruct),
								       fabricSensitiveStruct);
						}
						if (includeSensitive) {
							encoder.Encode(to_underlying(Fields::kFabricSensitiveInt8uList),
								       fabricSensitiveInt8uList);
						}
						if (aAccessingFabricIndex.HasValue()) {
							encoder.Encode(to_underlying(Fields::kFabricIndex),
								       fabricIndex);
						}

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
							    to_underlying(Fields::kFabricSensitiveInt8u)) {
								err = DataModel::Decode(reader, fabricSensitiveInt8u);
							} else if (__context_tag ==
								   to_underlying(
									   Fields::kOptionalFabricSensitiveInt8u)) {
								err = DataModel::Decode(reader,
											optionalFabricSensitiveInt8u);
							} else if (__context_tag ==
								   to_underlying(
									   Fields::kNullableFabricSensitiveInt8u)) {
								err = DataModel::Decode(reader,
											nullableFabricSensitiveInt8u);
							} else if (__context_tag ==
								   to_underlying(
									   Fields::kNullableOptionalFabricSensitiveInt8u)) {
								err = DataModel::Decode(
									reader, nullableOptionalFabricSensitiveInt8u);
							} else if (__context_tag ==
								   to_underlying(Fields::kFabricSensitiveCharString)) {
								err = DataModel::Decode(reader,
											fabricSensitiveCharString);
							} else if (__context_tag ==
								   to_underlying(Fields::kFabricSensitiveStruct)) {
								err = DataModel::Decode(reader, fabricSensitiveStruct);
							} else if (__context_tag ==
								   to_underlying(Fields::kFabricSensitiveInt8uList)) {
								err = DataModel::Decode(reader,
											fabricSensitiveInt8uList);
							} else if (__context_tag ==
								   to_underlying(Fields::kFabricIndex)) {
								err = DataModel::Decode(reader, fabricIndex);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace TestFabricScoped

				namespace NullablesAndOptionalsStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kNullableInt), nullableInt);
						encoder.Encode(to_underlying(Fields::kOptionalInt), optionalInt);
						encoder.Encode(to_underlying(Fields::kNullableOptionalInt),
							       nullableOptionalInt);
						encoder.Encode(to_underlying(Fields::kNullableString), nullableString);
						encoder.Encode(to_underlying(Fields::kOptionalString), optionalString);
						encoder.Encode(to_underlying(Fields::kNullableOptionalString),
							       nullableOptionalString);
						encoder.Encode(to_underlying(Fields::kNullableStruct), nullableStruct);
						encoder.Encode(to_underlying(Fields::kOptionalStruct), optionalStruct);
						encoder.Encode(to_underlying(Fields::kNullableOptionalStruct),
							       nullableOptionalStruct);
						encoder.Encode(to_underlying(Fields::kNullableList), nullableList);
						encoder.Encode(to_underlying(Fields::kOptionalList), optionalList);
						encoder.Encode(to_underlying(Fields::kNullableOptionalList),
							       nullableOptionalList);
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

							if (__context_tag == to_underlying(Fields::kNullableInt)) {
								err = DataModel::Decode(reader, nullableInt);
							} else if (__context_tag ==
								   to_underlying(Fields::kOptionalInt)) {
								err = DataModel::Decode(reader, optionalInt);
							} else if (__context_tag ==
								   to_underlying(Fields::kNullableOptionalInt)) {
								err = DataModel::Decode(reader, nullableOptionalInt);
							} else if (__context_tag ==
								   to_underlying(Fields::kNullableString)) {
								err = DataModel::Decode(reader, nullableString);
							} else if (__context_tag ==
								   to_underlying(Fields::kOptionalString)) {
								err = DataModel::Decode(reader, optionalString);
							} else if (__context_tag ==
								   to_underlying(Fields::kNullableOptionalString)) {
								err = DataModel::Decode(reader, nullableOptionalString);
							} else if (__context_tag ==
								   to_underlying(Fields::kNullableStruct)) {
								err = DataModel::Decode(reader, nullableStruct);
							} else if (__context_tag ==
								   to_underlying(Fields::kOptionalStruct)) {
								err = DataModel::Decode(reader, optionalStruct);
							} else if (__context_tag ==
								   to_underlying(Fields::kNullableOptionalStruct)) {
								err = DataModel::Decode(reader, nullableOptionalStruct);
							} else if (__context_tag ==
								   to_underlying(Fields::kNullableList)) {
								err = DataModel::Decode(reader, nullableList);
							} else if (__context_tag ==
								   to_underlying(Fields::kOptionalList)) {
								err = DataModel::Decode(reader, optionalList);
							} else if (__context_tag ==
								   to_underlying(Fields::kNullableOptionalList)) {
								err = DataModel::Decode(reader, nullableOptionalList);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace NullablesAndOptionalsStruct

				namespace NestedStruct
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kA), a);
						encoder.Encode(to_underlying(Fields::kB), b);
						encoder.Encode(to_underlying(Fields::kC), c);
						encoder.Encode(to_underlying(Fields::kD), d);
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

							if (__context_tag == to_underlying(Fields::kA)) {
								err = DataModel::Decode(reader, a);
							} else if (__context_tag == to_underlying(Fields::kB)) {
								err = DataModel::Decode(reader, b);
							} else if (__context_tag == to_underlying(Fields::kC)) {
								err = DataModel::Decode(reader, c);
							} else if (__context_tag == to_underlying(Fields::kD)) {
								err = DataModel::Decode(reader, d);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace NestedStruct

				namespace NestedStructList
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kA), a);
						encoder.Encode(to_underlying(Fields::kB), b);
						encoder.Encode(to_underlying(Fields::kC), c);
						encoder.Encode(to_underlying(Fields::kD), d);
						encoder.Encode(to_underlying(Fields::kE), e);
						encoder.Encode(to_underlying(Fields::kF), f);
						encoder.Encode(to_underlying(Fields::kG), g);
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

							if (__context_tag == to_underlying(Fields::kA)) {
								err = DataModel::Decode(reader, a);
							} else if (__context_tag == to_underlying(Fields::kB)) {
								err = DataModel::Decode(reader, b);
							} else if (__context_tag == to_underlying(Fields::kC)) {
								err = DataModel::Decode(reader, c);
							} else if (__context_tag == to_underlying(Fields::kD)) {
								err = DataModel::Decode(reader, d);
							} else if (__context_tag == to_underlying(Fields::kE)) {
								err = DataModel::Decode(reader, e);
							} else if (__context_tag == to_underlying(Fields::kF)) {
								err = DataModel::Decode(reader, f);
							} else if (__context_tag == to_underlying(Fields::kG)) {
								err = DataModel::Decode(reader, g);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace NestedStructList

				namespace DoubleNestedStructList
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kA), a);
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

							if (__context_tag == to_underlying(Fields::kA)) {
								err = DataModel::Decode(reader, a);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace DoubleNestedStructList

				namespace TestListStructOctet
				{
					CHIP_ERROR Type::Encode(TLV::TLVWriter &aWriter, TLV::Tag aTag) const
					{
						DataModel::WrappedStructEncoder encoder{ aWriter, aTag };
						encoder.Encode(to_underlying(Fields::kMember1), member1);
						encoder.Encode(to_underlying(Fields::kMember2), member2);
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

							if (__context_tag == to_underlying(Fields::kMember1)) {
								err = DataModel::Decode(reader, member1);
							} else if (__context_tag == to_underlying(Fields::kMember2)) {
								err = DataModel::Decode(reader, member2);
							}

							ReturnErrorOnFailure(err);
						}
					}

				} // namespace TestListStructOctet
			} // namespace Structs
		} // namespace UnitTesting
	} // namespace Clusters
} // namespace app
} // namespace chip
