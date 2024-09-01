#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string DNA;
	cin >> DNA;
	
	int max_so_far = 0;
	for (int i = 0; i < DNA.size(); ++i) {
		int same_char = 1;
		while (i < DNA.size() - 1 && DNA[i] == DNA[i+1]) {
			same_char++;
			i++;
		}
		max_so_far = max(max_so_far, same_char);
	}

	cout << max_so_far << endl;
	return 0;
}
