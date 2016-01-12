#include"stdafx.h"
#include<iostream>  
#include<vector>
#include<algorithm>
#include <string> 
#include <sstream>
#include <set>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// LOOP FOR j 
		//if find repeat
		//1. delete the character above the repeat one from exist array and pointer i is pointing on  the next characher after the repeat
		//update the maxlen
		//
		int maxLen=0;
		int arrayLooper=0; int deleteLooper=0;
//TO SAVE EXISTS NUM
		int exists[256]={false};//ASCII has 256 char from 0 to 255
		int maxSize=s.size();
		while (arrayLooper<maxSize)
		{
			if (exists[s[arrayLooper]])//find the repeat
			{   //update maxLen
				maxLen=max(arrayLooper-deleteLooper,maxLen);
				//delete the character above the repeat one from exist array 
				while(s[deleteLooper]!=s[arrayLooper])
				{
					exists[s[deleteLooper]]=false;
					deleteLooper++;
				}

				deleteLooper++;
				arrayLooper++;
			}
			else//not found repeat
			{
			exists[s[arrayLooper]]=true;
			arrayLooper++;
			}
		}
		//if arrayLooper reach the tail and find no repeat
		//updete maxLen the last time
		maxLen=max(arrayLooper-deleteLooper,maxLen);
		return maxLen;
	}
};
int main()
{
	string a="aaa";
	Solution temp;
	cout<<temp.lengthOfLongestSubstring(a)<<endl;
	/*
	ListNode*a=new ListNode(1);
	//ListNode*b=new ListNode(1);
	//ListNode*c=new ListNode(2);
	//ListNode*g=new ListNode(3);
	//a->next=b;
	//b->next=c;
	//c->next=g;
	ListNode*d=new ListNode(9);
	ListNode*e=new ListNode(9);
	//ListNode*f=new ListNode(2);
	d->next=e;
	//e->next=f;
	Solution temp;
	ListNode* head=temp.addTwoNumbers(a,d);
	//a=temp.reverseList(a);
	//ListNode* head=a;
	while(head)
	{
	cout<<head->val<<" ";
	head=head->next;
	}

	/*
	Solution temp;
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(2);
	nums2.push_back(1);
	temp.addTwoNumbers(nums1,1,nums2,1);
	for(vector<int>::iterator n1=nums1.begin();n1<nums1.end();n1++)
	{
	cout<<*n1<<" ";
	}
	*/
	return 0;

}