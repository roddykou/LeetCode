#include <iostream>
#include <vector>

using namespace std;

string getBtwSlashes(string &path, int &i) {
    string ret;
    int j = i + 1;
    while (j < path.length() && path[j] != '/') {
        j++;
    }
    ret = path.substr(i + 1, j - i - 1);
    i = j;
    return ret;
}

string simplifyPath(string path) {
    vector<string> s;
    int i = 0;
    while (i < path.length()) {
        string tmp = getBtwSlashes(path, i);
        if (tmp.empty() || tmp == ".")    continue;
        if (tmp == "..") {
            if (!s.empty()) s.pop_back();
        } else {
            s.push_back(tmp);
        }
    }
    string ret;
    for(auto str : s) ret += "/"+str;
    return ret.empty() ? "/" : ret;
}

int main() {

}
