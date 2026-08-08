class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> ans(m);  
        vector<int> last(m, -1);  

        // Step 1: Precompute last occurrence of each word2[j] in word1
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) last[j--] = i;
            --i;
        }

        // Step 2: Greedy forward scan
        bool canSkip = true;  
        j = 0;
        for (i = 0; i < n; ++i) {
            if (j == m) break;
            if (word1[i] == word2[j]) {
                ans[j++] = i;
            } 
            else if (canSkip && (j == m - 1 || i < last[j + 1])) {
                // Allow one mismatch
                canSkip = false;
                ans[j++] = i;
            }
        }

        // Step 3: Validate
        return j == m ? ans : vector<int>();
    }
};
