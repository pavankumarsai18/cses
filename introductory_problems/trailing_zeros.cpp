#include <iostream>

using namespace std;

int factorial_zeros(int n) {
	int num_zeros = 0;
	// find the power of five
	for (long long five_power = 5; five_power <= n; five_power *= 5) {
		num_zeros += (n/five_power);
	}
	return num_zeros;
}

int main() {
	int n;
	cin >> n;
	cout << factorial_zeros(n) << endl;
	return 0;
}
