class Solution {
public:
    int candy(vector<int>& ratings) {

        int total = ratings.size();
        int i=0;
        int c =0;

        vector<int> candies (ratings.size(), 0);

        while (++i < ratings.size()) {
            if (ratings[i-1] >= ratings[i])
                c = 0;
            else
                candies[i] = ++c;
        }
        --i;
        while (--i >=0 ) {
            if (ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i+1]+1, candies[i]);
            }
        }

        for_each(candies.begin(), candies.end(), [&total](int can){
            total += can;
        });

        return total;
    }

};
