#include <iostream>
#include <vector>

using namespace std;

void dfs(const string& nums, int index, int preNum, int preSum, char preOp, int target, string& curRet, vector<string>& ret) {
   if (index == nums.size()) {
      if (preSum == target) {
         ret.push_back(curRet);
      }
      return;
   }

   if (start == 0) {

   }
}

vector<string> addOperators(string num, int target) {
   vector<string> ret;
   string curRet = num[0];
   dfs(num, 1, num[0], num[0], '+', target, curRet, ret);
   return ret;
}


// "123", 6 -> ["1+2+3", "1*2*3"]
// "232", 8 -> ["2*3+2", "2+3*2"]
// "105", 5 -> ["1*0+5","10-5"]
// "00", 0 -> ["0+0", "0-0", "0*0"]
// "3456237490", 9191 -> []
int main() {
   vector<string> ret = addOperators("123", 6);
   for (int i = 0; i < ret.size(); i++)
   cout << ret[i] << endl;
}
