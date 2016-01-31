
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
    bool isNumber(string s) {
        enum InputType {
            INVALID, SPACE, SIGN, DOT, E, DIGIT, LEN
        };
        int trans[][LEN] = {
            {-1,  0,  1,  2, -1,  3},
            {-1, -1, -1,  2, -1,  3},
            {-1, -1, -1, -1, -1,  4},
            {-1,  5, -1,  4,  6,  3},
            {-1,  5, -1, -1,  6,  4},
            {-1,  5, -1, -1, -1, -1},
            {-1, -1,  7, -1, -1,  8},
            {-1, -1, -1, -1, -1,  8},
            {-1,  5, -1, -1, -1,  8}
        };
        int state = 0;
        int i=0;
        while (i<s.size()) {
            InputType input;
            if (isspace(s[i])) {
                input = SPACE;
            } else if (s[i] == '+' || s[i] == '-') {
                input = SIGN;
            } else if (s[i] == '.') {
                input = DOT;
            } else if (s[i] == 'e' || s[i] == 'E') {
                input = E;
            } else if (isdigit(s[i])) {
                input = DIGIT;
            } else {
                input = INVALID;
            }
            state = trans[state][input];
            if (state == -1) {
                return false;
            }
            i++;
        }
        return state == 3 || state == 4 || state == 5 || state == 8;
    }
};
    
int main() {
   
    
    Solution temp;
    cout<< temp.isNumber(" ")<<endl;
    
    return 0;
}