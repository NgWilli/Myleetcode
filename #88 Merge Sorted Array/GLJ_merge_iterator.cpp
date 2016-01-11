class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		while(nums1.size()!=m)
		{
			nums1.erase(nums1.end()-1);
		}
		while(nums2.size()!=n)
		{
			nums2.erase(nums2.end()-1);
		}
		if(m==0)
		{   

			nums1.insert(nums1.end(),nums2.begin(), nums2.end());
			return;
		}
		if (n==0)
		{
			return;
			//return nums1
		}
		vector<int>::iterator n1=nums1.begin();
		vector<int>::iterator n2=nums2.begin();
		while (n1!=nums1.end()&& n2!=nums2.end())
		{
			if (*n2<*n1)//if is head
			{
				n1=nums1.insert(n1,*n2);
				//cout<<nums1[0]<<endl;
				n2++;
			}
			else
			{
				n1++;
			}
		}
		if(n1==nums1.end())
		{
			nums1.insert(nums1.end(),n2,nums2.end());
		}

		return;
	}
};