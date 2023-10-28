//
//  gas_station_planning.cpp
//  Algorithms_OJtasks
//
//  Created by 考拉 on 2023/10/24.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minSumOfDistances(vector<int> &villages, int n) {
    
    int v_num = villages.size();
    if (v_num == 0 || n == 0 || n >= v_num) return 0;
    
    //only one gas station from villiages[i] to villages[j]
    vector<vector<int>> oneStationDis(v_num, vector<int>(v_num,0));
    for(int i = 0; i < v_num; i++) {
        for(int j = i + 1 ;j < v_num; j++) {
            int middle = villages[(i + j)/2];
            for(int k = i;k <= j;k++) { // all distances
//                oneStationDis[i][j] += abs(villages[k]-middle);
            }
        }
    }
    //initalize 1 gas station
    vector<vector<int>> dp(v_num, vector<int>(n, 0));
    for(int i = 0; i < v_num; i++) {
        dp[i][0] = oneStationDis[0][i];
    }
    //dp
    for (int i = 1; i < n; i++) { //gas stations
        for(int j = i; j < v_num; j++) { //villages
            dp[j][i] = 10000000;//set a large number
            for(int k = i - 1; k < j; k++) {
                dp[j][i] = min(dp[j][i], dp[k][i - 1] + oneStationDis[k + 1][j]);
            }
        }
    }
    return dp[v_num - 1][n - 1];
    
}


int main() {
    int x = 0;
    vector<int> villages;
    while(cin >> x){
        villages.push_back(x);
        if (cin.get() == '\n')
            break;
    }
    int n = 0;
    cin >> n; //numbers of gas stations
    //sort the coordinates of villages
    sort(villages.begin(), villages.end());
    cout<<minSumOfDistances(villages, n)<<endl;

    return 0;
}
