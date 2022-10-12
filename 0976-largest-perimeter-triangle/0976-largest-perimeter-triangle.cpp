class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
sort(nums.begin(),nums.end());
    //any tringle sum of smaller two side greater than 3rd side...so we check that condition, a+b>c where a<b<c
    int maxPerimeter=0;
    
    for(int i=0;i<=nums.size()-3;i++){
        //check the triangle valid condition
        if(nums[i]+nums[i+1]>nums[i+2]){
            maxPerimeter=max(maxPerimeter,nums[i]+nums[i+1]+nums[i+2]); //find max
        }
    }
    
    return maxPerimeter; //return the result
}
        
    
};