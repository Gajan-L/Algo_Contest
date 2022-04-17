// Q3 Maximum Trailing Zeros in a Cornered Path
// it's more a math problem
// just check every cornered path that i, j as the corner, count how may factors of 2 and 5;
// then the trailing zeros would be min(2s, 5s);
// time: O(mn), space: O(mn).

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> up(m, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<vector<vector<int>>> down(m, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<vector<vector<int>>> left(m, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<vector<vector<int>>> right(m, vector<vector<int>>(n, vector<int>(2, 0)));
        for (int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i - 1][j] % 5 == 0){
                    int num = grid[i - 1][j];
                    int cnt = 0;
                    while(num % 5 == 0){
                        cnt++;
                        num /= 5;
                    }
                    up[i][j][0] = up[i - 1][j][0] + cnt;
                }
                else{
                    up[i][j][0] = up[i - 1][j][0];
                }
                if(grid[i - 1][j] % 2 == 0){
                    int num = grid[i - 1][j];
                    int cnt = 0;
                    while(num % 2 == 0){
                        cnt++;
                        num /= 2;
                    }
                    up[i][j][1] = up[i - 1][j][1] + cnt;
                }
                else{
                    up[i][j][1] = up[i - 1][j][1];
                }
            }
        }
        for (int i = m - 2; i > -1; i--){
            for(int j = 0; j < n; j++){
                if(grid[i + 1][j] % 5 == 0){
                    int num = grid[i + 1][j];
                    int cnt = 0;
                    while(num % 5 == 0){
                        cnt++;
                        num /= 5;
                    }
                    down[i][j][0] = down[i + 1][j][0] + cnt;
                }
                else{
                    down[i][j][0] = down[i + 1][j][0];
                }
                if(grid[i + 1][j] % 2 == 0){
                    int num = grid[i + 1][j];
                    int cnt = 0;
                    while(num % 2 == 0){
                        cnt++;
                        num /= 2;
                    }
                    down[i][j][1] = down[i + 1][j][1] + cnt;
                }
                else{
                    down[i][j][1] = down[i + 1][j][1];
                }
            }
        }
        
        for (int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                if(grid[i][j - 1] % 5 == 0){
                    int num = grid[i][j - 1];
                    int cnt = 0;
                    while(num % 5 == 0){
                        cnt++;
                        num /= 5;
                    }
                    left[i][j][0] = left[i][j - 1][0] + cnt;
                }
                else{
                    left[i][j][0] = left[i][j - 1][0];
                }
                if(grid[i][j - 1] % 2 == 0){
                    int num = grid[i][j - 1];
                    int cnt = 0;
                    while(num % 2 == 0){
                        cnt++;
                        num /= 2;
                    }
                    left[i][j][1] = left[i][j - 1][1] + cnt;
                }
                else{
                    left[i][j][1] = left[i][j - 1][1];
                }
            }
        }
        for (int i = 0; i < m; i++){
            for(int j = n - 2; j > -1; j--){
                if(grid[i][j + 1] % 5 == 0){
                    int num = grid[i][j + 1];
                    int cnt = 0;
                    while(num % 5 == 0){
                        cnt++;
                        num /= 5;
                    }
                    right[i][j][0] = right[i][j + 1][0] + cnt;
                }
                else{
                    right[i][j][0] = right[i][j + 1][0];
                }
                if(grid[i][j + 1] % 2 == 0){
                    int num = grid[i][j + 1];
                    int cnt = 0;
                    while(num % 2 == 0){
                        cnt++;
                        num /= 2;
                    }
                    right[i][j][1] = right[i][j + 1][1] + cnt;
                }
                else{
                    right[i][j][1] = right[i][j + 1][1];
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int maxZero = 0;
                int curTwos = 0, curFives = 0, twos, fives;
                int num = grid[i][j];
                while(num % 2 == 0){
                    curTwos++;
                    num /= 2;
                }
                while(num % 5 == 0){
                    curFives++;
                    num /= 5;
                }
                // up + right
                fives = curFives + up[i][j][0] + right[i][j][0];
                twos = curTwos + up[i][j][1] + right[i][j][1];
                maxZero = max(maxZero, min(fives, twos));
                //printf("%d %d %d %d %d %d\n",i,j,tens,fives,twos,maxZero);
                // up + left
                fives = curFives + up[i][j][0] + left[i][j][0];
                twos = curTwos + up[i][j][1] + left[i][j][1];
                maxZero = max(maxZero, min(fives, twos));
                //printf("%d %d %d %d %d %d\n",i,j,tens,fives,twos,maxZero);
                // down + right
                fives = curFives + down[i][j][0] + right[i][j][0];
                twos = curTwos + down[i][j][1] + right[i][j][1];
                maxZero = max(maxZero, min(fives, twos));
                //printf("%d %d %d %d %d %d\n",i,j,tens,fives,twos,maxZero);
                // down + left
                fives = curFives + down[i][j][0] + left[i][j][0];
                twos = curTwos + down[i][j][1] + left[i][j][1];
                maxZero = max(maxZero, min(fives, twos));
                res = max(res, maxZero);
            }
        }
        return res;
    }
};
// 
