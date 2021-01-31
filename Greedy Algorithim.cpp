#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() == 0)
            return 0;
        bool ch[128];
        int str=0;
        int pt=0;
        int res=0;
        memset(ch, false, sizeof(ch));
        ch[s[0]] = true;
        while (pt + 1 < s.length())
        {
            while (pt + 1 < s.length() && !ch[s[pt+1]])
            {
                pt++;
                ch[s[pt]] = true;
            }
            res = max(res, pt - str);
            ch[s[str]] = false;
            str++;
            
        }
        return res+1;
    }
};
void main()
{
    Solution H;
    cout<<H.lengthOfLongestSubstring("123456789012345");
}
