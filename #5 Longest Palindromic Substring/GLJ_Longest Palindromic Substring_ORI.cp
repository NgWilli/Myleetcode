

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;//the return one
        int i;//for loop pointer
        int id;//the max position of string now
        int mx;//the max range of id;
        //string decorate
        for (int temp=0; temp<s.size(); temp++) {
            result=result+'#';
            result=result+s[temp];
        }
        result=result+'#';
        //to find the longest repeat string
        for ( i=0; i<result.size(); i++) {
          //if is the first one  init it.
            if(i==0)
            {
                id=0;
                mx=1;
            }
            else
            {
                int ranger=1;
                //while not out of range
                while((i+ranger)<result.size()&&(i-ranger)>=0)
                {
                    //if left and right are different break
                if(result[i+ranger]!=result[i-ranger])
                {
                    break;
                }
                    else
                    {
                        //cout<<"now comparing "<<result[i+ranger]<<" and "<<result[i-ranger]<<endl;
                        //update range and carry on
                        if((ranger+1)>mx)
                        {
                            mx=ranger+1;
                            id=i;
                        }
                        ranger++;
                    }
                
                }
            }
        }
        //output setup
        string finalTemp=result.substr(id-(mx-1),mx*2-1);
        string finalResult;
      //  cout<<"finalTempsize "<<finalTemp.size()<<endl;
        for(int temp=0;temp!=finalTemp.size();temp++)
        {
        if(finalTemp[temp]!='#')
        {
            finalResult+=finalTemp[temp];
        }
        }
        cout<<finalResult<<endl;
      //  cout<<"size "<<finalResult.size()<<endl;
       // cout<<"central id"<<id<<endl;
        //cout<<"str length "<<mx-1<<endl;
        
        
        return finalResult;
    }
};

int main() {
    string s="abb";
    Solution temp;
    temp.longestPalindrome("abb");
    //int a=temp.lengthOfLongestSubstring(s);
   // cout<<a<<endl;
    
    
    return 0;
}