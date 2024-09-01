#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void find_permutation(int n) {
	// 3 1 4 2
	// 4 2 5 1 3 --> [1 2] [3 4 5] --> [2 1] [5 4 3] --> [4 2 5 1 3]
	// 1 2 3 4 5 6 --> [1 2 3] [4 5 6] --> [3 2 1] [6 5 4] --> 6 3 5 2 4 1
	// 1 2 3 4 5 6 7 --> [1 2 3] [4 5 6 7] --> [3 2 1] [7 6 5 4] --> 6 3 7 2 5 1 4
	int first_half = n/2;
	int second_half = (n&1) ? (n - 1) : n;
	bool used_n = false;
	bool second_half_printed = false;
	int num_printed = 0;
	while (num_printed < n) {
		if (second_half_printed) {
			cout << first_half << " ";
			first_half--;
		} else {
			if ((n & 1) && second_half == (n - 2) &&  !used_n) {
				cout << n << " ";	
				used_n = true;
			} else {
				cout << second_half << " ";
				second_half--;
			}
			
		}
		second_half_printed = !second_half_printed;
		num_printed++;
	}
	cout << "\n";
	return;
}
int main() {
	int n;
	cin >> n;
	if (n == 1) {cout <<"1\n";}
	else if (n <= 3) {cout <<"NO SOLUTION\n";}
	else if (n == 4) {cout << "3 1 4 2\n";}
	else {
		find_permutation(n);
	}
	return 0;
}
