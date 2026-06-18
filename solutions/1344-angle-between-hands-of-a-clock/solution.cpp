class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAng = minutes*6;

        double totalAngHour = (double)(hour*60 + minutes)/2;

        double absDiff = abs(minAng- totalAngHour);

    return min(absDiff , 360-absDiff);
    }
};
