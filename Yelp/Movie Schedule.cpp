#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(vector<unordered_set<int> >& schedules, int currentMovie,
		 vector<int>& ret, unordered_set<int>& timeTaken) {
	if (currentMovie == schedules.size() - 1) {
		for (int possibleTime : schedules[currentMovie]) {
			if (timeTaken.find(possibleTime) == timeTaken.end()) {
				ret.push_back(possibleTime);
				return true;
			}
		}
	} else {
		for (int possibleTime : schedules[currentMovie]) {
			if (timeTaken.find(possibleTime) == timeTaken.end()) {
				ret.push_back(possibleTime);
				timeTaken.insert(possibleTime);
				if (dfs(schedules, currentMovie + 1, ret, timeTaken))
					return true;
				ret.pop_back();
				timeTaken.erase(possibleTime);
			}
		}
	}
	return false;
}

vector<int> schedule(vector<unordered_set<int> >& schedules) {
	vector<int> ret;
	unordered_set<int> timeTaken;
	dfs(schedules, 0, ret, timeTaken);
	return ret;
}

int main() {
	// 电影A: 14, 15, 16, 17
	// 电影B: 14, 15, 16
	// 电影C: 14, 15
	// 电影D: 14, 15, 17

	unordered_set<int> scheduleA;
	unordered_set<int> scheduleB;
	unordered_set<int> scheduleC;
	unordered_set<int> scheduleD;

	scheduleA.insert(0);
	scheduleA.insert(1);
	scheduleA.insert(2);
	scheduleA.insert(3);

	scheduleB.insert(0);
	scheduleB.insert(1);
	scheduleB.insert(2);

	scheduleC.insert(0);
	scheduleC.insert(1);

	scheduleD.insert(0);
	scheduleD.insert(1);
	scheduleD.insert(3);

	vector<unordered_set<int> > schedules;
	schedules.push_back(scheduleA);
	schedules.push_back(scheduleB);
	schedules.push_back(scheduleC);
	schedules.push_back(scheduleD);

	vector<int> finalSchedule = schedule(schedules);
	for (int airTime : finalSchedule)
		cout << airTime << " ";
	cout << endl;
}