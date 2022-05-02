
#include "heylib/hello.h"
#include <gtest/gtest.h>

namespace hey {

TEST(HelloTest, InitHey) {
	auto h = Hey(0,"bert");

	EXPECT_EQ(h.count,0);
	EXPECT_EQ(h.greeting, "bert");
}

TEST(HelloTest, CheckIn) {
	auto h = Hey(0,"bert");

	EXPECT_EQ(getCount(h), 0);
	EXPECT_EQ(getGreeting(h), "bert");
}

TEST(HelloTest, CheckBackIn) {
	auto h = Hey(0,"bert");

	updateHey(h);

	EXPECT_EQ(getCount(h), 1);
	EXPECT_EQ(getGreeting(h), "hey bert");
}

} // namespace hey
