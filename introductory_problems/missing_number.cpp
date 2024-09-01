#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	long long sum_so_far = 0;
	cin >> num;
	for (int i = 0; i < num - 1; i++) {
		int temp;
		cin >> temp;
		sum_so_far += temp;
	}
	long long n_sum = num;
	n_sum *= (num + 1);
	n_sum >>= 1;

	cout << (n_sum - sum_so_far) << endl;
	return 0;
}
