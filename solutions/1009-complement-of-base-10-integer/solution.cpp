class Solution {
public:
    string integerToBinary(int n)
    {
        if(n==0)
        {
            return "0";
        }
        string s = "";
        while(n)
        {
            s= to_string(n%2) +s;
            n /=2;
        }
    return s;
    }

    int binaryToInteger(string n1c)
    {
        int num=0;

        for(char c: n1c)
        {
            num = num *2 +(c - '0');
        }
    return num;
    }

    int bitwiseComplement(int n) {
        string n1 =integerToBinary(n);

        for(int i=0; i<n1.size(); i++)
        {
            if(n1[i]== '0')
            {
                n1[i] ='1';
            }
            else
            {
                n1[i] ='0';
            }
        }

        int ans = binaryToInteger(n1);
    return ans;
    }
};
