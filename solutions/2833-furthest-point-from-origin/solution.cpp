class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        string str1 = moves;
        int dist1 =0;

        string str2 = moves;
        int dist2 =0;

        for(int i=0; i<str1.size(); i++)
        {
            if(str1[i] == '_')
            {
                str1[i] = 'L';
            }
        }
        int countR1 =0;
        int countL1 =0;
        for(int i=0; i<str1.size(); i++)
        {

            if(str1[i] == 'L')
            {
                countL1++;
            }
            else
            {
                countR1++;
            }

            dist1 = abs(countL1 - countR1);
        }


        for(int i=0; i<str2.size(); i++)
        {
            if(str2[i] == '_')
            {
                str2[i] = 'R';
            }
        }
        int countR2 =0;
        int countL2 =0;
        for(int i=0; i<str2.size(); i++)
        {

            if(str2[i] == 'L')
            {
                countL2++;
            }
            else
            {
                countR2++;
            }

            dist2 = abs(countL2 - countR2);
        }

    return max(dist1,dist2);
    }
};
