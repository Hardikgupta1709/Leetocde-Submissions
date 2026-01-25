class Solution {
public:
    void reverse(vector<int>& a, int l, int r)
    {
        while (l < r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    void rotate_left(vector<int>& nums, int k)
    {
        int n = nums.size();
        if (n <= 1) 
            {
                return;
            }
        k = k % n;

        reverse(nums, 0, k-1);      
        reverse(nums, k, n-1);      
        reverse(nums, 0, n-1);      
    }

    
    vector<int> solve (vector<int>& nums, int k)
    {
        vector<int> nn;
        vector<int> pos;
        
        for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]>=0)
                {
                    nn.push_back(nums[i]);
                    pos.push_back(i);
                }
            }

        if (nn.empty())
        {
            return nums;
        }

        rotate_left(nn,k);

        for(int i=0; i<pos.size() ;i++)
            {
                nums[pos[i]] = nn[i];
            }
        return nums;
    }
    
    vector<int> rotateElements(vector<int>& nums, int k) {
        return solve(nums,k);
    }
};
