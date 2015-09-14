// g++ Contains\ Duplicate.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int i : nums) {
    	if (set.find(i) != set.end())	return true;
    	else set.insert(i);
    }
    return false;
}

int main () {
	int myints[] = {3, 30, 34, 5, 9};
	vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
	cout << containsDuplicate(v) << endl;
}