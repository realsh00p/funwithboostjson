#include "Band.hpp"

#include <gtest/gtest.h>

TEST(Foo, shouldBar) {
  Band band;
  // clang-format off
  band.set_name("Iron Maiden")
      .set_founded(1975)
      .add_album()
        .set_title("The Number Of The Beast")
        .set_released(1982)
        .done()
      .add_album()
        .set_title("Piece Of Mind")
        .set_released(1983)
        .done()
      .add_member()
        .set_name("Bruce Dickinson")
        .set_instrument("Vocals")
        .done()
      .add_member()
        .set_name("Steve Harris")
        .set_instrument("Bass Guitar")
        .done();
  // clang-format on

  std::cout << band;

  ASSERT_TRUE(true);
}
