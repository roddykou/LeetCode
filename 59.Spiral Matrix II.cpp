#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ret (n, vector<int> (n));
    int number = 1;
    for (int i = 0; i < n / 2; i++) {
		int step = n - 1 - 2 * i;
    	for (int j = i; j < n - 1 - i; j++) {
    		ret[i][j] = number;
    		ret[j][n - 1 - i] = number + step;				// 00->03  01->13  02->23
    		ret[n - 1 -i][n - 1 - j] = number + step * 2;	// 00->33  01->32  02->31
    		ret[n - 1 - j][i] = number + step * 3;
    		number++;
    	}
    	number += step * 3;
    }
	if (n % 2 == 1)
		ret[n/2][n/2] = number;    
    return ret;
}

int main() {
	int n = 5;
	vector<vector<int> > result = generateMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << ",";
		}
		cout << endl;
	}
}

/*
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]

 01 02 03 04
 12 13 14 05
 11 16 15 06
 10 09 08 07
*/