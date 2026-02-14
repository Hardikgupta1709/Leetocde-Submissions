class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        
        vector<string> res = words;
        
        int n = res.size();
        vector<string> tempStr;
        int count = 0;

        for(string s : res)
        {
            if(s.size() < k)
                {
                    continue ;
                }

            string temp = "";
            for(int i = 0; i < k; i++)
            {
                temp += s[i];
            }
            tempStr.push_back(temp);
        }

        if(tempStr.size() == 0) 
            {
                return 0;
            }

        sort(tempStr.begin(), tempStr.end());

        int freq = 1;

        for(int i = 1; i < tempStr.size(); i++)
        {
            if(tempStr[i] == tempStr[i - 1])
            {
                freq++;
            }
            else
            {
                if(freq >= 2)
                    count++;

                freq = 1;
            }
        }

        if(freq >= 2)
            count++;

        return count;
    }
};

