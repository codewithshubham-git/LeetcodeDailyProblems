#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Parse expression starting from index i
    set<string> parse(string &s, int &i) {

        // Stores the result of the current expression
        set<string> result;

        // We start with an empty string
        // because concatenation needs a starting value
        result.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                // Move past '{'
                i++;

                // Parse everything inside braces
                set<string> inside = parse(s, i);

                // Move past '}'
                i++;

                // Concatenate current result with inside
                result = multiply(result, inside);
            }
            else if (s[i] == ',') {
                // Union starts after comma
                i++;

                set<string> next = parse(s, i);

                result.insert(next.begin(), next.end());

                // parse() will stop at '}'
                // so we return here
                return result;
            }
            else {
                // Normal lowercase character
                string ch(1, s[i]);

                set<string> single = {ch};

                result = multiply(result, single);

                i++;
            }
        }

        return result;
    }

    // Cartesian product / concatenation
    set<string> multiply(set<string> &a, set<string> &b) {

        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};