#include<vector>

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int distance =0;
        for(int i=0;i<points.size()-1;i++)
        {

        int u1 = points[i][0];
        int u2 = points[i][1];
        int v1 = points[i+1][0];   
        int v2 = points[i+1][1];

        distance += max(abs(v1-u1),abs(v2-u2));
        }

        return distance;
    }
};
