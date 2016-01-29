

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
    bool isMatch(char* s ,char*p)
    {
        //if p=null and s is null retutn true
        if(*p==0)
            return *s==0;
        //if *(p+1)!='*'
        if (*(p+1)!='*') {
            if (*s!=0 &&(*p==*s||*p=='.')) {
                return isMatch(s+1, p+1);
            }
            else  return  false;
        }
        else
        {
            //*(P+1)is"*" then jump all the same chars as *s
            while (*s!=0 && (*p==*s||*p=='.')) {
                if (isMatch(s, p+2)) {
                    return true;
                }
                s++;
            }
            
            if (isMatch(s, p+2)) {
                return true;
            }
            else
                return false;
            
        }
    }
    
    
    
    
    bool isMatch(string s1, string p1) {
        char* s=(char*)s1.data();
        char* p=(char*)p1.data();
        return isMatch(s, p);
        
        
    }
};
int main() {
   
    
    Solution temp;
    cout<< temp.isMatch("a",
                        ".*..a*")<<endl;
    
    return 0;
}