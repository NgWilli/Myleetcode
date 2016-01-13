#include"stdafx.h"
#include<iostream>  
#include<vector>
#include<algorithm>
#include <string> 
#include <sstream>
#include <set>
using namespace std;
class Solution {
private:
	double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
		if (m < n) {
			swap(n, m);
			swap(A, B);
		}
		if (n == 0)
			return A[k - 1];
		if (k == 1)
			return min(A[0], B[0]);

		int pb = min(k / 2, n), pa = k - pb;
		if (A[pa - 1] > B[pb - 1])
			return findKthSortedArrays(A, m, B + pb, n - pb, k - pb);
		else if (A[pa - 1] < B[pb - 1])
			return findKthSortedArrays(A + pa, m - pa, B, n, k - pa);
		else
			return A[pa - 1];
	}
	/*let's say if len=m+n then k equals to m+n/2
	so the problem equals to find the k num in a and b
	ifa[k/2]<b[k/2] then do not concern about the first k/2 elements of a
	*/
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	
		int m=nums1.size();
		int n=nums2.size();
		int A[1000]={0};
		int B[1000]={0};
		int length=m+n;
		for (int temp=0;temp<m;temp++)
		{
			A[temp]=nums1[temp];
		}
		for (int temp=0;temp<n;temp++)
		{
			B[temp]=nums2[temp];
		}
		if ((n + m)&1)
			return findKthSortedArrays(A, m, B, n, (n + m) / 2 + 1);
		else
			return (findKthSortedArrays(A, m, B, n, (n + m) / 2 + 1) +
			findKthSortedArrays(A, m, B, n, (n + m) / 2)) / 2.0;
	}

};
int main()
{
	vector<int> a;
	a.push_back(1);
a.push_back(2);
a.push_back(3);
a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	vector<int> b;
	b.push_back(4);
	Solution temp;
	cout<<temp.findMedianSortedArrays(a,b)<<endl;
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