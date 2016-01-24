
// original idea with time limit exceed
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
    int reverse(int x) {
        long long result=0;
        int temp=0;
        while(x!=0)
        {
            temp=x%10;
            result=result*10+temp;
            if(int(result)!=result)
            {
                return 0;
            }
            x/=10;
        }
        
        return result;
        
    }
};
    
int main() {
   
    
    Solution temp;
    cout<< temp.reverse(1534236469)<<endl;
    
    return 0;
}