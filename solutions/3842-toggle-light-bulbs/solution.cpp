class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        sort(bulbs.begin(), bulbs.end());

        for(int i = 0; i + 1 < bulbs.size(); i++)
        {
            if(bulbs[i] == bulbs[i+1])
            {
                bulbs.erase(bulbs.begin() + i, bulbs.begin() + i + 2);
                i--;  
            }
        }
        return bulbs;
    }
};

