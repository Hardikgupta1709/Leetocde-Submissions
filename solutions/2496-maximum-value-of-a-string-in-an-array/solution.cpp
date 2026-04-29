class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int val=0;

        for(int i=0;i<strs.size();i++){
            string temp=strs[i];

            bool digits=false;
            bool charr=false;
            for(int j=0;j<temp.size();j++){
                if(isdigit(temp[j])){
                    digits=true;
                    if(charr){
                        break;
                    }
                }
                else{
                    charr=true;
                    if(digits){
                        break;
                    }
                }
            }
            if((charr) || (digits && charr)){
                if(val < temp.size()){
                    val=temp.size();
                }
            }else{
                if(val < (stoi(temp))){
                    val=stoi(temp);
                }
            }
        }
        return val;
    }
};
