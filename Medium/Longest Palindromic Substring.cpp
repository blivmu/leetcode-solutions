class Solution {
public:
    string longestPalindrome(string s) {
        // the following solution ONLY works for input strings with at least 3 characters
        // so, start by getting rid of strings with lengths of 1 or 2 (constraints state that s.length == 1 at minimum)

        // get rid of one-length string inputs (return itself)
        if(s.length() == 1){
            return s;
        }

        // initialize a vector array "List" that will hold each char in the input string
        vector<char> List;

        // get rid of two-length string inputs
        if(s.length() == 2){
            // use the vector array to put both characters in
            for(char letter : s){
                List.push_back(letter);
            }
            // if both characters are the same, return the whole input string
            if(List[0] == List[1]){
                return s;
            } 
            // else, just return the first character (using a temp string var)
            else{
                string HashireUmamusume = "";
                HashireUmamusume += List[0];
                return HashireUmamusume;
            }
        }
        // if the program makes it this far, then it can be assumed that the length of "s" is at least 3

        // initialize var for the return string (historically longest palindromic string)
        string longestStr = "";
        // initialize var for the currently-being-checked string
        string currStr = "";

        // initialize the vector array with every character in the input string "s"
        for(char letter : s){
            List.push_back(letter);
        }

        // loop through the entire array (checking from each and every single character)
            // IDEA: with the current character (in array) as the middle, check if every character on its left and right (of equal distance) are the same, if:
                // YES: then add it to currString (add it twice, one on each end of the current currStr).  
                // NO: then end the checking loop for this current middle char, and check to see if the currStr up to this point of loop-end is longer than longestStr (historically longest palindromic string found within the input string)
            // NOTE: this idea above works only if the middle char is not a palindromic itself/around it... meaning that it's not adjacent to itself (same char).
                // to fix this, i added a first-check to see if the middle is a palindrome, and if so, then check from both the left and right ends of the palindrome (using the following two pointers, k & j) such that the middle being checked right now is of length == 2
        for(int i = 0; i < List.size(); i++){
            // reset "currStr", and then initialize it to the current middle char, list[i]
            currStr = "";
            currStr += List[i];

            // initialize the two pointers to begin at the middle char (k = left, j = right)
            int k = i;
            int j = i;

            // initial checks for if the middle is also a palindrome, and if so, then move the initialization for the respective pointer (k / j), where "k" is the left and "j" is the right (they will traverse in those directions during the search)
                // also if middle palindrome is found, then add it to the list
                // ALSO it makes sure to see if middle palindrome is only of size 2 (if both sides of the single-middle are also the same char as the single-middle, then it skips it and the loop below handles it)
            // if NOT BOTH sides == the same char as single-middle: (see in "if" statement)
            // (start by creating boolean values to see if left/right of "i" are valid indices in array AND if the respective indices are equal to index [i])
            bool leftTruke = ( ((i - 1) >= 0) && (List[i - 1] == List[i]) );
            bool rightTruke = ( ((i + 1) < List.size()) && (List[i + 1] == List[i]));
            if(!(leftTruke && rightTruke)){
                // NOTE: the while loops below are for edge-cases where the middle palindrome is 4 (or more, 2*n) of the same char (such as "aaaa")
                    // it took a helluva lot of failed submissions to get this fix
                
                // check if left makes the middle an even-length palindrome
                while(leftTruke){
                    k--;
                    currStr += List[i];
                    if( !( ((k - 1) >= 0) && (List[k - 1] == List[i]) ) ){
                        leftTruke = false;
                    }
                }

                // check if right makes the middle an even-length palindrome
                while(rightTruke){
                    j++;
                    currStr += List[i];
                     if( !( ((j + 1) < List.size()) && (List[j + 1] == List[i]) ) ){
                        rightTruke = false;
                    }
                }

            }

            // initialize the loop by checking to see if the indices to the left of k and the right of j are within the domain of the array, and then moving them one over respectively if they are
            if( ((k - 1) >= 0) && ((j + 1) < List.size() )){
                k--;
                j++;

                // looping through the array in both directions, starting from the middle (current char/index "i" in array), checking to see if the two pointers (k & j) point to equal chars (ends if doesn't)
                while( ( (k >= 0) && (j < List.size()) ) && (List[k] == List[j]) ){
                    // if k = j, then add that equal-char to both ends of the current currStr
                    currStr = (List[k] + currStr + List[k]);

                    // move both pointers by 1 index, and then check to see if they're outside the array's domain (breaks out of loop early if yes)
                    k--;
                    j++;
                    if( (k < 0) || (j >= List.size()) ){
                        break;
                    }
                }
            }

            // finally, check to see if this current palindrome is longer than the longest palindrome found in the array (if yes, then set historic longest to it)
            if(currStr.length() > longestStr.length()){
                longestStr = currStr;
            }

        }

        // return the historic longest palindrome found in the input string "s"
        return longestStr;
    }
};
