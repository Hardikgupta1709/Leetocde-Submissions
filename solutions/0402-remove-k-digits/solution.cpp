class Solution {
public:
    string removeKdigits(string num, int k) {

        stack <char> s;
        string ans = "";

        int i=0;

        while(i<num.size())
        {
            char curr = num[i];

            while(!s.empty() && k>0 && s.top()>curr)
            {
                s.pop();
                k--;
            }   
            s.push(curr);
            i++;
        }

        while(k>0)
        {
            s.pop();
            k--;
        }

        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        int j=0;
        while(j< ans.size() && ans[j] =='0')
        {
            j++;
        }
        
        ans = ans.substr(j);

        if(ans == "")
        {
            return "0";
        }

    return ans;
    }
};

