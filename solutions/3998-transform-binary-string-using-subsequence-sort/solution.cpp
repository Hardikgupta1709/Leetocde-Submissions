class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> ans;

        int count1ins = 0;
        vector<int>prefixOnes(s.size());
        for(int i=0; i<s.size(); i++)
            {
                if(s[i] == '1')
                {
                    count1ins++;
                }
                prefixOnes[i] = count1ins;
            }

        for(string sub : strs)
            {
                if(sub == s)
                {
                    ans.push_back(true);
                    continue;
                }

                int count1insub = 0;
                int questionmarks = 0;

                for(int i=0; i<sub.size(); i++)
                    {
                        if(sub[i] == '1')
                        {
                            count1insub++;
                        }
                        else if(sub[i] == '?')
                        {
                            questionmarks++;
                        }
                    }

                if(count1insub > count1ins)
                {
                    ans.push_back(false);
                    continue;
                }

                if(count1insub + questionmarks < count1ins)
                {
                    ans.push_back(false);
                    continue;
                }

                int onesNeeded = count1ins - count1insub;

                for(int i = sub.size()-1; i>=0; i--)
                    {
                        if(sub[i] == '?')
                        {
                            if(onesNeeded > 0)
                            {
                                sub[i] = '1';
                                onesNeeded--;
                            }
                            else
                            {
                                sub[i] = '0';
                            }
                        }
                    }

                bool possible = true;
                int currentOnes = 0;

                for(int i=0; i<sub.size(); i++)
                    {
                        if(sub[i] == '1')
                        {
                            currentOnes++;
                        }

                        if(currentOnes > prefixOnes[i])
                        {
                            possible = false;
                            break;
                        }
                    }
                ans.push_back(possible);
            }
        return ans;
    }
};
