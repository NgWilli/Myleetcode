

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp(s);
        set<char> hashSet;
        double currentLen=0;
        double maxLen=0;
        hashSet.clear();
        if(s.empty()==1)
        {
            return 0;
        }
        if(s.size()==1)
        {
            return 1;
        }
        hashSet.insert(s.c_str()[0]);
        currentLen++;

        for(int i=1;i<s.size();i++)
        {
            
            if(hashSet.find(s.c_str()[i])!=hashSet.end())//match means repeat
            {
                
               // cout<<"new loop "<<endl;
               // cout<<"find repeat "<<s.c_str()[i]<<endl;
                if(currentLen>maxLen)
                {
                    maxLen=currentLen;
                 }
                int j=0;
                while (temp.c_str()[j]!=s.c_str()[i]) {
                    hashSet.erase(temp.c_str()[j]);//这一块数组应该是动态变化的
                    //cout<<" erase "<<temp.c_str()[j]<<endl;
                    currentLen--;
                    j++;
                }
                //cout<<j<<endl;
                hashSet.erase(temp.c_str()[j]);
               // cout<<" erase "<<temp.c_str()[j]<<endl;
                hashSet.insert(s.c_str()[i]);
                //cout<<"current want to delete is "<<s.c_str()[i]<<" and its position in temp is "<<temp.find(s[i])<<endl;
                temp=temp.substr(temp.find(s[i])+1,temp.size());
                
               // cout<<"delete complete now temp is "<<temp<<endl;
                
                
            }
            else{
                hashSet.insert(s.c_str()[i]);
                currentLen++;
                if(currentLen>maxLen)
                {
                    maxLen=currentLen;
                }
            }
        
        }
        return maxLen;
    }
    
};

int main() {
    string s="bpfbhmipx";
    Solution temp;
    int a=temp.lengthOfLongestSubstring(s);
    cout<<a<<endl;
    
    
    return 0;
}