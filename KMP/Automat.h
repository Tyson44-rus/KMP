#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Automat {
	string& sample;
	vector<size_t> prefix;
	int last_prefix;
public:
	Automat(string& sample) :sample(sample), prefix(sample.length()) {
		last_prefix = prefix[0] = 0;
		for (size_t i = 1; i < sample.length(); i++) {
			next(sample[i]);
			prefix[i] = last_prefix;
		}
		reset();
	}
	bool next(char c);
	void reset();
};
