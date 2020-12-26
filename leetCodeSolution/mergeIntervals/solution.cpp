class Solution {
public:
    int pivotI(vector<vector<int>>& intervals,int l,int r)
    {
        int pivotL=intervals[r][0];
        int pivotH=intervals[r][1];

        int j=l-1;
        for(int i=l;i<r;++i)
        {
            if(intervals[i][0]<pivotL)
            {
                j++;
                int tlow=intervals[i][0];
                int thigh=intervals[i][1];
                intervals[i][0]=intervals[j][0];
                intervals[i][1]=intervals[j][1];
                intervals[j][0]=tlow;
                intervals[j][1]=thigh;
            }
        }
        int tlow=intervals[j+1][0];
        int thigh=intervals[j+1][1];
        intervals[j+1][0]=intervals[r][0];
        intervals[j+1][1]=intervals[r][1];
        intervals[r][0]=tlow;
        intervals[r][1]=thigh;
        return j+1;
    }
    void sortInterval(vector<vector<int>>& intervals,int l,int r)
    {
        if(l<r)
        {
            int pI=pivotI(intervals,l,r);

            sortInterval(intervals,l,pI-1);
            sortInterval(intervals,pI+1,r);

        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sortInterval(intervals,0,intervals.size()-1);
        vector<vector<int>> res;

        int l=intervals[0][0];
        int r=intervals[0][1];
        vector<int> mid(2);

        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0]<=r)
            {
                mid[0]=l;
                r=max(r,intervals[i][1]);
            }
            else
            {
                mid[0]=l;
                mid[1]=r;
                res.push_back(mid);
                l=intervals[i][0];
                r=intervals[i][1];
            }
        }
        mid[0]=l;
        mid[1]=r;
        res.push_back(mid);
        return res;
    }
};
