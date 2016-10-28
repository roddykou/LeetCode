#include <iostream>
#include <unordered_set>

using namespace std;


int getHappiness(int n) {
   int ret = 0;
   while(n > 0) {
      ret += pow(n % 10, 2);
      n = n / 10;
   }
   return ret;
}

bool isHappy(int n) {
   if (n <= 0) return false;
   if (n == 1) return true;

   unordered_set<int> met;
   met.insert(n);

   while(true) {
      n = getHappiness(n);
      if (met.find(n) != met.end())
         return false;
      if (n == 1)
         return true;
      met.insert(n);
   }
   return false;
}

int main() {
   
}