//
//  cargo_port.cpp
//  Algorithms_OJtasks
//
//  Created by 考拉 on 2023/10/26.
//

//
//  cargo_port.cpp
//  Algorithms_OJtasks
//
//  Created by 考拉 on 2023/10/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//int maxSimultaneousShips(vector<vector<int>>& loading_plan) {
//    map<int, int> mp; //
//    for (const vector<int>& ship : loading_plan) {
//        mp[ship[0]] +=1;
//        mp[ship[1]] -=1;
//    }
//
//    int maxships = 0;
//    int curships = 0;
//    int day = 0;
//    for(auto & item: mp){
//        curships += item.second;
//        if(curships > maxships) {
//            maxships = curships;
//            day = item.first;
//        }
//    }
//
//    return day;
//}
//
//int maxSimultaneousShips2(map<int, int> mp) {
//    int maxships = 0;
//    int curships = 0;
//    int day = 0;
//    for(auto & item: mp){
//        curships += item.second;
//        if(curships > maxships) {
//            maxships = curships;
//            day = item.first;
//        }
//    }
//
//    return day;
//}
//
//
//int maxSimultaneousShips3(vector<vector<int>>& loading_plan) {
//    auto loading_plan_end = vector<vector<int>>(loading_plan.begin(),loading_plan.end());
//    sort(loading_plan_end.begin(), loading_plan_end.end(), [&](const vector<int>& s1, const vector<int>& s2){
//        return s1[1] > s2[1];
//    });
//    int end_day = loading_plan_end[0][1];
//    vector<int> events(end_day + 1,0);
//    for (const vector<int>& ship : loading_plan) {
//        for(int i = ship[0]; i <= ship[1]; i++) {
//            events[i] += 1;
//        }
//    }
//    int maxPosition = max_element(events.begin(),events.end()) - events.begin();
//    return maxPosition;
//}

void updateSimultaneousShips(vector<int>& events, vector<int>ship) {
    for(int i = ship[0]; i <= ship[1]; i++) {
        events[i] -= 1;
    }
}

int minimalOpenDays2(vector<vector<int>>& loading_plan) {
    int minmal = 0;
    int num_ships = loading_plan.size();
    sort(loading_plan.begin(), loading_plan.end(), [&](const vector<int>& s1, const vector<int>& s2){
        return s1[0]<s2[0];
    });
    
    
    auto loading_plan_end = vector<vector<int>>(loading_plan.begin(),loading_plan.end());
    sort(loading_plan_end.begin(), loading_plan_end.end(), [&](const vector<int>& s1, const vector<int>& s2){
        return s1[1] > s2[1];
    });
    int end_day = loading_plan_end[0][1];
    vector<int> events(end_day + 1,0);
    for (const vector<int>& ship : loading_plan) {
        for(int i = ship[0]; i <= ship[1]; i++) {
            events[i] += 1;
        }
    }
    
    while (loading_plan.size() != 0) {
        int day = max_element(events.begin(),events.end()) - events.begin();
        for (auto it = loading_plan.begin(); it != loading_plan.end(); ) {
            if((*it)[0] < day && (*it)[1] > day) {
                (*it)[2] -=1;
                if((*it)[2] == 0) {
                    updateSimultaneousShips(events,(*it));
                    it = loading_plan.erase(it);
                }
                else {
                    events[day] -= 1;
                    it++;

                }
            }
            else if((*it)[0] == day) {
                (*it)[2] -=1;
                if((*it)[2] == 0) {
                    updateSimultaneousShips(events,(*it));
                    it = loading_plan.erase(it);
                   
                }
                else {
                    events[day] -= 1;
                    it++;
                }
            }
            else {
                it++;
            }
        }
        minmal +=1;
        
    }
    
    
    
    return  minmal;
}


int minimalOpenDays(vector<vector<int>>& loading_plan) {
    vector<int> running(10000 + 1, 0);

    sort(loading_plan.begin(), loading_plan.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    for (const vector<int>& task : loading_plan) {
        //仍需要工作的天数
        int needed_days = task[2] - count(running.begin() + task[0],
                                            running.begin() + task[1] + 1, 1);
        //贪心，从靠后的天数开始，可以最大化同时工作的船数
        for (int i = task[1]; needed_days > 0; --i) {
            if (!running[i]) {
              running[i] = 1;
              --needed_days;
                }
        }
    }
    int minimal = 0;
    for(int i = 0; i < running.size(); i++){
        minimal += running[i];
    }
    return minimal;


}




int main() {
    int n;
    cin >> n;
    vector<vector<int>> loading_plan(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        cin >> loading_plan[i][0] >> loading_plan[i][1] >> loading_plan[i][2];
    }
    cout<<minimalOpenDays(loading_plan)<<endl;

}
