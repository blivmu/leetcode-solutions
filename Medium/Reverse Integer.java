import java.util.ArrayDeque;    // include java's stack library
import java.util.Deque;

class Solution {
    public int reverse(int x) {

        // start by creating a string var "stringX" and assigning it a transformation of x to a string
        String stringX = Integer.toString(x);
        

        // initialize new stack "reversedNums"
        Deque<Character> reversedNums = new ArrayDeque<>();

        // also initialize a boolean, "isNegative" for if the int starts with a negative sign
        boolean isNegative = false;
        int digits = 0;     // and a counter integer for the # of digits (for * (10^n) later)

        // loop through the string-converted-from-int, pushing all of its digits into the stack
        for (char iLuvLeetCode : stringX.toCharArray()){

            // so long as, in the digit, a negative sign doesn't reside there
            if(iLuvLeetCode != '-'){
                reversedNums.push(iLuvLeetCode);    
                digits++;   // also increase digits counter by 1 each time.
            }
            else{   // otherwise set "isNegative" to true
                isNegative = true;
            }
            
        }

        // if(reversedNums.getFirst() == '-'){
        //     reversedNums.pop();
        //     digits--;
        //     isNegative = true;
        // }

        
        long tempNumStorage = 0;

        if(reversedNums.getFirst() == '0'){
            
            if(digits == 1){
                return 0;
            } 
            else{

                reversedNums.pop();
                digits--;
            }
        }

        for(int i = (digits); i > 0; i--){

            long tensPlace = 1;
            for(int j = 1; j < i;  j++){
                tensPlace *= 10;
            }

            if( (Integer.MIN_VALUE > (tempNumStorage + (Character.getNumericValue(reversedNums.getFirst()) * tensPlace))) || (((tempNumStorage + (Character.getNumericValue(reversedNums.getFirst()) * tensPlace)) > Integer.MAX_VALUE)) ){
                return 0;
            } 
            else{
                tempNumStorage += ((long)Character.getNumericValue(reversedNums.pop()) * tensPlace);
            }

        }

        if(isNegative){
            tempNumStorage *= -1;
        }

        return (int)tempNumStorage;
        
    }
}
