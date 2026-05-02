class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++)
        {
            int val = nums1[i];
            int nextval =-1;

            int j=0;
            for(; j<nums2.size(); j++)
            {
                if(nums2[j] == val)
                {
                    break;
                }
            }

            for(int k=j+1; k<nums2.size(); k++)
            {
                if(nums2[k] > val )
                {
                    nextval = nums2[k];
                    break;
                }        
            }
            ans.push_back(nextval);
        }
    return ans;
    }
};
