
#include "heylib/internal/greeting.h"

namespace hey {
namespace internal {

void updateGreeting(Hey& greet) {
	greet.greeting = "hey " + greet.greeting;
}

void updateCount(Hey& greet) {
	greet.count += 1;
}

} // namespace internal
} // namespace hey
