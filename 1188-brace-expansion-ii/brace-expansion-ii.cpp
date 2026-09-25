class Solution {
public:

    set<string> solve(string &s, int &i) {
        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union
                i++;

                set<string> next = solve(s, i);

                result.insert(next.begin(), next.end());
            }
            else {
                set<string> cur;

                if (s[i] == '{') {
                    i++;  // skip '{'

                    cur = solve(s, i);

                    i++;  // skip '}'
                }
                else {
                    // Single character
                    cur.insert(string(1, s[i]));
                    i++;
                }

                // Concatenation
                set<string> temp;

                for (string a : result) {
                    for (string b : cur) {
                        temp.insert(a + b);
                    }
                }

                result = temp;
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};