// Initially, I came up with an invalid solution that simply found the first equal/greater height to the right of the current height, 
// and moving the new current height to that (after adding all rain squares between first), all the way until there are no 
// greater/equal heights left in the array to the right of the current height.

// This just didn't work because I neglected the fact that there can STILL be rain squares between the current wall and a shorter wall 
// to its right. I fixed this by implementing two cases, where one is if it finds a height >= current height, and one for if that doesn't 
// find anything, it then finds the next greatest height to the right of current height, and fills in the rain squares between them 
// (also changing the current height/wall to the previous right one). 

class Solution {
public:
    int trap(vector<int>& height) {
        
        // get rid of edge case for if there are 2 or less heights (not possible to collect any rain water)
        if(height.size() < 3){
            return 0;
        }

        int rainSquares = 0;    // initialize return variable

        // "i" is the left wall throughout the solution
        for (int i = 0; i < height.size();){
            
            // get height of left wall (i)
            int currMin = height[i];
            
            // initialize variables for right wall's index and height 
            int currMax = 0;
            int currMaxIndex = 0;

            // loop through rest of array (starting from 1 to right of left wall) to find the first wall (height) that's equal to or more than current left wall
            for(int j = (i + 1); j < height.size(); j++){
                if(height[j] >= currMin){
                    currMax = height[j];
                    currMaxIndex = j;
                    break;
                }
            }

            // if currMax is still less than currMin (no height greater than or equal to current left wall's height was found in the rest of the array),
            if(currMax < currMin){
                // then find the NEXT greatest height from this left wall (that's less than it, if it ends up here)
                for(int j = (i + 1); j < height.size(); j++){
                    if(height[j] > currMax){
                        currMax = height[j];
                        currMaxIndex = j;
                    }
                }

                // and find all the rain squares that can be filled up between that next greatest height (right wall) and the current left wall (differences between tallest enclosing wall, which is right wall here and every height between walls), adding to the global rainSquares variable
                for(int k = (i + 1); k < currMaxIndex; k++){
                    rainSquares += (height[currMaxIndex] - height[k]);
                }

            } 
            // else (a taller/equal right wall was found to enclose the current left wall), 
            else{
                // simply find all the differences in height from the current left wall and every height between the walls (adding to rainSquares)
                for(int j = (i + 1); j < currMaxIndex; j++){
                    rainSquares += (height[i] - height[j]);
                }

            }
            
            // if an enclosing (right) wall was found for the height at index [i], then set the new "i" (the left wall of the next loop iteration) to that right wall's index
            if(currMaxIndex > 0){
                i = currMaxIndex;
            }
            // otherwise, simply increment i++ and try that for the new left wall
            else{
                i++;
            }

            
        }

        return rainSquares;
    }
};


/////   failed first solution:   /////

/*



class Solution {
public:
    int trap(vector<int>& height) {
        
        // get rid of edge case for if there are 2 or less heights (not possible to collect any rain water)
        if(height.size() < 3){
            return 0;
        }

        int rainSquares = 0;    // initialize return variabl

        for(int i = 0; i < height.size() - 1;){

            int j = i + 1;   // initialize a variable for the curr. closing height

            // find the index of the closing height (>=) for the height at index [i],
            while(height[j] < height[i]){

                // if no closing height for height[i] left in the array, then leave loop (and set j = -1)
                if((j + 1) >= height.size()){
                    j = -1;
                    break;
                } 

                // else, if "j" is still within domain of array, then increment it to check the next index to see if it closes the height at height[i]
                else{   
                    j++;
                }

            }
            // now, if a successful closing height was found for height[i], its index will be held in var. "j", otherwise j = -1 (meaning "not found in rest of array")

            // if j =/= -1, then it means a successful closing height was found to the right of index i in the array
            if(j != -1){
                
                // and because the rain only fills up to the height of the lower closing wall (out of the two closing walls, or either if even heights), we find the difference in height between that lower height and each individual height between the two closing walls, adding that difference to the total rain squares (rainSquares)
                    // "i" = left wall, "j" = right wall, start loop with one to right of "i"
                for(int z = (i + 1); z < j; z++){
                    rainSquares += (height[i] - height[z]);
                }
                // if the two walls are adjacent to each other (no other heights in between), then this loop doesn't run and nothing is added to rainSquares

                // and once all rain squares are found between the two walls, set "i" to the right wall, such that the loop reiterates beginning at the index of the right wall (j), now finding any closing walls for that.
                i = j;

            }
            // else, if no successful closing wall could be found for height[i], then move right by 1 and try closing height for that height (until end of "height" array)
            else{
                i++;
            }


        }
        
        return rainSquares;
    }
};



*/
