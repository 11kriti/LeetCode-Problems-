class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
         auto w1b = word1.begin(), w1e = word1.end();
        auto w2b = word2.begin(), w2e = word2.end();
        auto c1b = w1b->begin(),  c1e = w1b->end();
        auto c2b = w2b->begin(),  c2e = w2b->end();
        
        // [2] iteration proceeds while characters are equal
        while (*c1b == *c2b)
        {   
            // [3] for both words, move to the next character 
            //     in each of currently iterated items
            ++c1b; ++c2b;
            
            // [4] if we are at the end of an item, move to the next item 
            if (c1b == c1e) ++w1b;
            if (c2b == c2e) ++w2b;
            
            // [5] if next item is the end of any of words,
            //     it's time break out of the cycle
            if (w1b == w1e || w2b == w2e) break;
            
            // [6] if change of item happened, update iterators
            if (c1b == c1e) { c1b = w1b->begin(); c1e = w1b->end(); }
            if (c2b == c2e) { c2b = w2b->begin(); c2e = w2b->end(); }
        }
        
        // [7] check that we broke out of the cycle exactly 
        //     after processing all characters in all items
        return (w1b == w1e && w2b == w2e);
    }
};