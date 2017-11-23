/* Command line parsing
   Copyright 2017 The NeoPG developers

   NeoPG is released under the Simplified BSD License (see license.txt)
*/

#pragma once

#include <neopg/cli/command.h>

namespace NeoPG {
namespace CLI {

class ListHashCommand : public Command {
 public:
  ListHashCommand(CLI::App& app, const std::string& flag,
                  const std::string& description,
                  const std::string& group_name = "")
      : Command(app, flag, description, group_name) {}
  void run();
};

class HashCommand : public Command {
 public:
  std::string m_algo{"SHA-256"};
  const std::string group = "Commands";
  ListHashCommand cmd_list;

  void run() override;
  HashCommand(CLI::App& app, const std::string& flag,
              const std::string& description,
              const std::string& group_name = "")
      : Command(app, flag, description, group_name),
        cmd_list(m_cmd, "list", "list supported hash functions", group) {
    m_cmd.add_option("--algo", m_algo, "hash function", true);
  }
  virtual ~HashCommand() {}
};

}  // Namespace CLI
}  // Namespace NeoPG
