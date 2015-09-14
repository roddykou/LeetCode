#include <iostream>
#include <vector>

using namespace std;

string convert1(string s, int numRows) {
    if (numRows == 1)   return s;

    vector<string> rows (numRows, "");
    int row = 0;
    bool downward = true;
    for (int i = 0; i < s.length(); i++) {
        rows[row] += s[i];

        if (row == 0)
            downward = true;
        else if (row == numRows - 1)
            downward = false;

        if (downward)
            row++;
        else
            row--;
    }

    string ret = "";
    for (int i = 0; i < rows.size(); i++)
        ret.append(rows[i]);
    return ret;
}

string convert(string s, int numRows) {
    if (numRows == 1)   return s;
    int len = s.length();
    string ret (len, 'X');
    int maxStep = 2 * (numRows - 1), downStep = maxStep, upStep = 0;
    int i = 0, j = 0;
    bool downward = true;
    while (j < len && j < maxStep) {
        int k = j;
        while (k < len && i < len) {
            ret[i] = s[k];
            if (downStep == 0 || upStep == 0)
                k += maxStep;
            else if (downward)
                k += downStep;
            else if (!downward)
                k += upStep;
            downward = !downward;
            i++;
        }
        j++;
        downStep -= 2;
        upStep += 2;
        downward = true;
    }
    return ret;
}
int main () {
    cout << convert("0123456789abcdefg", 2) << endl;
}
