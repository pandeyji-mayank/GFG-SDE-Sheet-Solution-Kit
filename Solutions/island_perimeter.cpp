#include <bits/stdc++.h>
using namespace std;

int vis[150][150];
int ct = 0;
void dfs(int i, int j, int rw, int cl, vector<vector<int>>&gri)
{
    if (i < 0 || j < 0 || i >= rw || j >= cl)
    {
        ct++;
        return;
    }
    if (gri[i][j]==0)
    {
        ct++;
        return;
    }
    if (vis[i][j]==1)
    {
        return;
    }
    vis[i][j]=1;
    dfs(i+1,j,rw,cl,gri);
    dfs(i,j+1,rw,cl,gri);
    dfs(i-1,j,rw,cl,gri);
    dfs(i,j-1,rw,cl,gri);
}
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        ct=0;
        int row = grid.size();
        int column = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vis[i][j] = 0;
            }
        }
        int t = -1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (grid[i][j] == 1)
                {
                    t=1;
                    dfs(i,j, row,column,grid);
                    break;
                }
            }
            if (t == 1)
            {
                break;
            }
        }
        return ct;
        // return ans;
    }
};
