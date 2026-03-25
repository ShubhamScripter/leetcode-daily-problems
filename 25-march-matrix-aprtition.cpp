class Solution {
    public:
        bool canPartitionGrid(vector<vector<int>>& grid) {
             long long int total=0;
            vector<long long int>row_sum(grid.size(),0);
            vector<long long int>col_sum(grid[0].size(),0);
    
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    row_sum[i]+=grid[i][j];
                    col_sum[j]+=grid[i][j];
                    total+=grid[i][j];
                }
            }
    
            int sum=0;
            for(int i=1;i<row_sum.size();i++)
            {
                row_sum[i]+=row_sum[i-1];  
            }
             for(int i=1;i<col_sum.size();i++)
            {
                col_sum[i]+=col_sum[i-1];  
            }
    
            for(auto e:row_sum)
            {
                if(e*2==total)
                {
                    cout<<"row called";
                    return true;
                }
            }
            for(auto e:col_sum)
            {
                if(e*2==total)
                {
                    cout<<"column called";
                    return true;
                }
            }
    
            return false;
        }
    };