#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main() {
    vector<pair<int, int>> input;
    int n, target_sum, num;
    cin >> n >> target_sum;
    
    for (int i = 0; i < n; ++i) {
        cin >> num;
        input.push_back({num, i+1}); 
    }
    
    sort(input.begin(), input.end());

    int left = 0, right = n - 1;
    bool found_ans = false;
    while (left < right) {
        int cur_sum = input[left].first + input[right].first;

        if (cur_sum < target_sum) {
            left++;
        } else if (cur_sum > target_sum) {
            right--;
        } else {
            found_ans = true;
            cout << input[left].second << " " << input[right].second << endl;
            break;
        }
    }

    if (!found_ans) {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
