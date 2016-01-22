class Solution {  
public:  
    string convert(string s, int nRows) {  
          
          //debug input
        if (nRows <= 1 || s.length() == 0)  
           return s;  
  
        string res = "";  
        int len = s.length();  
        for (int i = 0; i < len && i < nRows; ++i)  
        {  
            int indx = i;  
            res += s[indx];  
  
            for (int k = 1; indx < len; ++k)  
            {  
                //first and last line
                if (i == 0 || i == nRows - 1)  
                {  
                    indx += 2 * nRows - 2;  
                }  
               //line in the middle use the odd and even
                else  
                {  
                    if (k & 0x1)  //odd 
                        indx += 2 * (nRows - 1 - i);  
                    else indx += 2 * i;  
                }  
  
                
                if (indx < len)  
                {  
                    res += s[indx];  
                }     
            }  
        }  
        return res;  
    }  
}; 