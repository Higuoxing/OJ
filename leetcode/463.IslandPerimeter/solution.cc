#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int result = 0;
            for (int i = 0; i < grid.size(); i ++) {
                for (int j = 0; j < grid[i].size(); j ++) {
                    if (grid[i][j] == 1) {
                        result += 4;
                        if (i > 0 && grid[i-1][j] == 1) result -= 2;
                        if (j > 0 && grid[i][j-1] == 1) result -= 2;
                    }
                }
                
            }    
            return result;
        }
};

int main() {

    Solution sol;
    vector<vector<int>> grid(4, vector<int>(4));
    grid = {{0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}};
    int test = sol.islandPerimeter(grid);
    for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[i].size(); j ++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "------------------------------" << endl;
    cout << test;
    return 0;
}
