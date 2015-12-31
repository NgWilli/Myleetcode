#include<iostream>  
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class DataBlock
{
public:
	int originData;
	int originIndex;
	DataBlock()
	{
		originData=0;
	    originIndex=0;
	
	}
	~DataBlock()
	{
	
	
	}

};
//solution 1  sort+above&bottom indicator
class Solution {
public:
	Solution()
	{

	}
	~Solution()
	{


	}
	vector <int> twoSum(vector<int>& nums, int target) {
		//build target-num[i] a hash map
		map<int,DataBlock> hashmap;
		int index=1;
		for(vector<int>::iterator temp = nums.begin();temp!=nums.end();temp++)//O(n)
		{
			hashmap[target-*temp].originData=*temp;
			hashmap[target-*temp].originIndex=index;
			index++;
		}
		for(vector<int>::iterator temp = nums.begin();temp!=nums.end();temp++)
		{
			
			map<int,DataBlock>::iterator it= hashmap.find(*temp);

			if(it == hashmap.end())//cannot find the value
			{

				//do nothing

			}

			else {// search success return
				if((&(*temp)-&nums[0]+1)!=hashmap[*temp].originIndex)
			   {
				   //cout<<&(*temp)-&nums[0]+1<<endl;
				   //cout<< hashmap[*temp].originIndex<<endl;
				vector<int> returnVec;
				//cout<<hashmap[*temp]<<" "<<&(*find(nums.begin(), nums.end(),hashmap[*temp]))-&nums[0]+1<<endl;
				//cout<<*temp<<" "<<&(*temp)-&nums[0]+1<<endl;
                returnVec.push_back(hashmap[*temp].originIndex);// index of the second num
				returnVec.push_back(&(*temp)-&nums[0]+1);
				sort(returnVec.begin(), returnVec.end());  
				return returnVec;
				}
			}
			


		}

		vector<int> returnVecNo;
		return  returnVecNo;
	}

};