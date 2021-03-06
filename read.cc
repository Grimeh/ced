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
#include "read.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "wrap_syscall.h"

std::string Read(const std::string& filename) {
  std::string out;

  int fd =
      WrapSyscall("open", [&]() { return open(filename.c_str(), O_RDONLY); });
  char buf[16384];
  int n;
  do {
    n = WrapSyscall("read", [&]() { return read(fd, buf, sizeof(buf)); });
    out.append(buf, n);
  } while (n == sizeof(buf));
  return out;
}
