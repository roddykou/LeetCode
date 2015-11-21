#include <string>
#include <cmath>

using namespace std;

int titleToNumber(string s) {
    int ret = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        ret += (s[i] - 'A' + 1) * pow(26, s.length() - i - 1);
    }
    return ret;
}

int main() {

}
