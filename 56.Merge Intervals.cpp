#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool comp(const Interval& a, const Interval& b){
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ret;
    if(intervals.empty())   return ret;
    sort(intervals.begin(), intervals.end(), comp);
    ret.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
        if (intervals[i].start > ret.back().end)
            ret.push_back(intervals[i]);
        else
            ret.back().end = max(ret.back().end, intervals[i].end);

    return ret;
}

int main () {
    // Given [1,3],[2,6],[8,10],[15,18],
    // return [1,6],[8,10],[15,18]
    vector<Interval> v;
    v.push_back(Interval (1, 3));
    v.push_back(Interval (2, 6));
    v.push_back(Interval (8, 10));
    v.push_back(Interval (15, 18));

    vector<Interval> result = merge(v);
    for (int i = 0; i < result.size(); i++)
        cout << "[" << result[i].start << "," << result[i].end << "], ";
    cout << endl;
}
