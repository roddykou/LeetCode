#include <string>

using namespace std;

string convertToTitle(int n) {
    string ret;
    while (n > 0) {
        char c = 'A' + --n % 26;
        ret = c + ret;
        n /= 26;
    }
    return ret;
}

int main() {

}
