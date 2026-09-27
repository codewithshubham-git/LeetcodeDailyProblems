class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string curr = "";

        for (char ch : s) {

            if (ch == '(') {
                // Save the current string
                st.push(curr);
                curr = "";
            }
            else if (ch == ')') {
                // Reverse the current substring
                reverse(curr.begin(), curr.end());

                // Add it to the previous string
                curr = st.top() + curr;
                st.pop();
            }
            else {
                // Normal character
                curr += ch;
            }
        }

        return curr;
    }
};