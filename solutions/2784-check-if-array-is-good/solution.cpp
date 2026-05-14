class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int,int> freq;

        for(int x: nums)
        {
            freq[x] ++;
        }

       int largest = nums.back();
       int lastValuefreq = freq[largest];

        if(largest != nums.size() - 1)
        {
            return false;
        }

        bool allOne = true;
        for(auto it = freq.begin(); it!= freq.end(); ++it)
        {
            if(it->first == largest)
            {
                continue;
            }
            if(it->second !=1)
            {
                allOne = false;
                break;
            }
        }

        if(allOne && lastValuefreq == 2)
        {
            return true;
        }
    return false;
    }
};
