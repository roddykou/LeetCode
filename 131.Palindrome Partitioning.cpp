#include <iostream>
#include <vector>

using namespace std;

bool isPalin(const string& s, int start, int len) {
    for (int end = start + len - 1; start < end; start++, end--) {
        if (s[start] != s[end])
            return false;
    }
    return true;
}

void dfs(vector<vector<string> >& ret, vector<string>& current, const string& s, int start) {
    for (int len = 1; len <= s.length() - start; len++) {
        if (isPalin(s, start, len)) {
            current.push_back(s.substr(start, len));
            if (start + len == s.length())
                ret.push_back(current);
            else
                dfs(ret, current, s, start + len);
            current.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > ret;
    vector<string> current;
    dfs(ret, current, s, 0);
    return ret;
}

int main() {
    
}
