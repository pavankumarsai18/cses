#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> allPossibilities(string S) {
    if (S == "") {
        return {};
    } else if (S.size() == 1) {
        return {S};    
    } else if (S.size() == 2) {
        if (S[0] == S[1]) return {S};

        string rev_S(S.rbegin(), S.rend());
        if (S < rev_S) return {S, rev_S};
        return {rev_S, S};
    }
    
    unordered_set<string> seen_strings;
    vector<string> ans;
    for (size_t idx = 0; idx < S.size(); ++idx) {
        string removed_idx = S.substr(0, idx);
        
        if (idx != S.size() - 1) {
            removed_idx += S.substr(idx+1);
        }

        for (auto & str : allPossibilities(removed_idx)) {
            for (size_t i = 0; i < str.size(); ++i) {
                string new_string = str.substr(0, i) + S[idx] + str.substr(i);
                if (seen_strings.find(new_string) != seen_strings.end()) {
                    continue;
                }

                ans.push_back(new_string);
                seen_strings.insert(new_string);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    string input;
    cin >> input;

    vector<string> ans = allPossibilities(input);
    cout << ans.size() << endl;
    for (auto & str: ans) {
        cout << str << endl;
    }
	return 0;
}

