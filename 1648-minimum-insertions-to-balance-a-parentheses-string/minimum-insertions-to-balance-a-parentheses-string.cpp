
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // A closing pair must be ))
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    // Insert the missing second ')'
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } else {
                    // Insert a matching '('
                    insertions++;
                }
            }
        }

        return insertions + 2 * open;
    }
};
