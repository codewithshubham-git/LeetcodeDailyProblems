class Solution {
public:
    string removeDuplicates(string s) {
        
        string ans;

        for(char ch : s) {
            
            // If last character is same, remove it
            if(!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            }
            else {
                // Otherwise add current character
                ans.push_back(ch);
            }
        }

        return ans;
    }
};