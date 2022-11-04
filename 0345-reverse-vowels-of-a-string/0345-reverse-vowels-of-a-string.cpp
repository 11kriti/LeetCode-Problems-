class Solution 
{
public:
    string reverseVowels(string s)
    {
        set<char> vwls = {'a','e','i','o','u','A','E','I','O','U'};
        for (int l = 0, r = s.size()-1; l < r; )
        {
            while (l < r && !vwls.count(s[l])) ++l;
            while (l < r && !vwls.count(s[r])) --r;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};