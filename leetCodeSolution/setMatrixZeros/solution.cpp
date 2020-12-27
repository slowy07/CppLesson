class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j;
        bool flag1=false, flag2=false;
        int m=matrix.size();
        int n=matrix[0].size();
        for(j=0;j<n;j++)
        {
            if(matrix[0][j]==0)
                flag1=true;
        }
        for(i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
                flag2=true;
        }
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[i][j]==0&&matrix[0][j]!=0)

                    matrix[0][j]=i;

                if(matrix[i][j]==0&&matrix[i][0]!=0)

                    matrix[i][0]=j;
            }
        }
        for(j=1;j<n;j++)
        {
            int row=matrix[0][j];
            if(row==0||(row>=1&&row<m&&matrix[row][j]==0))
            {
                matrix[0][j]=0;
                for(i=1;i<m;i++)
                {
                    int p=matrix[i][0];
                    if(p!=j)
                        matrix[i][j]=0;
                }
            }
        }
        for(i=1;i<m;i++)
        {
            int col=matrix[i][0];
            if(col==0||(col>=1&&col<n&&matrix[i][col]==0))
               {
                   for(j=0;j<n;j++)
                       matrix[i][j]=0;
               }
               else
               {
                   for(j=1;j<n;j++)
                   {
                       if(matrix[0][j]==0)
                           matrix[i][j]=0;
                   }
               }
        }
        if(flag1)
        {
            for(j=0;j<n;j++)
                matrix[0][j]=0;
        }
        if(flag2)
        {
            for(i=0;i<m;i++)
                matrix[i][0]=0;
        }
    }
};
