// LeetCode 29. Divide Two Integers
// Medium

#include <limits>
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Special case: overflow.
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        
        int quotient = 0; 
        
        // sign of the numbers
        int sign = +1;
        
        if (dividend < 0 ^ divisor < 0) {
            // XOR is used to determine the sign of the final result
            sign = -1;
        }
                        
        // convert all the numbers to negative
        if (dividend > 0) {
            dividend = -dividend; 
        }
        
        if (divisor > 0) {
            divisor = -divisor; 
        }
                
        // relaxing search
        // remainder = dividend - multiple * divisor where multiple = 2^m
        int remainder = dividend;
        
        while (remainder <= divisor) {
            
            if (remainder == divisor) {
                quotient++; 
                break; 
            }
            
            int multiple = 1;                         
            while (remainder < multiple * divisor && multiple * divisor >= half_int_min) {
                // every left shift (or multiply by 2) result in a lower number
                multiple = multiple<<1; 
            }
            // since the current multipe leads to a number 
            // that is smaller than the current remainder
            if (multiple != 1) {
                multiple = multiple>>1;     
            }            
            
            quotient += multiple;             
            remainder -= multiple * divisor; // remainder get smaller             
        }
        
        // apply the sign to the result
        quotient = sign == +1 ? quotient : -quotient; 
        
        return quotient; 
        
    }

private:
    int half_int_min = INT_MIN>>2; 
};