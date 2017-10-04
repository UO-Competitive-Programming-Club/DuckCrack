#include "../Debug.h" 

using namespace std;

/* it has a very interesting edge case */
bool isUgly(int num) {
	int divisors[3] = { 2, 3, 5 };
	while ( (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) && abs(num) > 1) {
		for (int i = 0; i < 3; i++) {
			if (num % divisors[i] == 0) {
				num /= divisors[i];
			}
		}
	}

	return (num == 1);
}

int main(void) {

    int input = -1000;

    std::cout << isUgly(input) << std::endl;
    return 0;
}
