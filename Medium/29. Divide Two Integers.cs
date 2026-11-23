public class Solution {
    public int Divide(int dividend, int divisor) {


        // IDEA: multidimensional? like double the divisor each time until that 
        // increased divisor > whats left of the dividend, then backtrack down the doubled divisor values for as long as dividend < divisor. increase the quotient respectively by "how many times that divisor has been doubled by"
        long quotient = 0;
        bool isNegative = false;

        if ((dividend == -2147483648) && (divisor == -1)){
            return 2147483647;
        }
        if ((dividend == -2147483648) && (divisor == 1)){
            return -2147483648;
        }

        long Ldividend = (long)dividend;
        long Ldivisor = (long)divisor;

        // if both divisor and dividend are negative, turn them both positive
        if(divisor < 0 && dividend < 0){
            Ldivisor = 0 - Ldivisor;
            Ldividend = 0 - Ldividend;
        }
        else if(divisor < 0){
            Ldivisor = 0 - Ldivisor;
            isNegative = true;
        }
        else if (dividend < 0){
            Ldividend = 0 - Ldividend;
            isNegative = true;
        }

        long div2 = Ldivisor + Ldivisor;
        long div4 = div2 + div2;
        long div8 = div4 + div4;
        long div16 = div8 + div8;
        long div32 = div16 + div16;
        long div64 = div32 + div32;
        long div128 = div64 + div64;

        while(Ldividend >= div128){
            Ldividend -= div128;
            quotient += 128;
        }

        while(Ldividend >= div64){
            Ldividend -= div64;
            quotient += 64;
        }

        while(Ldividend >= div32){
            Ldividend -= div32;
            quotient += 32;
        }

        while(Ldividend >= div16){
            Ldividend -= div16;
            quotient += 16;
        }

        while(Ldividend >= div8){
            Ldividend -= div8;
            quotient += 8;
        }

        while(Ldividend >= div4){
            Ldividend -= div4;
            quotient += 4;
        }

        while(Ldividend >= div2){
            Ldividend -= div2;
            quotient += 2;
        }

        while(Ldividend >= Ldivisor){
            Ldividend -= Ldivisor;
            quotient++;

            if( (quotient > 2147483648) && isNegative) {
                return -2147483648;
            }
            else if((quotient > 2147483647) && (!isNegative)){
                return 2147483647;
            }
        }


        if(isNegative){
            quotient = 0 - quotient;
        }


        return (int)quotient;
    }

}
