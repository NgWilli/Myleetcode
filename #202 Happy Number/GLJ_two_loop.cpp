#include<iostream>  
#include<cmath>
#include<vector>
#include<set>

using namespace std;
int calculateSquare(int n)
{
	double sum=0;
	while(n!=0)
	{
	sum=sum+pow((double)(n%10),(double)2);
	n=n/10;
	}
	return sum;

}
// sort+above&bottom indicator
class Solution {
public:
    bool isHappy(int n) {
		set<int> iset;
        if(n<0)// illegal input
		{
		return false;
		}
		else//legal input
		{
		while(n<INT_MAX)//OR WILL EXCEED
		{
			if(n==1)
			{
			return true;
			}
			if(iset.find(n)!=iset.end())//got ya
			{
			return false;//then will be a loop no happy
			}
			else
			{
				iset.insert(n);
				n=calculateSquare(n);
			}
		}
		return false;
		
		}
    }
};