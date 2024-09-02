#include <iostream>
#include <vector>
#include <utility>
using namespace std;
// TODO
bool next_move_in_board(int r, int c, vector<int>& move, int n) {
	int dr = move[0], dc = move[1];
	return (1 <= (r+dr) && (r+dr) <= n) && (1 <= (c+dc) && (c+dc) <= n);
}

long long find_two_knights(long long n) {
	if (n == 1) return 0;
	long long ans = 0;
	vector<vector<int>> knight_moves = {{2, 1}, {-2, -1}, {2, -1}, {-2, 1},
					     {1, 2}, {-1, -2}, {-1, 2}, {1, -2}};
	
	long long n_sq = n;
	n_sq *= n;
 
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= n; ++c) {
			int num_attack_sq = 0;
			for (auto & move: knight_moves) {
				if (next_move_in_board(r, c, move, n)) {
					num_attack_sq++;	
				}				
			}
			
			ans += (n_sq - num_attack_sq);
		}
	}

	ans <<= 1; // ans *= 2
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << find_two_knights(i) << endl;
	}	
	return 0;
}
