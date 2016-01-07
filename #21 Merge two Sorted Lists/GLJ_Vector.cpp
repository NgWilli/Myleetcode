#include"stdafx.h"
#include<iostream>  
#include<vector>
#include<algorithm>

using namespace std;
/**
* Definition for singly-linked list.
*
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//put two lists into vector to sort
		if(l1!=NULL &&l2==NULL)
		{
			return l1;

		}
		if(l2!=NULL&& l1==NULL)
		{

			return l2;
		}
		vector<int> list1;
		vector<int> list2;
		ListNode* dummyHead=NULL;
		ListNode* tail=NULL;
		int isFirst=0;
		while(l1!=NULL)
		{
			list1.push_back(l1->val);
			l1=l1->next;
		}
		while(l2!=NULL)
		{
			list2.push_back(l2->val);
			l2=l2->next;
		}
		//if two lists are not empty
		while(list1.empty()!=1  && list2.empty()!=1)
		{
			//compare the first element of the list

			if(list1[0]<list2[0])
			{
				if(isFirst==0)//the first element
				{
					isFirst++;
					ListNode *temp=new ListNode(list1[0]);
					dummyHead=temp;
					tail=temp;
					list1.erase(list1.begin());
				}
				else//not the first element
				{
					ListNode *temp=new ListNode(list1[0]);
					tail->next=temp;
					tail=tail->next;
					list1.erase(list1.begin());
				}
			}
			else if(list2[0]<list1[0])
			{
				if(isFirst==0)//the first element
				{
					isFirst++;
					ListNode *temp=new ListNode(list2[0]);
					dummyHead=temp;
					tail=temp;
					list2.erase(list2.begin());
				}
				else//not the first element
				{
					ListNode *temp=new ListNode(list2[0]);
					tail->next=temp;
					tail=tail->next;
					list2.erase(list2.begin());
				}
			}
			else
			{
				if(isFirst==0)//the first element
				{
					isFirst++;
					ListNode *temp=new ListNode(list2[0]);
					dummyHead=temp;
					tail=temp;
					tail->next=new ListNode(list1[0]);
					tail=tail->next;
					list1.erase(list1.begin());
					list2.erase(list2.begin());
				}
				else//not the first element
				{
					ListNode *temp1=new ListNode(list2[0]);
					tail->next=temp1;
					tail=tail->next;
					list2.erase(list2.begin());
					ListNode *temp2=new ListNode(list1[0]);
					tail->next=temp2;
					tail=tail->next;
					list1.erase(list1.begin());
				}
			}

		}
		if(list1.empty()==1&& list2.empty()!=1)//list1 is empty and list 2 is not
		{
			while(!list2.empty())
			{
				ListNode *temp1=new ListNode(list2[0]);
				tail->next=temp1;
				tail=tail->next;
				list2.erase(list2.begin());
			}
		}
		else if(list2.empty()==1&& list1.empty()!=1)//list2 is empty and list 1 is not
		{
			while(!list1.empty())
			{
				ListNode *temp1=new ListNode(list1[0]);
				tail->next=temp1;
				tail=tail->next;
				list1.erase(list1.begin());
			}
		}


		return dummyHead;
	}

};
int main()
{
	Solution temp;
	ListNode * dummyHead;
	dummyHead=temp.mergeTwoLists(NULL,new ListNode(1));
	while(dummyHead!=NULL)
	{
		cout<<dummyHead->val<<" ";
		dummyHead=dummyHead->next;
	}

	return 0;

}