//
//  Rigorous_Subsequences.cpp
//  Algorithms_OJtasks
//
//  Created by 考拉 on 2023/10/24.
//

#include <iostream>
#include <vector>
using namespace std;


const int MOD = 100000007;

long long countRigorousSubsequences(const vector<int>& X) {
    int n = X.size();
    long long dp[3] = {0}; // dp[i] represents the number of subsequences ending in digit i

    for (int i = 0; i < n; i++) {
        if (X[i] == 2) {
            // If X[i] is 2, update only the count of 2s
            dp[2] = (2 * dp[2] + 1) % MOD;
        } else if (X[i] == 1) {
            // If X[i] is 1, update the count of 1s
            dp[1] = (2 * dp[1] + dp[2] ) % MOD ;
            
        } else if (X[i] == 0) {
            // If X[i] is 0
            dp[0] = (2 * dp[0] + dp[1]) % MOD ;
        }
    }

    return dp[0];
}

int main() {

    int i;
    vector<int> input;

    while (cin >> i)
    {
        input.push_back(i);
        while (cin.peek() == ' ')
        {
            cin.get();
        }
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    
    long long result = countRigorousSubsequences(input);
    cout << result << endl;

    return 0;
}
