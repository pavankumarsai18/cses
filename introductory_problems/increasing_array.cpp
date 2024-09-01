#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size;
	vector<int> nums;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		int number; cin >> number;
		nums.push_back(number);
	}


	long long num_moves = 0;
	
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] >= nums[i - 1]) continue;
		else {
			num_moves += (nums[i-1] - nums[i]);
			nums[i] = nums[i-1];
		}
	}
	cout <<num_moves <<endl;
	return 0;
}
