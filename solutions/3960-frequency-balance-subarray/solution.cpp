class Solution {
public:
    int getLength(vector<int>& nums) {
        int upper=1;
        int n = nums.size();

        for(int i=0; i<n; i++)
            {
                unordered_map<int,int> freq;
                unordered_map<int,int> freqCount;

                for(int j=i; j<n; j++)
                    {
                        int x= nums[j];

                        int oldFreq = freq[x];

                        if(oldFreq >0)
                        {
                            freqCount[oldFreq]--;

                            if(freqCount[oldFreq] == 0)
                                freqCount.erase(oldFreq);
                        }

                        freq[x]++;

                        int newFreq = freq[x];
                        freqCount[newFreq]++;

                        int len = j-i+1;

                        bool valid = false;

                        if(freqCount.size() == 1)
                        {
                            if(freq.size()==1)
                                valid = true;
                        }

                        if(freqCount.size() == 2)
                        {
                            auto it = freqCount.begin();

                            int f1 = it->first;
                            ++it;
                            int f2 = it->first;

                            int small = min(f1,f2);
                            int large = max(f1,f2);

                            if(large  == 2 *small)
                            {
                                valid = true;
                            }
                        }
                        
                        if(valid)
                        {
                            upper = max(upper,len);
                        }
                    }
            }
        return upper;
    }
};
