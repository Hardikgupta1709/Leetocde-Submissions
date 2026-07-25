class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        int maxi = INT_MIN;

        for(int i=0; i<num.size(); i++)
        {
            for(int j=i+1; j<num.size(); j++)
            {
                int prod = (num[i]- '0') * (num[j] - '0');
                maxi = max(maxi,prod);
            }
        }
    return maxi;
    }
};
