#include "Band.hpp"

#include <fstream>
#include <iostream>
#include <memory>

void Band::serialize_to(std::string fn) {
  std::ofstream ofs{fn};
  ofs << fn;
  ofs.close();
}

std::ostream &operator<<(std::ostream &os, const Band &b) {
  return os << b.root;
}
