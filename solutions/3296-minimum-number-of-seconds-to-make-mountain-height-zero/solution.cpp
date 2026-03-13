class Solution {
public:

    bool canFinish(long long mid, int mountainHeight, vector<int>& workerTimes)
    {
        long long total = 0;

        for(int i = 0; i < workerTimes.size(); i++)
        {
            long long t = workerTimes[i];
            long long j = 1;
            long long time = 0;

            while(true)
            {
                time += t * j;

                if(time > mid)
                    break;

                total++;
                j++;

                if(total >= mountainHeight)
                    return true;
            }
        }

        return total >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long left = 1;
        long long right = 1e18;
        long long ans = right;

        while(left <= right)
        {
            long long mid = left + (right - left) / 2;

            if(canFinish(mid, mountainHeight, workerTimes))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};
