class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        int j=0;

        for(int i=0; i<nums1.size(); i++)
        {
            if(j<i)
            {
                j=i;
            }
            while(j< nums2.size() && nums2[j] >= nums1[i])
            {
                maxi = max(maxi,j-i);
                j++;
            }
        }
    return maxi;
    }
};
