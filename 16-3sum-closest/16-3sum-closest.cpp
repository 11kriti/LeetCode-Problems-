class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX;
        int minDiff = INT_MAX;
        for (int i = 0; i < n-1; i++) {
            int left = i+1;
            int right = n-1;
            int x = nums[i];
            while (left < right) {
                int sum = x + nums[left] + nums[right];
                int diff = abs(target - sum);
                minDiff = min(minDiff, diff);
                bool thisBest = minDiff == diff;
				// Closest is either the closest we had before, or this sum, if we just chose the best one
				// Multiplication used to avoid branch caused by an if { } statement
                closest = closest * !thisBest + sum * thisBest;
                if (sum == target) {
                    return target;
                }
                left += sum < target;
                right -= sum > target;
    
            }
        }
        return closest;
        
    }
};