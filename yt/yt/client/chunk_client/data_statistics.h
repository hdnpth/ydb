#pragma once

#include <yt/yt_proto/yt/client/chunk_client/proto/data_statistics.pb.h>

#include <yt/yt/core/compression/public.h>

#include <yt/yt/core/yson/public.h>

#include <yt/yt/core/ytree/public.h>

#include <yt/yt/core/misc/property.h>

#include <library/cpp/yt/small_containers/compact_flat_map.h>

namespace NYT::NChunkClient {

////////////////////////////////////////////////////////////////////////////////

namespace NProto {

bool HasInvalidDataWeight(const TDataStatistics& statistics);

TDataStatistics& operator += (TDataStatistics& lhs, const TDataStatistics& rhs);
TDataStatistics  operator +  (const TDataStatistics& lhs, const TDataStatistics& rhs);

bool operator == (const TDataStatistics& lhs, const TDataStatistics& rhs);

void Serialize(const TDataStatistics& statistics, NYson::IYsonConsumer* consumer);

void SetDataStatisticsField(TDataStatistics& statistics, TStringBuf key, i64 value);

void FormatValue(TStringBuilderBase* builder, const TDataStatistics& statistics, TStringBuf spec);
void FormatValue(TStringBuilderBase* builder, const TDataStatistics* statistics, TStringBuf spec);
TString ToString(const TDataStatistics& statistics);

} // namespace NProto

////////////////////////////////////////////////////////////////////////////////

struct TCodecDuration
{
    NCompression::ECodec Codec;
    TDuration CpuDuration;
};

class TCodecStatistics
{
public:
    using TCodecToDuration = TCompactFlatMap<
        NCompression::ECodec,
        TDuration,
        1>;
    DEFINE_BYREF_RO_PROPERTY(TCodecToDuration, CodecToDuration);

public:
    TCodecStatistics& Append(const TCodecDuration& codecTime);

    TCodecStatistics& operator+=(const TCodecStatistics& other);

    TDuration GetTotalDuration() const;

private:
    TDuration TotalDuration_;

    TCodecStatistics& Append(const std::pair<NCompression::ECodec, TDuration>& codecTime);
};

void FormatValue(TStringBuilderBase* builder, const TCodecStatistics& statistics, TStringBuf spec);
TString ToString(const TCodecStatistics& statistics);

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NChunkClient

