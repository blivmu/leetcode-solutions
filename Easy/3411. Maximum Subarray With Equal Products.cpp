class Solution {
public:
    int maxLength(vector<int>& nums) {

        // initialize return value;
        int longestSubArr = 0;

        // loop for each number in "nums" array EXCEPT the last number:
        for(int i = 0; i < nums.size() - 1; i++)
        {

            // initialize the current product, LCM and GCD variables (minimum 2 items at a time)
            long long currProd = nums[i] * nums[i + 1];
            long long currLCM = lcm(nums[i], nums[i + 1]);
            int currGCD = gcd(nums[i], nums[i + 1]);

            // if the starting LCM * starting GCD == current Product:
            if(currLCM * currGCD == currProd)
            {
                // initialize var. for current subarray size to 2 (again, minimum two numbers needed for ts (this) )
                int currSize = 2;

                // loop through EACH subsequent number in the array, starting from the second number of the current subarray (initialized with 2 nums), until the end of the array:
                for(int j = i + 2; j < nums.size(); j++)
                {
                    // change the product, LCM & GCD with the current number in array (in the nested loop)
                    currProd *= nums[j];
                    currLCM = lcm(currLCM, nums[j]);
                    currGCD = gcd(currGCD, nums[j]);

                    // if the new entire-array-product is still equal to the new product of the LCM and GCD, let this nested loop continue iterating and increment the size counter (basically saying add the num at current "j", if valid based on rules above, to the current subarray)
                    if(currLCM * currGCD == currProd)
                    {
                        currSize++;
                    }
                    else    // and if not, then break out of this nested loop
                    {
                        break;
                    }
                }

                // once the nested loop above is exited, check if the size of the subarray found from that nested loop is greater than the historically largest size, and if yes, then make that the new historically largest size
                if (currSize > longestSubArr)
                {
                    longestSubArr = currSize;
                }
                

            }
        }
        

        return longestSubArr;
    }
};
