class Solution {
public:

    bool isPalindrome(int x) {
        string strOg = to_string(x);
        string str = to_string(x);

        int i=0;
        int j= str.size()-1;

        while(i<j)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;

            i++;
            j--;
        }

        if(str == strOg)
        {
            return true;
        }
    return false;
    }
};
