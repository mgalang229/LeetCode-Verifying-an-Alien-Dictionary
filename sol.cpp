class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int value[26];
        memset(value, 0, sizeof(value));
        for (int i = 0; i < (int) order.size(); i++) {
            value[order[i]-'a'] = i;
        }
        for (int i = 0; i < (int) words.size() - 1; i++) {
            string cur = words[i], next = words[i+1];
            int mn = min(cur.size(), next.size());
            bool match = true, invalid = false;
            for (int j = 0; j < mn; j++) {
                if (value[cur[j]-'a'] < value[next[j]-'a']) {
                    match = false;
                    break;
                }
                if (value[cur[j]-'a'] > value[next[j]-'a']) {
                    invalid = true;
                    break;
                }
            }
            if (!invalid && match && (int) cur.size() > (int) next.size()) {
                return false;
            }
            if (invalid) {
                return false;
            }
        }
        return true;
    }
};
