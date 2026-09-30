class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;

        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;

                // Odd depth -> group 1
                // Even depth -> group 0
                ans.push_back(depth % 2);
            } 
            else {
                // For ')' use the depth before closing
                ans.push_back(depth % 2);
                depth--;
            }
        }

        return ans;
    }
};
