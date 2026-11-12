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

/*
At first glance, I could instantly tell there were only three different costs that would need to be checked to always get the right output:

All type 3 items
Mix of just enough type 3 items (to fulfill the requirement of the lower-requirement item) and the remaning requirement's respective item.
No type 3 items at all, instead just type 1 and 2 items only.
I don't know how to explain it, but I can instantly tell that the initial suspicion of "what about a random mix of type 1 and type 2 items combined with the remaining being fulfilled by type 3 items?" was false, because case #3 above instantly disproves the existence of such a case.

Approach
Solution operates in these steps:

Case #1: Set minCost to be if the cost only consisted of the minimum number of type 3 items required to meet both need1 and need2.
Case #2: Find the difference between the required type1 (need1) and type2 (need2) items. For the higher-requirement one, add enough of it currently to make that difference zero (such that the current number of type1 and type2 items still required are equal). Now, add enough of type3 items to make them both meet their requirements simultaneously.
If the cost from case #2 is less than the cost of case #1, then the cost from case #2 is the new minCost.
Case #3: Find the cost if it only consists of type 1 and 2 items, just enough for each to fulfill their respective requirements.
If the cost from case #3 is less than the previous minCost, then case #3's cost is the new minCost.
Return minCost (answer)
Complexity
Time complexity:
O(1), no looping or anything, just raw operations.

Space complexity:
Probably O(1) as well but not as ideally? (Because of all the long long variables being used)
*/
