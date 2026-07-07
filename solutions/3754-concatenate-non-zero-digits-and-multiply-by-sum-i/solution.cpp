class Solution {
public:
    long long sumAndMultiply(int n) {
        string num = to_string(n);

        string no = "";
        long long sum =0;

        for(int i=0; i<num.size(); i++)
        {
            if(num[i] != '0')
            {
                no += num[i];

                sum += num[i] - '0';
            }
        }

        if(no.empty())
        {
            return 0;
        }

        long long x = stoll(no);
        return sum*x;
    }
};
