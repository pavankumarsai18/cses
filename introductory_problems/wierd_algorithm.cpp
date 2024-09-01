#include <iostream>
#include <string>
#include <vector>
using namespace std;

void collatz(long long num) {
	while (num != 1) {
		cout << (num) << " ";
		if (num & 1) {
			num = num*3 + 1;
		} else {
			num >>= 1;
		}
	}
	
	cout << 1 << endl;	
}

int main() {
	long long num;
	cin >> num;
	collatz(num);
	return 0;
}
