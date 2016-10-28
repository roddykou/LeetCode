#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int fidnRandomIndex(vector<int>& v, int target) {
   int count = 0, ret = -1;
   for (int i = 0; i < v.size(); i++) {
      if (v[i] == target) {
         count++;
         if (rand() % count == 0) {
            ret = i;
         }
      }
   }
   return ret;
}

int main() {
   srand(time(nullptr));
   int a[] = {1, 2, 3, 3, 3};
   vector<int> v (a, a + sizeof a / sizeof a[0]);
   while (true) {
      cout << fidnRandomIndex(v, 3) << endl;
      sleep(1);
   }
}