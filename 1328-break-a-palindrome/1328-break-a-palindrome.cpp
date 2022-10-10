class Solution {
public:
   bool isPalindrome(string &str){
        int i=0;
        int j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        int flag=0;
        string ans(n,'z');
        
        for(int i=0;i<n;i++){
            char x=palindrome[i];
            for(int j=0;j<26;j++){
                palindrome[i]=j+97;
                if(isPalindrome(palindrome)==0 && (palindrome <ans)){
                    flag=1;
                    ans=palindrome;
                }
            }
            palindrome[i]=x;
        }
        
        if(flag==0)
            return "";
        return ans;
        
        
    }
};