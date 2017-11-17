/* OpenPGP format
   Copyright 2017 The NeoPG developers

   NeoPG is released under the Simplified BSD License (see license.txt)
*/

#include <neopg/openpgp/header.h>
#include <neopg/openpgp/modification_detection_code_packet.h>

namespace NeoPG {
namespace OpenPGP {

void ModificationDetectionCodePacket::write_body(std::ostream& out) const {
  if (m_data.size() != 20) {
    throw std::logic_error("modification detection code has wrong size");
  }

  out.write((char*)m_data.data(), m_data.size());
}

PacketType ModificationDetectionCodePacket::type() const {
  return PacketType::ModificationDetectionCode;
}

}  // namespace OpenPGP
}  // namespace NeoPG
