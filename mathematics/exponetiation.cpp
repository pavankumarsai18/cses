#include <iostream>

using namespace std;

int exponent(int base, int power) {
	long long ans = 1;
	const int MOD = 1e9 + 7;

	if (power == 0) return 1;
	else if (power == 1) return base;
	else if (power == 2) {
		ans = base;
		ans = (ans * base)%MOD;
		return ans;
	}
	
	long long square_root = exponent(base, power >> 1);
	ans = (square_root*square_root)%MOD;

	if (power&1) {
		ans = (ans * base)%MOD;
	}

	return ans;

}

int main() {
	int n;
	int base, power;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> base; cin >> power;
		cout << exponent(base, power) << endl;
	}
	return 0;
}