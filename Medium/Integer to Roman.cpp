class Solution {
public:
    string intToRoman(int num) {

        int I, V, X, L, C, D, M;

        int numLeft = num;
        string result = "";
        
        if(numLeft / 1000 > 0){
            M = numLeft / 1000;
            numLeft -= (1000 * M);
            for(int i = 0; i < M; i++)
                result += 'M';
        } 

        if (numLeft / 100 == 9){
            result += 'C';
            result += 'M';
            numLeft -= 900;
        }
        else if(numLeft / 100 == 4){
            result += 'C';
            result += 'D';
            numLeft -= 400;
        }
        else{
            if(numLeft / 500 > 0){
                result += 'D';
                numLeft -= 500;
            }
            if(numLeft / 100 > 0){
                C = numLeft / 100;
                numLeft -= (100 * C);
                for(int i = 0; i < C; i++)
                    result += 'C';
            }
        }

        if(numLeft / 10 == 9){
            result += 'X';
            result += 'C';
            numLeft -= 90;
        }
        else if(numLeft / 10 == 4){
            result += 'X';
            result += 'L';
            numLeft -= 40;
        }
        else{
            if(numLeft / 50 > 0){
                result += 'L';
                numLeft -= 50;
            }
            if(numLeft / 10 > 0){
                X = numLeft / 10;
                numLeft -= (10 * X);
                for(int i = 0; i < X; i++)
                    result += 'X';
            }
        }

        if(numLeft == 9){
            result += 'I';
            result += 'X';
            numLeft -= 9;
        }
        else if(numLeft == 4){
            result += 'I';
            result += 'V';
            numLeft -= 4;
        }
        else{
            if (numLeft / 5 > 0){
                result += 'V';
                numLeft -= 5;
            }
            if (numLeft > 0){
                for (int i = 0; i < numLeft; i++){
                    result += 'I';
                }
            }
        }

        return result;


    }
};

/*
Intuition
  At first, I thought about my hatred for the Romans and their numerical system. So, I used that animosity to 
  lock in and DESTROY this problem through sheer brute force. The ANGER coarsing through my VEINS is currently 
  flowing too greatly for me to sit down and come up with a more efficient algorithm.

Approach
  With a lot of if/else statements (YandereDev style), I get rid of every edge-case along the way down the 
  number (number places starting with 4 || 9). Only when a number place doesn't start with a 4 nor a 9, nor 
  is greater than 5 (else there'll also be ONE of its 5xxxx place letter), does the counting of the base letter 
  begin (1xxxx).

Complexity
Time complexity:
  O(1), time usage only increases critically with # of digits in a decimal (base-10) number. Thus, the worst case 
  scenario is O(log n), where the log function is the common logarithm (base-10) (not than the base-2 logarithm 
  commonly assumed in computing).

Space complexity:
  O(1)
*/
