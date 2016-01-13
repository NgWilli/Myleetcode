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
		nums1.insert(nums1.end(),nums2.begin(), nums2.end());
		sort(nums1.begin(),nums1.end());

		return;
	}
};