class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long minCost = 0;  // initialize the return variable

        // set int "largerNeed" to need1 if greater, else need2 if greater
        long long largerNeed = (need1 > need2) ? need1 : need2;

        // first assign (check) if just costBoth would fulfill minimum
        minCost = largerNeed * costBoth;

        // next, check type1/type2 adding + costBoth:

        long long currCost = 0;  // initialize new variable for current costs
        long long tempNum = 0;   // initialize new variable for multiplying
        // for the difference in type 1 & 2 needs, add up to the current
        // cost counter until both types need an equal amount of items to
        // reach their needs, then add up to those needs using type 3s (costBoth)
        if(need1 > need2){ 
            tempNum = need1 - need2;
            tempNum *= cost1;
            currCost += tempNum;
            tempNum = need2;
            currCost += tempNum * costBoth;
        }
        else{
            tempNum = need2 - need1;
            tempNum *= cost2;
            currCost += tempNum;
            tempNum = need1;
            currCost += tempNum * costBoth;
        }
        // if this cost is less than historic minimum cost, set it to be new minCost
        if(currCost < minCost){
            minCost = currCost;
        }

        // next, check for if just adding enough type 1 and type 2 (w/o type 3)
        // items fulfills need1 and need2 requirements for less
        currCost = 0;
        tempNum = need1;
        currCost += tempNum * cost1;
        tempNum = need2;
        currCost += tempNum * cost2;
        // if this cost is less than historic minimum cost, set it to be new minCost
        if(currCost < minCost){
            minCost = currCost;
        }


        return minCost;
    }
};
