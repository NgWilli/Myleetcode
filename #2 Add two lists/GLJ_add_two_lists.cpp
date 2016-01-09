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
	ListNode* reverseList(ListNode* l1)// reverse a list ,actually no use at all
	{
		ListNode*p,*c,*n;
		c=l1;
		p=NULL;
		n=l1->next;
		while (n)//if n is not NULL(tail)
		{
			c->next=p;
			p=c;
			c=n;
			n=n->next;
		}
		c->next=p;
		return c;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//to avoid empty input
		if(l1==NULL)
		{
			return reverseList(l2);

		}
		if(l2==NULL)
		{
			return reverseList(l1);
		}
		int carry=0;
		int temp=0;
		ListNode*head1=l1;
		ListNode*head2=l2;
		while (l1->next&&l2->next)
		{
			temp=(l1->val+l2->val+carry)%10;
			carry=(l1->val+l2->val+carry)/10;
			l1->val=temp;
			l1=l1->next;
			l2=l2->next;
		}
		if (l1->next==NULL&&l2->next==NULL)
		{
			temp=(l1->val+l2->val+carry)%10;
			carry=(l1->val+l2->val+carry)/10;
			l1->val=temp;
			
			if(carry==0)
			{
				return head1;

			}
			else{
				l1->next=new ListNode(1);
				return  head1;
			}
		}
		else if(l1->next==NULL)
		{
			l1->next=l2->next;
			temp=(l1->val+l2->val+carry)%10;
			carry=(l1->val+l2->val+carry)/10;
			l1->val=temp;
			l1=l1->next;
			while (1)
			{
				temp=(l1->val+carry)%10;
				carry=(l1->val+carry)/10;
				l1->val=temp;
				if(l1->next!=NULL)
				{
                 l1=l1->next;
				}
				else
				{
				break;
				}
				
			}
			if(carry==0)
			{
				return  head1;

			}
			else{
				l1->next=new ListNode(1);
				return head1;
			}

		}
		else
		{
			
			temp=(l1->val+l2->val+carry)%10;
			carry=(l1->val+l2->val+carry)/10;
			l1->val=temp;
			l1=l1->next;
			while (1)
			{
				temp=(l1->val+carry)%10;
				carry=(l1->val+carry)/10;
				l1->val=temp;
				if(l1->next!=NULL)
				{
					l1=l1->next;
				}
				else
				{
					break;
				}

			}
			if(carry==0)
			{
				return  head1;

			}
			else{
				l1->next=new ListNode(1);
				return  head1;
			}
		}

	}
	
};
int main()
{

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