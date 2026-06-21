class Solution {
public:
    int maxDistance(string moves) {
        int x2=0;
        int y2=0;
        int k=0;

        for(int i=0; i<moves.size(); i++)
        {
            if(moves[i] == 'L')
            {
                x2--;
            }
            else if(moves[i] == 'R')
            {
                x2++;
            }
            else if(moves[i] == 'D')
            {
                y2--;
            }
            else if(moves[i] == 'U')
            {
                y2++;
            }
            else 
            {
                k++;
            }
        }

    int ans = abs(x2) + abs(y2) +k;
    return ans;
    }
};
