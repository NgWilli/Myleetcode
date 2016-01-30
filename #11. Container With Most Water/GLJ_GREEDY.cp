

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
//greedy solution
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = height.size() - 1;
        
        int ret = 0;
        while(i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            ret = max(ret, area);
            
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        
        return ret;
    }
};
int main() {
   
    vector<int> height={1,2,3,4,5};
    Solution temp;
    cout<< temp.maxArea(height)<<endl;
    
    return 0;
}