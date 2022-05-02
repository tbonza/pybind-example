
#include "heylib/hello.h"
#include "heylib/internal/greeting.h"

namespace hey {

int getCount(Hey& hey) {
	return hey.count;
}

std::string getGreeting(Hey& hey) {
	if (hey.greeting.empty())
		return "";
	return hey.greeting;
}

void updateHey(Hey& greet) {
	internal::updateGreeting(greet);
	internal::updateCount(greet);
}

} // namespace hey
