class Solution {
public:
    bool isPalindrome(int x) {
     
  long  int original = x;
   long  int ans = 0;
    while(x > 0)
    {
long  int  digit = x % 10;
  ans = ( ans * 10) + digit ;
  x = x / 10;
    }
if ( original == ans )
{
return true ;
}
else
{
return false;
}
        
    }
};