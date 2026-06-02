class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int mini = INT_MAX;

        for(int i=0; i<landStartTime.size(); i++)
        {
            int land = landStartTime[i] + landDuration[i];
            for(int j=0; j<waterStartTime.size(); j++)
            {
                int total = (max(land,waterStartTime[j]) )+ waterDuration[j];

                mini = min(mini,total);
            }
        }

        for(int i=0; i<waterStartTime.size(); i++)
        {
            int water = waterStartTime[i] + waterDuration[i];
            for(int j=0; j<landStartTime.size(); j++)
            {
                int total = (max(water,landStartTime[j])) + landDuration[j];

                mini = min(mini,total);
            }
        }
    return mini;
    }
};
