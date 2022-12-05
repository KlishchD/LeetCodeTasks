class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> q;
        vector<int> p(s.size(), -1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                q.push(i);
            } else {
                if (q.empty()) continue;
                p[i] = q.top();
                q.pop();
            }
        }

        int ans = 0, cans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (p[i] == -1) {
                cans = 0;
                continue;
            }
            cans += i - p[i] + 1;
            i = p[i];
            ans = max(ans, cans);
        }
        return ans;
    }
};
