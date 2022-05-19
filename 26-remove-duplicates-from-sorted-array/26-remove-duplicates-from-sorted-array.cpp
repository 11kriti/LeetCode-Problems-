class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//here i use the TWO pointer apporach
int i =0;
for(int j =1 ; j<nums.size() ;j++)
{
if(nums[j] != nums[i])
{i++;
nums[i]=nums[j];
}

}
return i+1;
 //time complexity - O(n)       
    }
};