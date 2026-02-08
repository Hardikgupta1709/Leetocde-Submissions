class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int count =0 ;
        int n = nums.size();

        for(int i=0; i<n; i++)
            {
                int key = nums[i];
                int sum =0;
                 int elementCount =0 ;
                for(int j= i+1; j<n; j++)
                    {
                        sum += nums[j] ;
                        elementCount++;
                    }
                if(elementCount > 0)
                {
                    
                if(key > (sum/elementCount) )
                         {
                             count ++;
                         }
                }
            }
        return count;
    }
};
