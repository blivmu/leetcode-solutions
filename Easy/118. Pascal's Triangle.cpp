class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> finalTriangle;

        vector<int> prevRow;
        for(int i = 1; i <= numRows; i++){

            vector<int> rowArr;

            if(i == 1){
                rowArr.push_back(1);
            }
            else if(i == 2){
                rowArr.push_back(1);
                rowArr.push_back(1);
            }
            else{
                rowArr.push_back(1);
                for(int j = 0; (j+1) < prevRow.size(); j++){
                    // int x = prevRow[j];
                    // int y = prevRow[j + 1];
                    // rowArr.push_back(x + y);
                    rowArr.push_back(prevRow[j] + prevRow[j + 1]);
                } 
                rowArr.push_back(1);
            }

            prevRow = rowArr;

            finalTriangle.push_back(rowArr);
        }



        return finalTriangle;
        
    }
};

/*
Intuition
    A very simple problem with a simple 2-minute solution using a second array that holds the values of the previous row.

Approach
    If you notice on Pascal's triangle, both rows 0 (1) and 1 (1, 1) (the first and second rows, formally referred to as rows 0 and 1, 
    respectively, in combinatorics) have different behaviors from every subsequent row after row 1. These two rows do not follow 
    Pascal's rule of adding two values from the previous row to form a value, as Pascal's rule only begins starting with row 2 (1, 2, 1) 
    (unless you consider imaginary zeroes?).

    This solution first gets past those first two rows, creating their rows individually before applying the algorithmic rule to every 
    subsequent row (if the inputted number, "numRows", allows for it), where the first and last value in the row is 1, and every intermediate 
    value is from the addition of two values in the previous row.

Complexity
Time complexity:
    O(n^2) (average, best and worst) - Scales quadratically with the # of rows as the solution utilizes a loop nested inside a loop, 
    both of which basically run for n number of times.

Space complexity:
    O(n^2) (also average, best and worst) - Also scales quadratically with # of rows because the Pascal's triangle array, "finalArray", 
    is basically just an n-array of n-arrays... (given a large enough n).
*/
