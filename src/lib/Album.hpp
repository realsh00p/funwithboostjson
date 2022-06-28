#pragma once

#include <boost/json.hpp>
#include <boost/json/object.hpp>

#include <cstdint>
#include <string>

class Band;

class Album {
private:
  Band &parent;
  boost::json::object &album;

public:
  Album(Band &_parent, boost::json::object &_album)
      : parent(_parent), album(_album) {}

  auto done() -> Band & { return parent; }

  auto set_title(std::string value) -> Album & {
    album.insert_or_assign("title", std::move(value));
    return *this;
  }

  auto set_released(std::int16_t value) -> Album & {
    album.insert_or_assign("released", value);
    return *this;
  }
};
