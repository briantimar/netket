// Copyright 2018 The Simons Foundation, Inc. - All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef NETKET_DATA_LOADER
#define NETKET_DATA_LOADER

#include <fstream>
#include <iostream>
#include <json.hpp>
#include <string>
#include <vector>

#include "exceptions.hpp"

/** Get Eigen matrix from comma-separated input.
*/
namespace netket {


template <typename T>
class DataLoader {
  using MatrixType = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic, RowMajor>;

  std::string fname_;
  MatrixType data_;

  public:
    DataLoader(std::string filename) : fname_(filename) {
      data_(ReadAll(fname_));
    };

  MatrixType ReadAll(std::string filename) {
      std::ifstream filein(fname_);
      if (filein.is_open()) {

      std::string line;
      std::string entry;
      int numlines;
      std::vector<double> flattened;
      while (std::getline(filein, line)){
        std::stringstream linevals(line);
        std::string entry;
        while (std::getline(stringstream, entry, ',')){
          flattend.push_back(std::stod(entry));
        }
        numlines++;
      }
      int numcol = flattened.size()/numlines;
      return Eigen::Map<MatrixType>(flattened, numrow, numcol);
    }
     else {
      std::stringstream s;
      s << "Cannot open file: " << filename;
      throw InvalidInputError(s.str());
    }
  };
};
}  // namespace netket

#endif
