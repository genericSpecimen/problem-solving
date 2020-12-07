#include <iostream>
#include <cstdio>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	/*
	std::string buffer;
	
	while(std::cin >> buffer) {

	}
		
	std::cout << "hello\n";
	std::printf("world!\n");
	*/

	/*
	std::cout << "Enter a number: \n";
	int n;
	std::cin >> n;
	std::cout << "You entered: " << n << "\n";
	*/
	/*
	while(std::cin >> buffer) {
		std::cout << "hmm\n";
	}
	*/

	int x = 10000000, y = 10000000;
	//long long int z = x * static_cast<long long int>(y);
	// OR
	long long int z = 1LL * x * y;
	std::cout << z << "\n";

	return 0;
}
