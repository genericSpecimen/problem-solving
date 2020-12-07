#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <vector>

/*
// solution using a map to record frequencies
bool is_lapindrome(const std::string& S) {
	std::map<char, int> freq;
	int i = 0;
	for(; i<S.size()/2; i++) {
		freq[S[i]]++;
	}

	// if odd length string, then ignore the current character
	if(S.size() % 2 != 0) i++;

	for(; i<S.size(); i++) {
		freq[S[i]]--;
	}
	for (auto itr = freq.begin(); itr != freq.end(); itr++) {
		// std::cout << itr->first << " " << itr->second << "\n";
		if(itr->second != 0) return false;
	}
	return true;
}
*/

// simpler solution with an array
bool is_lapindrome(const std::string& S) {
	// frequency array for each of the 26 alphabets
	std::vector<int> freq(26, 0);

	int i = 0, half_len = S.size() / 2;

	for(; i < half_len; i++) {
		freq[S[i] - 'a']++;
	}
	
	// if odd length string, then skip the current (middle) character
	if(S.size() % 2 != 0) i++;
	
	for(; i < S.size(); i++) {
		freq[S[i] - 'a']--;
	}

	for(auto f : freq) {
		if(f != 0) return false;
	}
	return true;
}

int main() {
	int T; std::cin >> T;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string S;
	while(T--) {
		std::getline(std::cin, S);
		std::cout << (is_lapindrome(S) ? "YES\n" : "NO\n");
	}
	return 0;
}
