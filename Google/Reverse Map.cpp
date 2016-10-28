#include <iostream>
#include <vector>

using namespace std;

void reverseMap(vector<string>& strings, vector<int>& mapping) {
	for (int i = 0; i < mapping.size(); i++) {
		if (mapping[i] == -1)	continue;

		int originalIdx = i, reversedIdx = -1;
		while (mapping[originalIdx] != -1) {
			reversedIdx = mapping[originalIdx];
			mapping[originalIdx] = -1;
			if (reversedIdx == i)	break;
			swap(strings[originalIdx], strings[reversedIdx]);
			originalIdx = reversedIdx;
		}
	}
}

int main() {
	vector<string> strings = {"cat", "mouse", "dog", "rabbit", "tiger", "lion"};
	vector<int> mapping = {2, 0, 1, 3, 5, 4};
	reverseMap(strings, mapping);
	for (string s : strings)
		cout << s << ", ";
	cout << endl;
}