/*

Simple self-driving car: let a list of instructions is given(aaararaa) for every second,
calculate the destination of the car after car follows all instructions.
Here 'a' represents accelerate and 'r' represents reverse.  The car is only
running along a straight line started at origin = 0 and with velocity v=1.
After an instruction 'a', the car will double its velocity. After an instruction
'r', the car will reverse direction and reset its its speed to 1.

Follow up: given a destination(e.g., x= 5 or -5), generate a list of instructions
to make the car arrive at the given destination after following all instructions.
If there are more than one solution, return the one with minimal length.

*/

#include <iostream>
#include <vector>

using namespace std;

// return the final destination. 21:07 - 21:10
int driving(string instructions) {
	int v = 1, pos = 0;
	for (int i = 0; i < instructions.length(); i++) {
		if (instructions[i] == 'a') {
			pos += v;
			v *= 2;
		} else {
			v = v > 0 ? -1 : 1;
		}
		cout << pos << " ";
	}
	cout << endl;
	return pos;
}


int dfs(const int dest, int pos, int v, string& ret) {
	if (pos == dest)
		return 0;
	if (abs(pos) > 1)
		return -1;

	cout << "pos " << pos << " v " << v <<  " ret: " << ret << endl;
	int accSteps = dfs(dest, pos + v, 2 * v, ret);
	int revSteps = dfs(dest, pos, v > 0 ? -1 : 1, ret);

	if (accSteps == -1 && revSteps == -1)
		return -1;
	else if (accSteps == -1) {
		ret += "r";
		return revSteps + 1;
	} else if (revSteps == -1) {
		ret += "a";
		return accSteps + 1;
	} else {
		ret += accSteps < revSteps ? "a" : "r";
		return min(accSteps, revSteps) + 1;
		
	}

}

// 21:13 - 21:20
string getInstructions(const int dest) {
	string ret = "";
	dfs(dest, 0, 1, ret);
	return ret;
}


int main() {
	// string instructions = "aaararaa";
	// cout << driving(instructions) << endl;

	cout << getInstructions(1) << endl;
} 