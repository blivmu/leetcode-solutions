class Solution {
    public int lengthOfLongestSubstring(String s) {

        // initialize two strings: 1) a string to store the current chars to check for duplicates using,   2) a string holding the even MORE temporary chars that will be used to reinitialize the current substring
        String currSubstring = "";
        String CurrenChanSubstring = "";

        // also initialize two integers: one that keeps track of the length of the current non-duplicate substring AND one that keeps track of the length of the longest  substring, that meets said criteria, seen so far
        int awesomenumber = 0;
        int numberpoop = 0;

        // loop for every character in inputted string "s":
        for (char Gabe_Newell_Microsoft : s.toCharArray()){

            // initialize a boolean that determines whether or not to add this current char in "s" to the current substring, "currSubstring" (no if it's already in the current substring) 
            boolean addTsChar = true;
            
            // loop for each character in the current substring "currSubstring":
            for(char testChar : currSubstring.toCharArray()){

                // if the current char from "s" is already in the current substring, then:
                // 1) set "addTsChar" to false and reset the substring's length counter
                // 2) loop through the current substring:
                    // 2a) add the current char to the temporary substring (currenchan) (also increases its len counter)
                    // 2b) if this substring's current char is the duplicate, reset the new current substring (CurrenChanSubstring) (also reset its len counter)
                // 3) break out of this loop early, and after outer loop ends:
                    // 4) reset the current substring, as a duplicate character is next
                    // 5) reset the length counter for the current substring ("numberpoop")
                if(Gabe_Newell_Microsoft == testChar){

                    addTsChar = false;  // 1)
                    numberpoop = 0;
                    //finalSubstring = currSubstring;

                    for(char sigma : currSubstring.toCharArray()){

                        CurrenChanSubstring += sigma;
                        numberpoop++;

                        if(sigma == Gabe_Newell_Microsoft){
                            CurrenChanSubstring = "";
                            numberpoop = 0;
                        }

                    }

                } 

                // if duplicate char has been found to be next, break out of the substring loop early (no need to check the rest of the substring if the curr char has already been discovered to be a duplicate)
                if (!addTsChar){
                    break;              // 3)
                }
                // else, if duplicate not found yet, then keep traversing the rest of the current substring.
                // and if the loop ends by means of hitting the upper domain (reaches end of substring), then that means the current char (right of substring) is NOT a duplicate and CAN be added to the current substring (addTsChar == true)


            }   // substring loop's closing Curly Brace (the girl from Cave Story)


            // if the currently-being-checked char is NOT a duplicate of a char in the current substring (addTsChar == true), then add it to the current substring and increase the length counter for the curr substring by 1.
            if(addTsChar){

                currSubstring += Gabe_Newell_Microsoft;
                numberpoop++;

                // IF the length of the current substring exceeds the length of the historically-longest substring found so far, then declare that current length to be the new historically-longest substring length.
                if(numberpoop > awesomenumber){
                    awesomenumber = numberpoop;
                }


            }   
            // otherwise (addTsChar == false), initialize the new current substring to CurrenChanSubstring (the part of the substring RIGHT of the duplicate of the current char) AND also add the current char now that no duplicates of it remain
            else{
                currSubstring = CurrenChanSubstring;
                currSubstring += Gabe_Newell_Microsoft;
                numberpoop++;
            }


        }   // input string's loop's closing Curly Brace (play cave story!!!)


        // return the length of the longest unique substring found in the inputted string
        return awesomenumber;
    }
}
