#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++) {  
            hashtable[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end() && it->second != i) {
                return {it->second, i};
            }
        }
        
        return {};
    }
};

int main(){
	int a[3] = {1,2,5};
	vector<int> nums(a,a+3);
	int b = 3;
	Solution1 solution1;
	Solution2 solution2;
	cout << "解法一：" << endl;
	for(int k : solution1.twoSum(nums,b)){
		cout << k << " ";
	}
	cout << endl << "解法二：" << endl;
	for(int k : solution2.twoSum(nums,b)){
			cout << k << " ";
		}
//	cout << solution.twoSum(nums,b);
} 
