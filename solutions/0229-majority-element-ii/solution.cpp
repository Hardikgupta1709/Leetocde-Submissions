class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int n = nums.size();

        unordered_map<int,bool> visited;

        for(int i=0; i<nums.size(); i++)
        {
            if(freq[nums[i]] > n/3 && visited[nums[i]] == false)
            {
                visited[nums[i]] = true;
                ans.push_back(nums[i]);
            }
        }
    return ans;
    }
};
