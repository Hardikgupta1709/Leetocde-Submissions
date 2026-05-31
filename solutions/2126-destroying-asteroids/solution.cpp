class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long minThreshold = (long long)asteroids[0] + mass;

        if(mass < asteroids[0])
        {
            return false;
        }

        for(int i=1; i<asteroids.size(); i++)
        {
            if(asteroids[i] > minThreshold)
            {
                return false;
            }
            else
            {
                minThreshold += asteroids[i];
            }
        }
    return true;
    }
};
