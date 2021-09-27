#include <iostream>
#include <limits>

#define MAX std::numeric_limits<int>::max()
#define MIN std::numeric_limits<int>::min()

int reverse(int x) {
	int rev = 0, rem = 0;
	while (x != 0) {
		rem = x % 10;
		/*
		 * (rev * 10 + rem)  can overflow in the following cases:
		 * 1. rev > MAX/10
		 * 2. rev == MAX/10 && rem > 7    (last digit of 2^31 - 1 is 7)
		 * 3. rev < MIN/10
		 * 4. rev == MIN/10 && rem < -8   (last digit of 2^31 is 8)
		 */
		if(rev > MAX/10 || rev < MIN/10 || (rev == MAX/10 && rem > 7) || (rev == MIN/10 && rem < -8)) {
			return 0;
		}
		rev = rev*10 + rem;
		x /= 10;
	}
	return rev;
}

int main(int argc, char *argv[]) {
	int num = std::atoi(argv[1]);
	std::cout << num << std::endl;
	if(num > std::numeric_limits<int>::max()) std::cout << "heccc\n";
	std::cout << reverse(num) << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
}

