

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
    
    bool isMatch(const char *s, const char *p)
    {
        if (s == NULL || p == NULL) return false;
        if (*p == '\0') return *s == '\0';
        
        if (*p == '*')
        {
            while (*p == '*') ++p;
            
            while (*s != '\0')
            {
                if (isMatch(s, p)) return true;
                ++s;
            }
            
            return isMatch(s, p);
        }
        else if ((*s != '\0' && *p == '?') || *p == *s)
        {
            return isMatch(s + 1, p + 1);
        }
        
        return false;
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