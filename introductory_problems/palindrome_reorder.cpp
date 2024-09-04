#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string make_palindrome(string & s) {
    int charCount[26] = {0};
    bool isOddLength = s.size() & 1;

    for (int i = 0; i < s.size(); ++i) {
        charCount[s[i] - 'A']++;
    }

    int numEven = 0, numOdd = 0;
    int oddIdx;
    for (int i = 0; i < 26; ++i) {
        if (charCount[i] & 1) {
            numOdd++;
            oddIdx = i;
        } else {
            numEven++;
        }
    }

    if((isOddLength && numOdd != 1) || (!isOddLength && numOdd != 0)) {
            return "NO SOLUTION";
    }
        
    string ans = "";
    for (int i = 0; i < 26; ++i) {
        for (int count = 0; count < charCount[i]/2; count++) {
            ans += 'A' + i;
        }
    }

    if (isOddLength) ans += 'A' + oddIdx;
    int curIdx = (isOddLength) ? ans.size() - 2 : ans.size() - 1;
    for (int i = curIdx; i >= 0; --i) {
        ans += ans[i];
    }
    return ans;

}

int main() {
    string input;
    cin >> input;
    
    cout << make_palindrome(input) << endl;

    return 0;
}
