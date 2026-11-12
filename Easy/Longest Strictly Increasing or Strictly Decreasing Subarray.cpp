class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }

        int longestLength = 1;

        int LgstLenInc = 1;
        int LgstLenDec = 1;
        for(int i = 0; i < (nums.size() - 1); i++){

            if(nums[i + 1] > nums[i]){
                LgstLenInc++;
            } else{
                if(LgstLenInc > longestLength){
                    longestLength = LgstLenInc;
                }
                LgstLenInc = 1;
            }

            if(nums[i + 1] < nums[i]){
                LgstLenDec++;
            } else{
                if(LgstLenDec > longestLength){
                    longestLength = LgstLenDec;
                }
                LgstLenDec = 1;
            }

            if(nums[i] == nums[i + 1]){
                if(LgstLenInc > longestLength){
                    longestLength = LgstLenInc;
                }
                if(LgstLenDec > longestLength){
                    longestLength = LgstLenDec;
                }
                LgstLenInc = 1;
                LgstLenDec = 1;
            }


        }

        if(LgstLenInc > longestLength){
            longestLength = LgstLenInc;
        }
        if(LgstLenDec > longestLength){
            longestLength = LgstLenDec;
        }
        


        return longestLength;
    }
};
