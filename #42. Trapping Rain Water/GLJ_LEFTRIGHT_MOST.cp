

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& A) {
        
        int n=A.size();
        
        // Note: The Solution object is instantiated only once.
        if(A.size()==0 || n<1)return 0;
        
        int maxheight = 0;
        vector<int> leftMostHeight(n);
        for(int i =0; i<n;i++)
        {
            leftMostHeight[i]=maxheight;
            maxheight = maxheight > A[i] ? maxheight : A[i];
        }
        
        maxheight = 0;
        vector<int> rightMostHeight(n);
        for(int i =n-1;i>=0;i--)
        {
            rightMostHeight[i] = maxheight;
            maxheight = maxheight > A[i] ? maxheight : A[i];
        }
        
        int water = 0;
        for(int i =0; i < n; i++)
        {
            int high = min(leftMostHeight[i],rightMostHeight[i])-A[i];
            if(high>0)
                water += high;
        }
        return water;
    }
};
int main() {
   
    vector<int> height={1,2,3,4,5};
    Solution temp;
   // cout<< temp.trap(height)<<endl;
    
    return 0;
}