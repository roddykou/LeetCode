#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> ret (1, 1), tmp (1, 1);
    for (int i = 1; i <= rowIndex; i++) {
        tmp.push_back(1);
        int j = 1;
        while (j <= i / 2) {
            tmp[j] += ret[j - 1];
            j++;
        }
        j = i - 1;
        while (j > i / 2) {
            tmp[j] = tmp[i - j];
            j--;
        }
        ret = tmp;
    }
    return ret;
}

int main () {
}
