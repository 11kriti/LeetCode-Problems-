
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        
        # Track the visited node.
        visited = set()

        # Go from one node (room) to another as much as possible.
        def dfs(node):
        	# We don't really need to return anything here, 
        	# since we just want to add the new node to the visited list in this function.
            
            if node in visited:
                return
            
            visited.add(node)
            
            for k in rooms[node]:
                dfs(k)
        
        dfs(0)

        # Return True if we visited all the rooms
        return len(visited) == len(rooms)