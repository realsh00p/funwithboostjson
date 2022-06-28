#pragma once

#include <boost/json.hpp>
#include <boost/json/object.hpp>

#include <cstdint>
#include <string>

class Band;

class Member {
private:
  using object = boost::json::object;

  Band &parent;
  object &member;

public:
  Member(Band &_parent, object &_member) : parent(_parent), member(_member) {}

  auto done() -> Band & { return parent; }

  auto set_name(std::string value) -> Member & {
    member.insert_or_assign("name", std::move(value));
    return *this;
  }

  auto set_instrument(std::string value) -> Member & {
    member.insert_or_assign("instrument", std::move(value));
    return *this;
  }
};
