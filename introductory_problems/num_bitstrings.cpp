#include <iostream>
using namespace std;

int num_bit_strings(int n) {
	const int MOD = 1e9 + 7;
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		ans = (ans << 1)%MOD;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	
	cout << num_bit_strings(n) << endl;
	return 0;
}
