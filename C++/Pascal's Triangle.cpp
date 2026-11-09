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
