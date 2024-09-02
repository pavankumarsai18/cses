#include <iostream>
#include <vector>
#include <utility>
using namespace std;
// TODO make memory efficient
bool canEmpty(int A, int B) {
	// 2X + 1Y = A
	// X + 2Y = B

	// 2X + 1Y = A
	// 2X + 4Y = 2B
	// 3Y = (2B - A) --> Y = (2B - A)/3


	// X = B - 2Y = (3B - 4B + 2A)/3 = (2A - B) / 3

	long long long_A = A;
	long long long_B = B;

	long long Y  = (2*long_B - long_A);
	long long X  = (2*long_A - long_B);

	return (Y%3 == 0 && Y >= 0) && (X%3 == 0 && X >= 0);
}

int main() {
	int n;
	int x, y;
	
	// Take input
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x; cin >> y;
		if (canEmpty(x, y)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	

	return 0;
}
