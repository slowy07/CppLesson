class Solution {
public:
    void dfs(vector<vector<int>>& h, int i, int j, vector<vector<bool>> &vis){
        int m= h.size();
        int n= h[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]==true) return;
        vis[i][j]=true;
        
        //travel to all 4 direction and mark visited;
        if(i+1 <m && h[i][j] <= h[i+1][j])
            dfs(h, i+1, j, vis);
        
        if(i-1 >=0 && h[i][j] <= h[i-1][j])
            dfs(h, i-1, j, vis);
        
        if(j+1 <n && h[i][j] <= h[i][j+1])
            dfs(h, i, j+1, vis);
        
        if(j-1>=0 && h[i][j] <= h[i][j-1])
            dfs(h, i, j-1, vis);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        //do dfs on all the edges of pacific ocean 
        //which has value equal or greater than the parent node;
        
        //do dfs on all the edge of atlantic ocean
        //which has value equal or greater than the parent node;
        
        int m= h.size();
        int n= h[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        //top pacific ocean
        for(int j=0;j<n;j++){ // i-> 0
            dfs(h, 0, j, pacific);
        }
        
        //left pacific ocean
        for(int i=0;i<m;i++){ // j=0
            dfs(h, i, 0, pacific);
        }
        
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        //right atlantic ocean;
        for(int i=0;i<m;i++){ // j=n-1;
            dfs(h, i, n-1, atlantic);
        }
        
        //bottom atlantic ocean
        for(int j=0;j<n;j++){ //i=m-1;
            dfs(h, m-1, j, atlantic);
        }
        
        vector<vector<int>> ans;
        //find common element in both pacific and atlantic;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pacific[i][j]==true && atlantic[i][j]==true) ans.push_back({i, j});
            
        return ans;
        
        // time complexity ->  O(N*M)
    }
};
