class Solution {
public:
    inline bool isGood(unordered_map<string, int> &q) {
        for (auto &i : q) {
            if (i.second > 0) return 0;
        }
        return 1;
    }
    
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
        for (int i = 0; i < len; ++i) {
            for (int j = 0; i + (j + 1) * len - 1 < s.size(); ++j) {
                if (j >= words.size()) {
                    if (q.count(s.substr(i + (j - words.size()) * len, len))) {
                        ++q[s.substr(i + (j - words.size()) * len, len)];
                    }
                }
                if (q.count(s.substr(i + j * len, len))) {
                    --q[s.substr(i + j * len, len)];
                    
                    if (isGood(q))
                        ans.push_back(i + (j + 1 - words.size()) * len);
                    
                }
            }
            for (int j = max(0, ((int)s.size() - i) / len - (int)words.size()); i + (j + 1) * len - 1 < s.size(); ++j) {
             
                if (q.count(s.substr(i + j * len, len))) {
                    ++q[s.substr(i + j * len, len)];
                }
                
            }
                        
        }
        return ans;
    }
};
