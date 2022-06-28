#pragma once

#include "Album.hpp"
#include "Member.hpp"

#include <boost/json/array.hpp>
#include <boost/json/value.hpp>
#include <list>
#include <memory>

#include <boost/json.hpp>
#include <boost/json/object.hpp>

class Band {
private:
  boost::json::object root;

  std::list<Album *> albums;
  std::list<Member *> members;

public:
  void serialize_to(std::string fn);

  friend std::ostream &operator<<(std::ostream &os, const Band &band);

  auto set_name(std::string value) -> Band & {
    root.insert_or_assign("name", std::move(value));
    return *this;
  }

  auto set_founded(std::int64_t value) -> Band & {
    root.insert_or_assign("founded", value);
    return *this;
  }

  auto add_album() -> Album {
    constexpr auto key{"albums"};
    if (!root.contains(key)) {
      root.insert_or_assign(key, boost::json::array{});
    }
    auto &object =
        root.at(key).as_array().emplace_back(boost::json::object{}).as_object();

    return Album{*this, object};
  }

  auto add_member() -> Member {
    constexpr auto key{"members"};
    if (!root.contains(key)) {
      root.insert_or_assign(key, boost::json::array{});
    }
    auto &object =
        root.at(key).as_array().emplace_back(boost::json::object{}).as_object();

    return Member{*this, object};
  }
};

std::ostream &operator<<(std::ostream &os, const Band &b);
