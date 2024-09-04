#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    int n, sum, num;
    unordered_map<int, int> numCount;
    cin >> n >> sum;
    
    for (int i = 1; i <= n; ++i) {
        cin >> num;
    
        int other_num = sum - num;

        if (numCount.find(other_num) != numCount.end()) {
            cout << numCount[other_num] << " " << i << endl;
            return 0;
        }

        numCount[num] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
