class Solution {
public:
    string convert(string s, int numRows) {
        
        string finalString = "";
        
        // start by getting rid of single-row edge cases
        if (numRows == 1){
            return s;
        }
        
        // initialize a string array representing each row (top to bottom) in the zig zag matrix
        string zigzagMatrix[numRows];
        
        int i = 1;    // counter variable
        for(char yayay : s){
            // for each character in the string:
            
            // each period is considered the straight-down and the diagonal, until the start of the next straight down (double of numsRow - 2 <-- this is because the first and last rows aren't zigzagged)
                // if the counter's current value exceeds the number of chars that exists per period, reset counter back to 1 (starting the next period)
            if(i > ((numRows * 2) - 2)){
                i = 1;
            }
            
            // if counter is currently within the range of numRows, then it's in a straight-down column and just gets added to respective row
                // else, it's in the zig zag for the current period, so add it to the respective zig-zag row (difference of counter and number of rows, then down that many rows (of difference) from the last row)
            if(i <= numRows){
                zigzagMatrix[i - 1] += yayay;
            }
            else{
                zigzagMatrix[(numRows - (i - numRows) ) - 1] += yayay;
            }
            
            i++;    // increment counter
        }
        
        // finally, add each index of the string array (by rows, top to bottom) to tge final, resultant string and output that
        for(int i = 0; i < numRows; i++){
            finalString += zigzagMatrix[i];
        }
        
        return finalString;
    }
};

