class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        if (timeSeries.size() == 0) return 0;
        for (int i = 0; i < timeSeries.size() -1;i++) {
               if (timeSeries[i] + duration <= timeSeries[i+1]) res += duration;
                else res+= (timeSeries[i+1] - timeSeries[i]);
        }
        res += duration;
        return res;
    }
};
