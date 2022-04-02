// Q2: https://leetcode.com/problems/count-artifacts-that-can-be-extracted/
// use a map for mapping grid with artifacts;
// for every grid in dig, erase it from map;
// count the num of left artifacts, then we can get the num of extraction.
// Time: O(n^2); Space: O(n^2)

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        map<pair<int, int>, int> grid;
        int m = artifacts.size();
        for (int i = 0; i < m; i++) {
            int width = artifacts[i][3] - artifacts[i][1] + 1, height = artifacts[i][2] - artifacts[i][0] + 1;
            for (int row = artifacts[i][0]; row <= artifacts[i][2]; row++) {
                for (int col = artifacts[i][1]; col <= artifacts[i][3]; col++) {
                    grid[{row, col}] = i;
                }
            }
        }
        for (vector<int> v : dig) {
            pair<int, int> p = { v[0], v[1] };
            if (grid.count(p)) {
                grid.erase(p);
            }
        }
        unordered_set<int> left;
        for (auto p : grid) {
            left.insert(p.second);
        }
        return m - left.size();
    }
};
