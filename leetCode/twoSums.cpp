#include<bits/stdc++.h>
using namespace std;

//Brute Force solution
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>answer;

        for(int i = 0; i < nums.size(); i++){
            int aux = nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(aux + nums[j] == target && i!=j){
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        } 
        return answer;
        
    }
};
*/

//Optimal Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> answer;

        for(int i = 0; i < nums.size(); i++){
            int aux = target - nums[i];

            if(answer.find(aux) != answer.end()){
                return {answer[aux], i};
            }

            answer[nums[i]] = i;
        } 
        return {};
        
    }
};

int main(void){
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    
    vector<int> result = sol.twoSum(nums, target);
}