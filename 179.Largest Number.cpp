#include <iostream>
#include <vector>

using namespace std;

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    string ans;
    for(int i=0; i<nums.size(); i++){
        ans += to_string(nums[i]);
    }
    /*
    Input:
    [0,0]
    Output:
    "00"
    Expected:
    "0"
    */
    return ans[0]=='0' ? "0" : ans;
}

int main() {

}
