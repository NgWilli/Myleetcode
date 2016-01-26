
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
    int myAtoi(string str) {
        long long result=0;
        int neg=false;
        int i=0;
            //while is ' ' jump
            while (str[i]==' ') {
                i++;
            }
            //illegal input
            char ch=str[i];
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            {
                return 0;
            }
            else
            {
                
                //if is neg
                if(str[i]=='-')
                {
                    neg=1;
                    i++;
                }
                else if(str[i]=='+')
                {
                    i++;
                }
                
                    while ((str[i] >= '0' && str[i] <= '9')) {
                        result=result*10+int(str[i]-'0');
                        //overflow check
                        
                        if(neg)
                        {
                            if(result*(-1)!=int(result*(-1)))
                            {
                            return INT_MIN;
                            }
                        }
                        else
                        {
                            if(result!=int(result))
                            {
                            return INT_MAX;
                            }
                        }
                        i++;
                    }
            }
        
        if(neg)
        {
            return result*(-1);
        
        }
        else
        {
            return result;
        }
        
    }
};
    
int main() {
   
    
    Solution temp;
    cout<< temp.myAtoi("  -3833e44")<<endl;
    
    return 0;
}