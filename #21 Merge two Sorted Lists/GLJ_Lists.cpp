class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//prevent the input {}{}, {}{0}, {0}{}
		if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		ListNode *dummyHead=NULL;
		ListNode *tail=NULL;
		while(l1!=NULL&&l2!=NULL)
		{
			if(dummyHead==NULL)//IT'S HEAD
			{
				if(l1->val<l2->val)//不需要判断相等的情况 反正后面还会插入的
				{
				dummyHead=l1;
				tail=l1;
				l1=l1->next;
				}
				else
				{
				dummyHead=l2;
				tail=l2;
				l2=l2->next;
				}
			}
			else//ORI NODE
			{
				if(l1->val<l2->val)
				{
					tail->next=l1;
					tail=tail->next;
					l1=l1->next;
				
				}
				else
				{
					tail->next=l2;
					tail=tail->next;
					l2=l2->next;
				}
			}
		}
		if(l1!=NULL)
		{
			tail->next=l1;
		}
		else if(l2!=NULL)
		{
			tail->next=l2;
		}
		else
		{
		tail->next=NULL;
		}

		return dummyHead;
		}
};