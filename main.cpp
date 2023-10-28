//
//  main.cpp
//  Algorithms_OJtasks
//
//  Created by 考拉 on 2023/10/16.
//

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int isEven(int n) {
//    // if even
//    if (n % 2 == 0) {
//        return 1;
//    } //if odd
//    else {
//        return 0;
//    }
//}
//
//int calScore(int n) {
//    int score = 0;
//    while (n != 1) {
//        int num_type = isEven(n);
//        if (num_type) { // even
//            n /= 2;
//        }
//        else { // odd
//            n = 3*n + 1;
//        }
//        score += 1;
//    }
//    return score;
//}
//
//void swap(int& n, int& m) {
//    int tmp = n;
//    n = m;
//    m = tmp;
//}
//
//int partitionArray(vector<int> &arr, int left, int right) {
//    int pivot = arr[left];
//    int i = left;
//    int j = right;
//    while (i != j) {
//        while (i < j && arr[j] >= pivot) {
//            j--;
//        }
//        while (i < j && arr[i] <= pivot) {
//            i++;
//        }
//        swap(arr[i], arr[j]);
//    }
//    // place pivot
//    swap(arr[left],arr[i]);
//    return  i;
//}
//
//int getIthScores(int i, vector<int> &arr,int left, int right) {
//    int confirmed_pos = 0;
//    while (1) {
//        confirmed_pos = partitionArray(arr, left, right);
//        if (confirmed_pos == i) {
//            break;
//        }
//        else if (confirmed_pos > i) {
//            right = confirmed_pos - 1;
//
//        }
//        else {
//            left = confirmed_pos + 1;
//        }
//    }
//    return arr[confirmed_pos]; //scores
//
//}
//
//
//int resortArray(int x, int y, int i) {
//    int size = y - x + 1;
//    vector<int> scoreArray(size);
//    // calculate the scores
//    for (int i=0; i < size; i++) {
//        scoreArray[i] = calScore(x+i);
//    }
//
//    vector<int> originalArray = scoreArray;
//    int ith_score = getIthScores(i-1, scoreArray, 0, y-x);
//    // find ith index
//    vector<int>::iterator it = find(originalArray.begin(), originalArray.end(), ith_score );
//    int ith_num = distance(originalArray.begin(), it) + x;
//    return ith_num;
//
//}
//
//
//int main(){
//
//
//    int x, y, i;
//    cin >> x >> y >> i;
//
////    int i;
////    vector<int> input;
////
////    while (cin >> i)
////    {
////        input.push_back(i);
////        while (cin.peek() == ' ')
////        {
////            cin.get();
////        }
////        if (cin.peek() == '\n')
////        {
////            break;
////        }
////    }
//    cout<< resortArray(x, y, i)<<endl;
//
//
//}
//



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to calculate the score of an integer n
int calculateScore(int n) {
    int score = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        score++;
    }
    return score;
}

// Custom comparator for sorting integers based on their scores and absolute values
bool customCompare(int a, int b) {
    int scoreA = calculateScore(a);
    int scoreB = calculateScore(b);

    // Sort by score in ascending order
    if (scoreA != scoreB) {
        return scoreA < scoreB;
    }

    // If scores are equal, sort by absolute value in ascending order
    return abs(a) < abs(b);
}

int main() {
    int x, y, i;
    std::cin >> x >> y >> i;

    std::vector<std::pair<int, int>> numbers; // Pair of (number, score)

    for (int num = x; num <= y; num++) {
        int score = calculateScore(num);
        numbers.push_back(std::make_pair(num, score));
    }

    // Sort by score and absolute value
    std::sort(numbers.begin(), numbers.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return abs(a.first) < abs(b.first);
    });

    // Output the i-th number
    cout << numbers[i - 1].first << std::endl;

    return 0;
}
