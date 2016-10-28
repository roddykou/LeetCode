#include <iostream>
#include <vector>

using namespace std;

/*
定义dp[i]表示从i到end能取到的最大值，当我们在i处，有两种选择：

1.若取values[i]，对方可以取values[i+1] 或者values[i+1] + values[i+2]
当对方取values[i+1] 后 ，我们只能从 i+2 到end内取，我们所取得最大值是dp[i+2],  注意：对方所选取的结果一定是使得我们以后选取的值最小
当对方取values[i+1] + values[i+2]后，我们只能从i+3到end内取，我们所取得最大值是dp[i+3]。
此时：dp[i] = values[i] + min(dp[i+2],dp[i+3]) , 注意：对方所选取的结果一定是使得我们以后选取的值最小

2.若取values[i] + values[i+1],对方可取values[i+2] 或者values[i+2] + values[i+3]
当对方取values[i+2]后，我们只能从i+3到end内取，我们取得最大值是dp[i+3]
当对方取values[i+2]+values[i+3]后，我们只能从i+4到end内去，我们取得最大值是dp[i+4]
此时：dp[i] = values[i] + values[i+1]+min(dp[i+3],dp[i+4])

这里的取最小值和上面一样的意思，对方选取过之后的值一定是使得我们选取的值最小，对方不傻并且还很聪明
*/
bool firstWillWin(vector<int> &values) {
    int n = values.size();
    if (n < 3)  return true;
    
    vector<int> dp (n + 2, 0);
    dp[n - 1] = values[n - 1];
    dp[n - 2] = values[n - 2] + values[n - 1];
    for (int i = n - 3; i >= 0; i--)
        dp[i] = max(values[i] + min(dp[i + 2], dp[i + 3]),
                    values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]));
    
    int total = 0;
    for (int v : values)
        total += v;
    return dp[0] * 2 > total;
}

int main() {
	vector<int> v1 = {1, 2, 2};
	vector<int> v2 = {1, 2, 4};

	cout << firstWillWin(v1) << endl;
	cout << firstWillWin(v2) << endl;
}