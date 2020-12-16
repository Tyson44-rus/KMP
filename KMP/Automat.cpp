#include "Automat.h"

bool Automat::next(char c) {
	while (last_prefix > 0 && sample[last_prefix] != c)
		last_prefix = prefix[last_prefix - 1];

	if (sample[last_prefix] == c)
		last_prefix++;

	return last_prefix == sample.length();
}

void Automat::reset() {
	last_prefix = 0;
}