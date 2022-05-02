
#include "heylib/internal/greeting.h"
#include <gtest/gtest.h>

namespace hey {
namespace internal {

TEST(GreetingTest, HasGreeting) {
	auto h = Hey(0,"");

	updateGreeting(h);
	updateGreeting(h);
	updateGreeting(h);

	EXPECT_EQ(h.greeting, "hey hey hey ");
	EXPECT_EQ(h.count, 0);
}

TEST(GreetingTest, HasCount) {
	auto h = Hey(0,"");

	updateCount(h);
	updateCount(h);
	updateCount(h);

	EXPECT_EQ(h.greeting, "");
	EXPECT_EQ(h.count, 3);
}

} // namespace internal
} // namespace hey

