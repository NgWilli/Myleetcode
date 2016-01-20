

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;//the return one
        int i;//for loop pointer
        int id;//the max position of string now
        int mx;//the max range of id;
        vector<int> pArray(1000);
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
                pArray.push_back(1);
            }
            //hit the simple jump rule
            else
                if(i<id+mx-1)
                {
                    cout<<"strat a jump"<<endl;
                    
                    //then id(i)=id(2*id-i)
                    //
                    //jump a lot of state
                    int ranger1=min((id+mx-i),pArray[2*id-i]);
                    //cout<<"pArray[2*id-i]= "<<pArray[2*id-i]<<endl;
                    // cout<<"now i is "<<i<<" ,and now the center is "<<id<<" ,with mx of "<<mx<<" and range1 ori is "<<ranger1<<endl;
                    while((i+ranger1)<result.size()&&(i-ranger1)>=0)
                    {
                        //if left and right are different break
                        if(result[i+ranger1]!=result[i-ranger1])
                        {
                            //update p array
                            pArray[i]=ranger1;
                            break;
                        }
                        else
                        {
                            //cout<<"now comparing "<<result[i+ranger]<<" and "<<result[i-ranger]<<endl;
                            //update range and carry on
                            if((ranger1+1)>=mx)
                            {
                                mx=ranger1+1;
                                id=i;
                            }
                            ranger1++;
                        }
                        
                    }
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
                            //update p array
                            pArray[i]=ranger;
                            break;
                        }
                        else
                        {
                            //cout<<"now comparing "<<result[i+ranger]<<" and "<<result[i-ranger]<<endl;
                            //update range and carry on
                            if((ranger+1)>=mx)
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
        // cout<<"finalTempsize "<<finalTemp.size()<<endl;
        for(int temp=0;temp!=finalTemp.size();temp++)
        {
            if(finalTemp[temp]!='#')
            {
                finalResult+=finalTemp[temp];
            }
            
        }
        // cout<<"id mx"<<id<<" "<<mx<<endl;
        // cout<<finalTemp<<endl;
        // cout<<finalResult<<endl;
        //  cout<<"size "<<finalResult.size()<<endl;
        // cout<<"central id"<<id<<endl;
        //cout<<"str length "<<mx-1<<endl;
        return finalResult;
    }
    
};

int main() {
    string s="abacaaaaanabanaaaacb";
    Solution temp;
    temp.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    //int a=temp.lengthOfLongestSubstring(s);
   // cout<<a<<endl;
    
    
    return 0;
}