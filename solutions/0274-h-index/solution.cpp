class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        sort(citations.begin(), citations.end());

        for(int i=0; i<n ; i++)
        {
            int length = n-i;
            if(citations[i] >= length)
            {
                return length;
            }
        }
    return 0;
    }
};
