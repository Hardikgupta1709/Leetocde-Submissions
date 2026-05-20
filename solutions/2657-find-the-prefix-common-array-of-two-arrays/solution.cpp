class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> c(A.size(),0);

        for(int i=0; i<A.size(); i++)
        {
            unordered_map<int,int> freq;

            for(int j=0; j<=i; j++)
            {
                freq[A[j]]++;
                freq[B[j]]++;
            }

            int count =0;

            for(auto it : freq)
            {
                if(it.second == 2)
                {
                    count ++;
                }
            }
            c[i] = count;
        }
    return c;
    }
};
