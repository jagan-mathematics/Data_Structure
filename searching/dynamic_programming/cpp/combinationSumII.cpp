#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());  // Sort to handle duplicates easily
    vector<vector<vector<int>>> dp(target + 1);  // DP table

    dp[0] = {{}};

    for (int candidate : candidates) {
        for (int t = target; t >= candidate; --t) {
            for (auto& combination : dp[t - candidate]) {
                combination.push_back(candidate);
                if (find(dp[t].begin(), dp[t].end(), combination) == dp[t].end()) {
                    dp[t].push_back(combination);
                }
                combination.pop_back();
            }
        }
    }

    return dp[target];
}


void printArray(vector<vector<int>> &arr) {
    for (vector<int> & i : arr) {
        for (int &j: i) {
                printf("%d  ", j);
        }
        printf("\n");
    }
}



int main(){
    vector<int> dp = {{10,4,2,7,6,2,5 }};
    vector<vector<int>> value = combinationSum2(dp, 8);
    printArray(value);
    cout << "done" ;
}
