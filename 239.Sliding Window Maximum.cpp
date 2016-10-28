#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Window position                Max     i        window
// ---------------               -----   ---      --------
//                                 -      0           0
//                                 -      1           1
// [1  3  -1] -3  5  3  6  7       3      2           1, 2
//  1 [3  -1  -3] 5  3  6  7       3      3           1, 2, 3
//  1  3 [-1  -3  5] 3  6  7       5      4           4
//  1  3  -1 [-3  5  3] 6  7       5      5           4, 5
//  1  3  -1  -3 [5  3  6] 7       6      6           6
//  1  3  -1  -3  5 [3  6  7]      7      7           7

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   // store the indice of the number and the numbers in this window is alwasy
   // in descending order.
   deque<int> window;
   vector<int> ret;

   for (int i = 0; i < nums.size(); i++) {
      if (!window.empty() && window.front() <= i - k)
         window.pop_front();

      // pop all numbers in the window that are smaller than nums[i]
      auto itr = window.begin();
      while (itr != window.end() && nums[*itr] > nums[i])
         itr++;
      window.erase(itr, window.end());
      window.push_back(i);

      // insert the maximum into result set
      if (i - k >= -1)
         ret.push_back(nums[window.front()]);
   }

   return ret;
}

int main() {

}
