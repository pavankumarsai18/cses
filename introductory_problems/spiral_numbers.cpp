#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
long long find_num(int r, int c) {
	int max_ = max(r, c);
	long long spiral_square = max_; spiral_square *= max_;
	int dist = 0;
	if (max_ & 1) { // perfect square sits on (1, max)
		dist = abs(r - 1) + abs(max_ - c);
	} else { // perfect square sits on (max, 1)
		dist = abs(r - max_) + abs(c - 1);
	}
	return spiral_square - dist;
}


int main() {
	int t, x, y;
	vector<long long> ans;
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		cin >> x; cin >> y;
		ans.push_back(find_num(x, y));
	}
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
