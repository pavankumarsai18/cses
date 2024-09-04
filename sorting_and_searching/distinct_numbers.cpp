#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int number;
    vector<int> input;

    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> number;
        input.push_back(number);
    }

    
    sort(input.begin(), input.end());

    size_t idx = 0, num_distinct = 0;
   
    while (idx != input.size()) {
        num_distinct++;
        
        size_t next_idx = idx + 1;
        
        while (next_idx < input.size() && input[idx] == input[next_idx]) {
            next_idx++;
        }
        
        idx = next_idx;
    }

    cout << num_distinct << endl;

    return 0;
}
