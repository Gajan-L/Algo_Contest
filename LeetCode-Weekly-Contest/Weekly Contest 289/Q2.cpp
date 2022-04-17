// Q2 Minimum Rounds to Complete All Tasks
// it looks familar somehow
// sort the array;
// for tasks of same value, counts it cnt;
// if cnt == 1, violate the rule, return -1;
// if cnt % 3 == 0, need cnt/3 rounds to finish it;
// else need cnt/3 + 1 rounds; 
// why? just greedy assign k task one round, and modify the last two round;
// if cnt/3 == 1, last two rounds would be 2, 2, else, last two rounds would be 3, 2.
// time: O(nlogn), space: O(1).

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size(), cnt = 0;
        for(int i = 0,j = 0; j < n;){
            while(j < n && tasks[j] == tasks[i]) j++;
            // j would be the index of next difficulty level of task;
            int curDiffTasksNum = j - i;
            if(curDiffTasksNum == 1){
                return -1;
            }
            if(curDiffTasksNum % 3 == 0){
                cnt += curDiffTasksNum/3;
            }
            else{
                cnt += curDiffTasksNum/3 + 1;
            }
            i = j;
        }
        return cnt;
    }
};
