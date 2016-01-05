#include<iostream>  
#include <windows.h>
#include <WINDEF.H>
#include<vector>


using namespace std;
class Solution {
public:
     int nthSuperUglyNumber(int n, vector<int>& primes) {
		 //input debug
		 if(n>1000000|| n<=0|| primes.size()>100|| primes.size()<0)
		 {
		 return 0;
		 }
		 if(n==1)
		 {
			 return 1;

		 }
		vector<int> uglyNumSeries;
		vector<int> indexPrimes(primes.size(),0);
		uglyNumSeries.push_back(1);
		int minForNow;
		n--;
		vector<int> minIndex;
		while(n!=0)
		{
			minForNow=INT_MAX;
			for(int l=0;l<primes.size();l++)//find the min index and record the index that equals
			{
				//find the min Index
				if(minForNow>primes[l]*uglyNumSeries[indexPrimes[l]])
				{
				//cout<<"uglyNumSeries[indexPrimes[l]] "<<uglyNumSeries[indexPrimes[l]]<<endl;
			//	cout<<"indexPrimes[l] "<<indexPrimes[l]<<endl;
				//cout<<"primes[l] "<<primes[l]<<endl;
				minForNow=primes[l]*uglyNumSeries[indexPrimes[l]];
				minIndex.clear();
				minIndex.push_back(l);
				}
				else if(minForNow==primes[l]*uglyNumSeries[indexPrimes[l]])
				{
				minIndex.push_back(l);
				}
             
			}
			for(int j=0;j<minIndex.size();j++)
			{
			//	cout<<"minIndex[j] "<<minIndex[j]<<endl;
			indexPrimes[minIndex[j]]++;
			}
			uglyNumSeries.push_back(minForNow);
		n--;
		}
		return uglyNumSeries.back();
		
		
    }
};