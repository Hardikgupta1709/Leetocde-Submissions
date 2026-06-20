class Solution {
public:
    int minLights(vector<int>& lights) {

        int n = lights.size();

        vector<int>prefix(n),suffix(n);

        int res=0;


        for(int i=0; i<n; i++)
        {
            if(lights[i])
            {
                lights[i]++;
            }
        }

        prefix[0] = lights[0];
        suffix[n-1] = lights[n-1];

        for(int i=1; i<n; i++)
        {
            prefix[i] = max(lights[i],prefix[i-1]-1);
        }

        for(int i=n-2; i>=0; i--)
        {
            suffix[i] = max(lights[i],suffix[i+1]-1);
        }

        for(int i=0; i<n; i++)
        {
            lights[i] = max(prefix[i],suffix[i]);
        }

        int zeros = 0;

        for(int i=0; i<n; i++)
        {
            if(lights[i] ==0)
            {
                zeros++;
            }
            else
            {
                res+= ceil(zeros/3.0);
                zeros = 0;
            }
        }
        res += ceil(zeros/3.0);
            
    return res;
    }
};
