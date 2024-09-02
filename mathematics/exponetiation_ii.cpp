#include <iostream>

using namespace std;

int exponent(int base, int power, int MOD) {
	long long ans = 1;

	if (power == 0) return 1;
	else if (power == 1) return base;
	else if (power == 2) {
		ans = base;
		ans = (ans * base)%MOD;
		return ans;
	}
	
	long long square_root = exponent(base, power >> 1, MOD);
	ans = (square_root*square_root)%MOD;

	if (power&1) {
		ans = (ans * base)%MOD;
	}

	return ans;

}

int main() {
	int n;
	int base, power, super_power;
	cin >> n;
	int mod = 1e9 + 7;
	for (int i = 0; i < n; ++i) {
		cin >> base; cin >> power; cin >> super_power;
		cout << exponent(base,exponent(power, super_power, (mod - 1)), mod) << endl;
	}
	return 0;
}
