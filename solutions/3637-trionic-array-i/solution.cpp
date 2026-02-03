class Solution {
public:
    bool solve1(vector<int>& nums,int &p)
    {
        int i =0;
        while(i != nums.size()-1)
        {
            if(nums[i]<nums[i+1])
            {
                p=i+1;
                i++;
            }
            else
            {
                break;
            }
        }
        return p>0;
    }

    bool solve2(vector<int>& nums,  int &p, int &q)
    {
        int i=p;
        while(i != nums.size()-1)
        {
            if(nums[i]> nums[i+1])
            {
                q= i+1;
                i++;
            }
            else
            {
                break;
            }
        }
        return q>p;
    }

    bool solve3(vector<int> & nums, int &q)
    {
        int i=q;
        while(i != nums.size()-1)
        {
            if(nums[i]<nums[i+1])
            {
                i++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool isTrionic(vector<int>& nums) {

        int p =0;
        int q =0;
        bool cond1 = solve1(nums,p);
        bool cond2 = solve2(nums,p,q);
        bool cond3 = solve3(nums,q);

        if(cond1 && cond2 && cond3 && q<nums.size()-1)
        {
            return true;
        }

    return false;
    }
};
