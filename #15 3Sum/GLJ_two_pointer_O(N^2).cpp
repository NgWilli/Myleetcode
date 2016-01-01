#include<iostream>  
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

// sort+above&bottom indicator
class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &num) {
		vector<vector<int>> vecReturn;
		sort(num.begin(), num.end());
		int target=0;
		int size=num.size();
		if(size<=2)
		{
		
		return vecReturn;
		}
		for(int i=0;i<=size-3;i++)
		{
			int headP=i+1;
			int bottomP=size-1;
			while(headP<bottomP)
			{
				if(num[headP]+num[bottomP]+num[i]<0)
				{
					headP++;
				}
				else if(num[headP]+num[bottomP]+num[i]>0)
				{
					bottomP--;
				}
				else//if everything fits,record this dataset
				{
					int a[3]={ num[i], num[headP], num[bottomP]};
					vecReturn.push_back(vector<int>(a,a+3));
					headP++;
					bottomP--;
					//to avoid duplications
					while(headP<bottomP&& num[headP-1]==num[headP])//headP  duplicates
					{
						headP++;
					}
					while(headP<bottomP&& num[bottomP+1]==num[bottomP])//headP  duplicates
					{
						bottomP--;
					}
					while (i <= size - 3 && num[i] == num[i + 1])//
						i++;
				}
			}
		}
		return vecReturn;
	}
};