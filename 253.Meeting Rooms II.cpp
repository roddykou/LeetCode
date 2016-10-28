struct Interval {
    int start, end;
    Interval(int s, int e) : start (s), end (e) {}  
};

int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> starts, ends;
    int res = 0, endpos = 0;
    for (auto a : intervals) {
        starts.push_back(a.start);
        ends.push_back(a.end);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 0; i < intervals.size(); ++i) {
        if (starts[i] < ends[endpos]) ++res;
        else ++endpos;
    }
    return res;
}

int main() {

}