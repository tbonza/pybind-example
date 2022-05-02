#ifndef HEYLIB_INTERNAL_GREETING_H
#define HEYLIB_INTERNAL_GREETING_H

#include "heylib/hello.h"

namespace hey {
namespace internal {

void updateGreeting(Hey& greet);
void updateCount(Hey& greet);

} // namespace internal
} // namespace hey


#endif // HEYLIB_INTERNAL_GREETING_H
