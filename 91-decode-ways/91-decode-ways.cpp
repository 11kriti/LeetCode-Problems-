class Solution {
public:
     int dp[1001];
    
    //i is the iterator ove the string and s is the string itself
    int ways(int i, string s)
    {
        //BASE CASES
        if(i>=s.size())
            return 1;
        else if(s[i]=='0')
            return 0;
        else if(i==s.size()-1)
            return 1;
        else if(dp[i]!=-1)
            return dp[i];
        
        //MAIN LOGIC
        //when its 1 then no problem whatever the adjoining number is but when its 2 then the adjoining must be between 0-6 and 48 is ASCII value for 0 ans 54 is for 6
        else if(s[i]=='1' || s[i]=='2' && s[i+1]>=48 && s[i+1]<=54)
            //i+1 when we are taking only single element +2 when we are taking in pair
            return dp[i]=ways(i+1,s)+ways(i+2,s);
        else
            //else we have some other number then we just increment the iterator and store the answer in dp array for that particular number
            return dp[i]=ways(i+1,s);
    }
    
    
    int numDecodings(string s) 
    {
        //setting the values in DP as -1
        memset (dp,-1,sizeof(dp));
        return ways(0,s);
    }
};