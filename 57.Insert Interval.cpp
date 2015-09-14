#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret;
    int i = 0;
    while (i < intervals.size() && newInterval.end >= intervals[i].start) {
        if (newInterval.start > intervals[i].end) {
            ret.push_back(intervals[i]);
        } else {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        i++;
    }
    ret.push_back(newInterval);
    while (i < intervals.size())
        ret.push_back(intervals[i++]);
    return ret;
}

int main () {
    // [[2,4],[5,7],[8,10],[11,13]], [3,8]
    vector<Interval> v;
    v.push_back(Interval (2,4));
    v.push_back(Interval (5,7));
    v.push_back(Interval (8,10));
    v.push_back(Interval (11,13));
    vector<Interval> r = insert(v, Interval(3,8));
    for (int i = 0; i < r.size(); i++)
        cout << "[" << r[i].start << ", " << r[i].end << "], ";
    cout << endl;
}
