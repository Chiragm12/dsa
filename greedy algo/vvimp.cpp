//what we do is make a array with the maximum amount of deadlines, and then we try to fill the slots with the jobs that have the highest profit
#include <vector>
#include <algorithm>
using namespace std;


class Solution {

public:
    struct job {
        int id;
        int profit;
        int deadline;
    };

    static bool comp(job val1, job val2) {
        return val1.profit > val2.profit;
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = profit.size();
        vector<job> jobs;

        // Create the job list
        for (int i = 0; i < n; i++) {
            jobs.push_back({i + 1, profit[i], deadline[i]});
        }

        // Sort jobs by profit descending
        sort(jobs.begin(), jobs.end(), comp);

        // Find the maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }

        // Create slot array of size maxDeadline+1
        vector<int> slot(maxDeadline + 1, -1);

        int jobCount = 0;
        int totalProfit = 0;

        // Try to place each job
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = jobs[i].id;
                    jobCount++;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }

        return {jobCount, totalProfit};
    }
};