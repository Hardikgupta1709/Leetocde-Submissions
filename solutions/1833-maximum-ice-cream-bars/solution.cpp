class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count =0;
        int remaining =coins;

        for(int i=0; i<costs.size();i++)
        {
            if(remaining >= costs[i])
            {
                count++;
                remaining -= costs[i];
            }
            else
            {
                break;
            }
        }
    return count;
    }
};
