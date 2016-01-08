#include"stdafx.h"
#include<iostream>  
#include<vector>
#include<algorithm>
#include <string> 
#include <sstream>
using namespace std;
class Solution {
public:
	string multiplyBin(string a, char b)
	{
		if (a=="0"||b=='0')// no use to multiply
		{
			return "0";
		}
		int indexA=a.size()-1;
		int num=0;
		int bit=0;
		int carry=0;
		string c;
	   
	   while (indexA>=0)
	   {
		   	num= (a[indexA]-'0')*(b-'0')+carry;
			bit=num%10;
			carry=num/10;
            c=(char)(bit + '0') + c;
            indexA--;
	   }
	   if (carry > 0)
		   c = (char)(carry + '0') + c;
	   return c;
	}
	string addBinary(string a, string b) {
		int indexA=a.size()-1;
		int indexB=b.size()-1;
		int num=0;
		int bit=0;
		int carry=0;
		string c;
		while(indexA >=0&& indexB>=0)// A&B BOTH HAS VALUE
		{
			num= (a[indexA]-'0')+(b[indexB]-'0')+carry;
			bit=num%10;
			carry=num/10;
			c=(char)(bit + '0') + c;
			indexA--;
			indexB--;
		}

		while(indexA >= 0)
		{
			int num = a[indexA ] - '0' + carry;
			carry = num / 10;
			num %= 10;

			c = (char)(num + '0') + c;

			indexA--;
		}

		while(indexB >= 0)
		{
			int num = b[indexB] - '0' + carry;
			carry = num / 10;
			num %= 10;

			c = (char)(num + '0') + c;

			indexB--;
		}

		if (carry > 0)
			c = (char)(carry + '0') + c;

		return c;
	}
	string multiply(string num1, string num2) {
		if (num1=="0"||num2=="0")// no use to multiply
		{
			return "0";
		}
		int index1=num1.size()-1;
		string temp="";
		string sum="";
		while (index1>=0)
		{
			temp=multiplyBin(num2,num1[index1]);
			for(int i=num1.size()-index1-1;i>0;i--)
			{
			temp=temp.append("0");
			}
			sum=addBinary(temp,sum);
			index1--;
		}
		return sum;


	}
};
int main()
{
	string a="111";
	string b="99";
	Solution temp;
	cout<<temp.multiply(a,b)<<endl;
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