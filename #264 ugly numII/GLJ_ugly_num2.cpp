#include<iostream>  
#include <windows.h>
#include <WINDEF.H>
#include<vector>


using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
		vector<int> uglyNumSeries;
		int index2=0;
		int index3=0;
		int index5=0;
		uglyNumSeries.push_back(1);
		int uglyTemp;
		n--;
		while(n!=0)
		{
			uglyTemp=min(5*uglyNumSeries[index5],min(3*uglyNumSeries[index3],2*uglyNumSeries[index2]));
		    if(uglyTemp==2*uglyNumSeries[index2])
			{
			++index2;
			}
			 if(uglyTemp==3*uglyNumSeries[index3])
			{
			++index3;
			}
			  if(uglyTemp==5*uglyNumSeries[index5])
			{
			++index5;
			}
			  uglyNumSeries.push_back(uglyTemp);
		n--;
		}
		return uglyNumSeries.back();
		
		
    }
};