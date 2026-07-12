class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int h1 = stoi(startTime.substr(0,2));
        int m1 = stoi(startTime.substr(3,2));
        int s1 = stoi(startTime.substr(6,2));

        int sTotal = h1* 3600 + m1*60 +s1;

        int h2 = stoi(endTime.substr(0,2));
        int m2 = stoi(endTime.substr(3,2));
        int s2 = stoi(endTime.substr(6,2));

        int eTotal = h2*3600 + m2*60 + s2;

        int ans = eTotal - sTotal;
    return ans;
    }
};
