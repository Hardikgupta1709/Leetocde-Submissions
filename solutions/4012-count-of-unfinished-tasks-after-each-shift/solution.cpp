class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<int> ans;

        int n = tasks.size();

        vector<long long>prefix(n+1,0);

        for(int i=0; i<n; i++)
            {
                prefix[i+1] = prefix[i] + tasks[i];
            }

        long long workDone =0;

        for(int j=0 ; j<shifts.size(); j++)
            {
                workDone += shifts[j];

                if(workDone >= prefix[n])
                {
                    ans.push_back(0);
                    workDone =0;
                    continue;
                }

                int completed =0;

                int low =0;
                int high = n;
                int mid = low + (high-low)/2;

                while(low <= high)
                    {
                        if(prefix[mid] <= workDone)
                        {
                            completed = mid;
                            low = mid +1;
                        }
                        else
                        {
                            high = mid-1;
                        }
                        mid = low + (high - low)/2;
                    }
                ans.push_back(n-completed);
            }
        return ans;
    }
};
