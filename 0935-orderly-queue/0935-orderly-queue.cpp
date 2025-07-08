class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;
        int n = s.length();
        for(int i = 1; i < n; i++) {
            string temp = s.substr(i, s.length()) + s.substr(0, i);
            ans = min(ans, temp);
        }
        return ans;
    }
};