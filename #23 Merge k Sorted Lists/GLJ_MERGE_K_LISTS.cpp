#include<iostream>  
#include<vector>
#include<algorithm>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 */

struct CompareListElement {  
    bool operator ()(const ListNode* a, const ListNode* b) const  
    {  
        return (a->val > b->val);  //NOTE1： 用大于符号建立小堆  
    }  
};  
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heapVec;
		ListNode* dummyHead=NULL;  
		ListNode* front=dummyHead;   
        ListNode* tail = dummyHead; 
		int initFlag=0;
		if(lists.empty()&&(lists.size()==1&&lists[0]==NULL))
		{
		return NULL;
		}
		
		for(vector<ListNode*>::iterator it=lists.begin();it!=lists.end();it++)
		{
			if((*it)!=NULL)//copy lists into heapVec to make the heap
			{
			heapVec.push_back(*it);
			}
		}
		make_heap(heapVec.begin(),heapVec.end(),CompareListElement());//make heap
		while(heapVec.empty()!=1)
		{
			if(initFlag==0)
			{
			dummyHead=heapVec.front();
			tail=heapVec.front();
			initFlag++;
			}
			else{
			tail->next=heapVec.front();//put the front of heap into output queue
			tail=tail->next;
			}
			//pop back the first queue and remake the queue  then pushback it
		//to pop back 
		//1. pop the heap
			//2. pop the element from the vec
			//3. rebuild the heap  and push back
		pop_heap(heapVec.begin(),heapVec.end(),CompareListElement());
		heapVec.pop_back();
		if(tail->next!=NULL)
		{
			heapVec.push_back(tail->next);//repush the fixed list into vec
			push_heap(heapVec.begin(),heapVec.end(),CompareListElement());//rebuild heap
		
		}		
		}
		
		return dummyHead;
    }
};