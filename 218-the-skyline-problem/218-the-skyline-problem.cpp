class Solution {
public:
    
        std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
	std::vector<std::vector<int>> height, result;
	std::multiset<int> multiset_;
	int prev = 0, curr = 0;
	for (std::vector<int>& a : buildings) { 
		height.push_back({a[0], -a[2]}); 
		height.push_back({a[1],  a[2]}); 
	}
	std::sort(height.begin(), height.end()); 
	multiset_.insert(0);
	for (std::vector<int>& a : height) {
		if (a.back() < 0) {
			multiset_.insert(-a.back());
		}
		else multiset_.erase(multiset_.find(a.back()));
		curr = *multiset_.rbegin();
		if (curr != prev) { 
			result.push_back({a.front(), curr}); 
			prev = curr; 
		} 
	} 
	return result;
}
    
};