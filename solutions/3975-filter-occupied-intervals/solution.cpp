class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> temp = occupiedIntervals;
        sort(temp.begin(),temp.end());

        vector<vector<int>> ans;
        vector<vector<int>>FinalAns;

        for(int i=0; i<temp.size(); i++)
            {
                int start = temp[i][0];
                int end = temp[i][1];

                if(ans.empty() || start > ans.back()[1] +1)
                {
                    ans.push_back({start,end});
                }
                else
                {
                    ans.back()[1]=  max(ans.back()[1],end);
                }
            }

        for(int i=0; i<ans.size(); i++)
            {
                int start = ans[i][0];
                int end = ans[i][1];


                if(end<freeStart || start>freeEnd)
                {
                    FinalAns.push_back({start,end});
                }
                else 
                {
                    if(start < freeStart)
                    {
                        FinalAns.push_back({start, freeStart-1});
                    }
                    if(end > freeEnd)
                    {
                        FinalAns.push_back({freeEnd+1, end});
                    }
                }
            }
        return FinalAns;
    }
};
