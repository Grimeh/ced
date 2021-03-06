// Copyright 2017 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#pragma once

#include <boost/filesystem/path.hpp>
#include <memory>
#include <string>
#include <vector>

// can be used as a project aspect
class CompilationDatabase {
 public:
  CompilationDatabase();
  virtual ~CompilationDatabase();
  virtual std::string CompileCommandsFile() const = 0;

  bool ClangCompileArgs(const boost::filesystem::path& filename,
                        std::vector<std::string>* args);

 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
