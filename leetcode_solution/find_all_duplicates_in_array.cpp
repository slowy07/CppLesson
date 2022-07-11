class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        vector<int> jawaban;
        for (auto i = 0;  i < a.size(); i++) {
            int j = abs(a[i]);
            if (a[j - 1] < 0) {
                jawaban.push_back(j);
            } else {
                a[j - 1] = -a[j - 1];
            }
        }
        return jawaban;
    }
};
