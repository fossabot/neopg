/* OpenPGP format
   Copyright 2017 The NeoPG developers

   NeoPG is released under the Simplified BSD License (see license.txt)
*/

#include <neopg/openpgp/header.h>
#include <neopg/openpgp/symmetrically_encrypted_data_packet.h>

namespace NeoPG {
namespace OpenPGP {

void SymmetricallyEncryptedDataPacket::write_body(std::ostream& out) const {
  out.write((char*)m_data.data(), m_data.size());
}

PacketType SymmetricallyEncryptedDataPacket::type() const {
  return PacketType::SymmetricallyEncryptedData;
}

}  // namespace OpenPGP
}  // namespace NeoPG
