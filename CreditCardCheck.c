// Checks if inputed credit card number is valid or not using Luhn's algorithm and also identifies which bank it belongs too
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    // Prompt user for number
    long creditNum;
    do
    {
        creditNum = get_long("Number: ");
    }
    while (creditNum < 0);
    
    // Set credit card number divided by 10 to ensure we get every other digit
    long creditNum2 = creditNum / 10, sum = 0;
    int digitsCounter = 0;
    
    // loop gets every other digit starting from the end of the credit card number, gets half the number of digits, and the sum of every other number multiplied and split if necessary
    while (creditNum2 > 1)
    {
        long digit = creditNum2 % 10;
        digit = digit * 2;
        creditNum2 /= 100;
        
        if (digit >= 10)
        {
            long digit2 = 0;
            digit2 = digit / 10;
            sum += digit2;
            digit = digit % 10;
        }
        sum += digit;
        digitsCounter++;
    }
    
    
    long creditNum3 = creditNum, sum2 = 0;
    int digitsCounter2 = 0;
    
    // Second loop to get the other half of the numbers, number of other half of digits, and the sum of the other half of the numbers
    while (creditNum3 > 1)
    {
        long digit3 = creditNum3 % 10;
        creditNum3 = creditNum3 / 100;
        sum2 += digit3;
        digitsCounter2++;
    }
    
    // Total number of digits and total sum
    int numOfDigits = digitsCounter + digitsCounter2;
    long sum3 = sum + sum2;
    
    // Checks if credit card number is valid and which company it's from
    if ((sum3 % 10 == 0 && numOfDigits == 15 && creditNum / 10000000000000 == 34) || (sum3 % 10 == 0 && numOfDigits == 15 && creditNum / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if ((sum3 % 10 == 0 && numOfDigits == 16 && creditNum / 100000000000000 == 51) || (sum3 % 10 == 0 && numOfDigits == 16 && creditNum / 100000000000000 == 52) || (sum3 % 10 == 0 && numOfDigits == 16 && creditNum / 100000000000000 == 53) || (sum3 % 10 == 0 && numOfDigits == 16 && creditNum / 100000000000000 == 54) || (sum3 % 10 == 0 && numOfDigits == 16 && creditNum / 100000000000000 == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((sum3 % 10 == 0 && numOfDigits == 13 && creditNum / 1000000000000 == 4) || (sum3 % 10 == 0 && numOfDigits == 16 && creditNum / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
      
}
