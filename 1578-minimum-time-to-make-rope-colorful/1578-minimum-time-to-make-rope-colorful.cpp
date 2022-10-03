class Solution {
public:

    int minCost(string s, vector<int>& t) {
     
     if(s.size()==1) return 0;
        
     int total=t[0],maxi=t[0],ans=0;
        
      for(int i=1;i<s.size();i++)
        {  if(s[i]!=s[i-1])
             { ans+=total-maxi;
               maxi=t[i];total=t[i];
             } 
           else
           { maxi=max(maxi,t[i]);
             total+=t[i];
           }
        }
        
        ans+=total-maxi; // for last similar group 
        return ans;
    }
};