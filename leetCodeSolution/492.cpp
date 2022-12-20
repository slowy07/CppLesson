class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);
        while (area % W) {
            --W;
        }
        return {area / W, W};
    }
};
