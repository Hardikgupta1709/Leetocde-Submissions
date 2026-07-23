class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> totalMinutes;

        for(int i=0; i<timePoints.size(); i++)
        {
            string Hmin = "";
            int counter = 0;

            while(counter < 2)
            {
                Hmin += timePoints[i][counter];
                counter++;
            }
            int Hmins = stoi(Hmin)*60;

            string min = "";
            int counter2 = 3;

            while(counter2 < 5)
            {
                min += timePoints[i][counter2];
                counter2++;
            }
            int mins = stoi(min);

            int totalMins = Hmins + mins;
            totalMinutes.push_back(totalMins);
        }

        sort(totalMinutes.begin(), totalMinutes.end());

        int mini = INT_MAX;
        for(int i=1; i<totalMinutes.size(); i++)
        {
            int difference = totalMinutes[i] - totalMinutes[i-1];
            mini = min(mini,difference);
        }

        int MidnightDistance = (1440 - totalMinutes[totalMinutes.size()-1]) + totalMinutes[0];

        mini = min(mini, MidnightDistance);

    return mini;
    }
};
