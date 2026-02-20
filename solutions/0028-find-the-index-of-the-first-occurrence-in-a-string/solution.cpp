class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int i=0, j=0, ans = -1;
        while(i<n && j < m){
            j=0;
            if(haystack[i] == needle[j]){
                ans = i;
                while(i<n && j<m){
                    if(haystack[i] == needle[j]){
                        i++;
                        j++;
                    }
                    else{
                        i = ans+1;
                        break;
                    }
                }
                if(j == m) return ans;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};
