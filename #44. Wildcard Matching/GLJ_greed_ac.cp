

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
    
    
        bool isMatch(const char *s, const char *p) {
            const char *presp = NULL, *press = NULL;    //previous starting comparison place after * in s and p.
            // flag means we fount "*"
            bool startFound = false;
            //if s is not end
            while (*s!='\0') {
                if (*p=='?') {
                    p++;
                    s++;
                }
                else if(*p=='*')
                {
                    startFound=true;
                    presp=++p;
                    press=s;
                }
                else
                {
                    if(*p==*s)
                        
                    {
                        p++;
                        s++;
                    }
                    else if(startFound==1)
                    {
                        p=presp;
                        s=(++press);
                    
                    }
                    else
                    {
                    
                        return false;
                    }
                    
                    
                }
                
                
            }
            
            
            while(*p == '*') ++p;
            return *p == '\0';
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