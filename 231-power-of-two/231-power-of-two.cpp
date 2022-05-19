class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i;
         int ans ;
        for(i=0;i<=30;i++)
        {

        ans = pow( 2 , i);
        
  if  (  ans == n)
  {
   return true;
  }
        }


return false;

    }
    
};