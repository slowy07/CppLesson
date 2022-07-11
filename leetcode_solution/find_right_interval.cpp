class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        map<int, pair<int, int>> mp;
        int n = a.size();
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; i++) {
            mp[a[i][0]] = {a[i][1], i};
        }
        for (int i = 0; i < n; i++) {
            auto it = mp.lower_bound(a[i][1]);
            if (it != mp.end()) {
                ans[i] = it -> second.second;
            }
        }
        return ans;
    }
};
