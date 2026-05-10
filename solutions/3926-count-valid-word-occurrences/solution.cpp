class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        vector<int> ans;

        string concat = "";

        for(string str: chunks)
            {
                concat += str;
            }

        vector<string> words;
        string temp = "";

        for(int i=0; i<concat.size(); i++)
            {
                char ch = concat[i];
                if(ch >='a' && ch<='z')
                {
                    temp +=ch;
                }
                else if(ch == '-' && i>0 && i<concat.size()-1 &&
                       concat[i-1] >='a' && concat[i-1] <='z' &&
                       concat[i+1] >='a' && concat[i+1] <='z')
                {
                    temp +=ch;
                }
                else
                {
                    if(temp != "")
                        {
                            words.push_back(temp);
                            temp = "";
                        }
                }
            }

        if(temp != "")
        {
            words.push_back(temp);
        }

        unordered_map<string,int> freq;

        for(string w : words)
            {
                freq[w]++;
            }

        for(string str: queries)
            {    
                ans.push_back(freq[str]);
            }
    return ans;
    }
};
