class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0], e = newInterval[1];
        vector<vector<int>> ans;
        for (auto &intv : intervals) {
            if (s > e) ans.push_back(intv);
            else if (intv[0] > e) {
                ans.push_back({ s, e });
                s = e + 1;
                ans.push_back(intv);
            } else if (intv[1] < s) ans.push_back(intv);
            else {
                s = min(s, intv[0]);
                e = max(e, intv[1]);
            }
        }
        if (s <= e) ans.push_back({ s, e });
        return ans;
    }
};
