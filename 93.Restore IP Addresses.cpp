#include <iostream>
#include <vector>

using namespace std;

void dfs(string s, string current, vector<string>& ret, int pos) {
    /* Need to condition pos first */
    if (pos == 4 && s.empty())
        ret.push_back(current.substr(0, current.length() - 1));
    if (pos < 4) {
        for (int i = 1; i <= s.length() && i < 4; i++) {
            int number = stoi(s.substr(0, i));
            /* Deny "001" -> 1 */
            if ((number == 0 && i == 1) || (number > 0 && number < 256 && s[0] != '0'))
                dfs(s.substr(i), current + s.substr(0, i) + '.', ret, pos + 1);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    dfs(s, "", ret, 0);
    return ret;
}

int main() {
    // vector<string> r = restoreIpAddresses("25525511135");
    vector<string> r = restoreIpAddresses("010010");
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << ",";
    cout << endl;
}
