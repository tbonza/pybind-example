#ifndef HEYLIB_HELLO_H
#define HEYLIB_HELLO_H

#include <string>

namespace hey {

struct Hey {
	int count;
	std::string greeting;

	Hey(int ct, std::string greet) : count(ct), greeting(greet) {}
};

int getCount(Hey& hey);
std::string getGreeting(Hey& hey);

// Update values in greeting.
void updateHey(Hey& greet);

} // namespace hey

#endif // HEYLIB_HELLO_H
