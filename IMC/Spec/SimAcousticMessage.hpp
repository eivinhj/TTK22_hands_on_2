//***************************************************************************
// Copyright 2017 OceanScan - Marine Systems & Technology, Lda.             *
//***************************************************************************
// Licensed under the Apache License, Version 2.0 (the "License");          *
// you may not use this file except in compliance with the License.         *
// You may obtain a copy of the License at                                  *
//                                                                          *
// http://www.apache.org/licenses/LICENSE-2.0                               *
//                                                                          *
// Unless required by applicable law or agreed to in writing, software      *
// distributed under the License is distributed on an "AS IS" BASIS,        *
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
// See the License for the specific language governing permissions and      *
// limitations under the License.                                           *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 0fe4582bf06b504af601569d6a25a3a2                            *
//***************************************************************************

#ifndef IMC_SIMACOUSTICMESSAGE_HPP_INCLUDED_
#define IMC_SIMACOUSTICMESSAGE_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// IMC headers.
#include <IMC/Base/Config.hpp>
#include <IMC/Base/Message.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/JSON.hpp>
#include <IMC/Base/Serialization.hpp>
#include <IMC/Spec/Enumerations.hpp>
#include <IMC/Spec/Bitfields.hpp>

namespace IMC
{
  //! Simulated Acoustic Message.
  class SimAcousticMessage: public Message
  {
  public:
    //! Flags.
    enum FlagsBits
    {
      //! Acknowledgement.
      SAM_ACK = 0x01,
      //! Delayed.
      SAM_DELAYED = 0x02,
      //! Reply.
      SAM_REPLY = 0x03
    };

    //! Latitude.
    double lat;
    //! Longitude.
    double lon;
    //! Depth.
    float depth;
    //! Sentence.
    std::string sentence;
    //! Transmission Time.
    double txtime;
    //! Modem Type.
    std::string modem_type;
    //! Source system.
    std::string sys_src;
    //! Sequence Id.
    uint16_t seq;
    //! Destination System.
    std::string sys_dst;
    //! Flags.
    uint8_t flags;
    //! Data.
    std::vector<char> data;

    static uint16_t
    getIdStatic(void)
    {
      return 207;
    }

    static SimAcousticMessage*
    cast(Message* msg__)
    {
      return (SimAcousticMessage*)msg__;
    }

    SimAcousticMessage(void)
    {
      m_header.mgid = SimAcousticMessage::getIdStatic();
      clear();
    }

    SimAcousticMessage*
    clone(void) const
    {
      return new SimAcousticMessage(*this);
    }

    void
    clear(void)
    {
      lat = 0;
      lon = 0;
      depth = 0;
      sentence.clear();
      txtime = 0;
      modem_type.clear();
      sys_src.clear();
      seq = 0;
      sys_dst.clear();
      flags = 0;
      data.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SimAcousticMessage& other__ = static_cast<const SimAcousticMessage&>(msg__);
      if (lat != other__.lat) return false;
      if (lon != other__.lon) return false;
      if (depth != other__.depth) return false;
      if (sentence != other__.sentence) return false;
      if (txtime != other__.txtime) return false;
      if (modem_type != other__.modem_type) return false;
      if (sys_src != other__.sys_src) return false;
      if (seq != other__.seq) return false;
      if (sys_dst != other__.sys_dst) return false;
      if (flags != other__.flags) return false;
      if (data != other__.data) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(lat, ptr__);
      ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(depth, ptr__);
      ptr__ += IMC::serialize(sentence, ptr__);
      ptr__ += IMC::serialize(txtime, ptr__);
      ptr__ += IMC::serialize(modem_type, ptr__);
      ptr__ += IMC::serialize(sys_src, ptr__);
      ptr__ += IMC::serialize(seq, ptr__);
      ptr__ += IMC::serialize(sys_dst, ptr__);
      ptr__ += IMC::serialize(flags, ptr__);
      ptr__ += IMC::serialize(data, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(lat, bfr__, size__);
      bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(depth, bfr__, size__);
      bfr__ += IMC::deserialize(sentence, bfr__, size__);
      bfr__ += IMC::deserialize(txtime, bfr__, size__);
      bfr__ += IMC::deserialize(modem_type, bfr__, size__);
      bfr__ += IMC::deserialize(sys_src, bfr__, size__);
      bfr__ += IMC::deserialize(seq, bfr__, size__);
      bfr__ += IMC::deserialize(sys_dst, bfr__, size__);
      bfr__ += IMC::deserialize(flags, bfr__, size__);
      bfr__ += IMC::deserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(lat, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(lon, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(depth, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(sentence, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(txtime, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(modem_type, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(sys_src, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(seq, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(sys_dst, bfr__, size__);
      bfr__ += IMC::deserialize(flags, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SimAcousticMessage::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SimAcousticMessage";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 31;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(sentence) + IMC::getSerializationSize(modem_type) + IMC::getSerializationSize(sys_src) + IMC::getSerializationSize(sys_dst) + IMC::getSerializationSize(data);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "lat", lat, nindent__);
      IMC::toJSON(os__, "lon", lon, nindent__);
      IMC::toJSON(os__, "depth", depth, nindent__);
      IMC::toJSON(os__, "sentence", sentence, nindent__);
      IMC::toJSON(os__, "txtime", txtime, nindent__);
      IMC::toJSON(os__, "modem_type", modem_type, nindent__);
      IMC::toJSON(os__, "sys_src", sys_src, nindent__);
      IMC::toJSON(os__, "seq", seq, nindent__);
      IMC::toJSON(os__, "sys_dst", sys_dst, nindent__);
      IMC::toJSON(os__, "flags", flags, nindent__);
      IMC::toJSON(os__, "data", data, nindent__);
    }
  };
}

#endif
