class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

        int count =0;

        int i =0;
        int j= nums.size()-1;

        while(i<j)
        {
            if(nums[i] == 0)
            {
                while(i<j && nums[j] ==0)
                {
                    j--;
                }

                if(i<j)
                {
                    swap(nums[i] , nums[j]);
                    count++;
                    j--;
                }
            }
            i++;
        }
    return count; 
    }
};

