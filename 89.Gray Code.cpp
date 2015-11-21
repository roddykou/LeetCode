#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) {
    vector<int> ret;
    ret.push_back(0);
    for (int i = 0; i < n; i++)
        for (int j = ret.size(); j > 0; j--)
            ret.push_back(ret[j - 1] + (1 << i));
    return ret;
}

int main() {

}
