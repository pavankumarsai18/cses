#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

long long min_partition(int index, long long sum1, long long sum2, vector<int> & weights) {
	if (index == weights.size()) {
		return abs(sum1 - sum2);
	}

	long long choose = min_partition(index + 1, sum1 + weights[index], sum2, weights);
	long long do_not_choose = min_partition(index + 1, sum1, sum2 + weights[index], weights);

	return min(choose, do_not_choose);

}


int main() {
	int n;
	cin >> n;
	vector<int> weights;
	for (int i = 0; i < n; ++i) {
		int weight; cin >> weight;
		weights.push_back(weight);
	}

	cout << min_partition(0, 0, 0, weights) << endl;

	return 0;
}
