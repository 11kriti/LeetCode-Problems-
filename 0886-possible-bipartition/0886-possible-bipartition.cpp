class Solution {
public:
    const int LIKE = 1;
    const int DISLIKE = -1;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for(vector<int> person : dislikes) {
            graph[person[0]].push_back(person[1]);
            graph[person[1]].push_back(person[0]);
        }
        vector<int> likes(n + 1, 0);
        for(int person = 1; person <= n; person++) {
            if(likes[person]) continue;
            likes[person] = LIKE;
            if(hasMatchingLike(person, graph, likes)) 
                return false;
        }
        return true;
    }
    bool hasMatchingLike(int person, vector<vector<int>> &graph, vector<int> &likes) {
        for(int neighbor_person : graph[person]) {
            if(!likes[neighbor_person]) {
                likes[neighbor_person] = likes[person] == LIKE ? DISLIKE : LIKE;
                if(hasMatchingLike(neighbor_person, graph, likes)) 
                    return true;
            } else if(likes[neighbor_person] == likes[person]) 
                return true;
        }
        return false;
    }
};