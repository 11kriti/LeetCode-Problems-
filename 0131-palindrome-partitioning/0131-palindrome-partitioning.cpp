
class Solution {

    bool ispalindrome(string s){
        for(int i=0;i<s.size()/2;++i){
            if(s[i]==s[s.size()-1-i]){
                continue;
            }
            return false;
        }
        return true;
    }
public: void dfs(vector<vector<string>>&ans,vector<string>&temp,string s){
   if(s.size()==0){  //base condistion when there is no string left
       ans.push_back(temp);
       return;
   }
    for(int i=0;i<s.size();++i){
        string check=s.substr(0,i+1);
        if(ispalindrome(check)){
            temp.push_back(check);
            dfs(ans,temp,s.substr(i+1));
            temp.pop_back();

        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        dfs(ans,temp,s);
        return ans;
    }
};