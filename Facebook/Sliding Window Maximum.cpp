#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Data {
	int number;
	int index;
	Data(int n, int i) : number (n), index (i) {}
};

class SlidingWindowMax {
public:
	SlidingWindowMax (int s) : windowSize (s), count (0) {}
	void add(int n) {
		if (!window.empty() && window.front().index <= count - windowSize)
			window.pop_front();

		auto itr = window.begin();
		while (itr != window.end() && itr->number > n)
			itr++;
		window.erase(itr, window.end());

		Data data (n, count);
		window.push_back(data);
		count++;
	}

	int getMax() {
		return window.front().number;
	}

private:
	deque<Data> window;
	int windowSize;
	int count;
};

int main() {
	SlidingWindowMax window (3);
	window.add(1);
	cout << window.getMax() << endl;
	window.add(3);
	cout << window.getMax() << endl;
	window.add(-1);
	cout << window.getMax() << endl;
	window.add(-3);
	cout << window.getMax() << endl;
	window.add(5);
	cout << window.getMax() << endl;
	window.add(3);
	cout << window.getMax() << endl;
	window.add(6);
	cout << window.getMax() << endl;
	window.add(7);
	cout << window.getMax() << endl;
}