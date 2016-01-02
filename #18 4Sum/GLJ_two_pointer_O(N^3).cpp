#include<iostream>  
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

// sort+above&bottom indicator

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret;
		int len=nums.size();
		if(len<4)
		{
			return ret;
		}
		sort(nums.begin(),nums.end());
		for(int i=0;i<=len-4;i++)//FIRST 
		{

			for(int m=i+1;m<=len-3;m++)//SECOND
			{
				// first number : num[i]
				int j = m + 1;    // THIRD number
				int k = len - 1;    // FOURTH number
				while (j < k) {
					if (nums[m] + nums[j] + nums[k]+ nums[i] < target) {
						++j;
					} else if (nums[m] + nums[j] + nums[k]+nums[i] > target) {
					
						--k;
					} else {
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[m]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						ret.push_back(temp);
						++j;
						--k;
						// folowing 3 while can avoid the 
						while (j < k && nums[j] == nums[j - 1])
							++j;
						while (j < k && nums[k] == nums[k + 1])
							--k;
					}
				}
				while (m <len-3 && nums[m] == nums[m + 1])
				{
					++m;
				}
			}
			while(i<len-4 && nums[i]==nums[i+1])//no duplications
			{
				++i;
			}
			
		}
		return ret;
	}
};