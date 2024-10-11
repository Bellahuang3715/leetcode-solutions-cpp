class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
//         // no valid transformation
//         if (wordSet.find(endWord) != wordSet.end())
//         {
//             return 0;
//         }
        
//         queue<pair<string, int>> q;
//         q.push({beginWord, 1});
//         unordered_set<string> visited;
//         visited.insert(beginWord);
        
//         // bfs
//         while (!q.empty())
//         {
//             string word = q.front().first;
//             int length = q.front().second;
//             q.pop();
            
//             for (int i = 0; i < word.size(); i++)
//             {
//                 char originalChar = word[i];
//                 for (char c = 'a'; c <= 'z'; c++)
//                 {
//                     word[i] = c; // Try changing the i-th character to any letter 'a' to 'z'

//                     // If this transformation matches endWord, return the current length + 1
//                     if (word == endWord) {
//                         return length + 1;
//                     }

//                     // If this transformation is in the wordSet and hasn't been visited, add to queue
//                     if (wordSet.find(word) != wordSet.end() && visited.find(word) == visited.end()) {
//                         q.push({word, length + 1});
//                         visited.insert(word); // Mark this word as visited
//                     }
//                 }
//                 word[i] = originalChar; // Restore the original word
//             }
//         }
//         return 0;
        // Step 1: Convert wordList into a set for O(1) lookup
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    // If endWord is not in wordList, there is no valid transformation
    if (wordSet.find(endWord) == wordSet.end()) {
        return 0;
    }

    // Step 2: Initialize BFS
    queue<pair<string, int>> q; // Pair: (current word, transformation length)
    q.push({beginWord, 1}); // Start with the beginWord, with length 1
    unordered_set<string> visited; // Keep track of visited words
    visited.insert(beginWord);

    // Step 3: BFS loop
    while (!q.empty()) {
        string word = q.front().first;
        int length = q.front().second;
        q.pop();

        // Generate all possible one-letter transformations of the current word
        for (int i = 0; i < word.size(); i++) {
            char originalChar = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c; // Try changing the i-th character to any letter 'a' to 'z'
                
                // If this transformation matches endWord, return the current length + 1
                if (word == endWord) {
                    return length + 1;
                }
                
                // If this transformation is in the wordSet and hasn't been visited, add to queue
                if (wordSet.find(word) != wordSet.end() && visited.find(word) == visited.end()) {
                    q.push({word, length + 1});
                    visited.insert(word); // Mark this word as visited
                }
            }
            word[i] = originalChar; // Restore the original word
        }
    }

    // If no transformation sequence leads to endWord, return 0
    return 0;
    }
};