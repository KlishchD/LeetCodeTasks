class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        int n = words.size() * len;
        
        if (n > s.size()) {
            return {};
        }
        
        unordered_map<string, int> q;
        
        for (string &s : words) {
            q[s]++;
        }
        
        
        vector<int> ans;
        
        for (int i = 0; i + n - 1 < s.size(); ++i) {
            unordered_map<string, int> q1 = q;
            bool flag = true;
            for (int j = 0; j < words.size(); ++j) {
                if (q1.count(s.substr(i + (j * len), len)) && q1[s.substr(i + (j * len), len)]) {
                    --q1[s.substr(i + (j * len), len)];
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
