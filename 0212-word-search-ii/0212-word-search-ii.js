/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */

const endWord = '*'

class Trie{
    constructor(words){
        this.root = {}
        this.isWord = false
        words.forEach(word => this.addWord(word))
    }
    
    addWord(word){
        let current = this.root
        
        for(const letter of word){
            if(!current[letter]){
                current[letter] = {}
            }
            current = current[letter]   
        }
        current.isWord = true
    }
    
}


var findWords = function(board, words) {
    const trie = new Trie(words)
    const result = new Set()
    
    const visited = new Set()
    
    const dfs = (i, j, node, subResult) => {
        //base cases: out of bounds, letter does not exist in next prefix
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || !node[board[i][j]] || visited.has(`${i} ${j}`)){
            return
        }
        
        visited.add(`${i} ${j}`)
        subResult += board[i][j]
        
        node = node[board[i][j]]
        
        if(node.isWord){
            result.add(subResult)    
        }
        
        dfs(i, j+1, node, subResult)
        dfs(i, j-1, node, subResult)
        dfs(i-1, j, node, subResult)
        dfs(i+1, j, node, subResult)
        
        
        visited.delete(`${i} ${j}`)
        
    }
    
    for(let i = 0; i < board.length; i++){
        for(let j = 0; j < board[0].length; j++){
            if(trie.root[board[i][j]]){
                dfs(i, j, trie.root, "")
            }
        }
    }
    
    
    return [...result]

};