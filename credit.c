//cs50 header file
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void isCardValid(long long number);
int howLongIsInput(long long n);
int firstTwoDigits(long long num);
long long input;

int main(void)
{
    //take input via cs50s get_long_long
    input = get_long_long("Number: ");

    //checking card is valid
    isCardValid(input);
}
void isCardValid(long long number)
{
    // Multiply every other digit by 2
    //  starting with the number’s second-to-last digit
    //  and then add those products’ digits together.
    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to
    // 0), the number is valid!

    int check = firstTwoDigits(number);
    int multiplyDigits = 0;
    int nonMultiplydigits = 0;
    int everyDigitmultiply = 0;
    int finalsum = 0;
    int n = howLongIsInput(number);

    for (int i = 0; i < n; i++)
    {
        multiplyDigits = 0;
        nonMultiplydigits += number % 10;
        number = number / 10;
        multiplyDigits += number % 10;
        multiplyDigits = multiplyDigits * 2;
        number = number / 10;
        if (multiplyDigits >= 10)
        {
            int a, b;
            a = multiplyDigits % 10;
            multiplyDigits = multiplyDigits / 10;
            b = a + multiplyDigits;
            everyDigitmultiply += b;
        }
        else
        {

            everyDigitmultiply += multiplyDigits;
        }
    }
    finalsum = everyDigitmultiply + nonMultiplydigits;

   //All American Express numbers start with 34 or 37
    if ((check == 34 || check == 37) && (n == 15))
    {
        if (finalsum % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //most MasterCard numbers start with 51, 52, 53, 54, or 55
    // (they also have some other potential starting numbers which we won’t concern ourselves with for this problem)
    else if ((check >= 51 && check <= 55) && n == 16)
    {
        if (finalsum % 10 == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //all Visa numbers start with 4
    else if ((check >= 40 && check <= 49) && (n == 13 || n == 16))
    {
        if (finalsum % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

//find length of an input
int howLongIsInput(long long n)
{
    if (n == 0)
        return 1;
    return floor(log10(llabs(n))) + 1;
}


//find first two digits of an input
int firstTwoDigits(long long num)
{
    long long abs_num = llabs(num); // Work with the absolute value initially

    while (abs_num >= 100)
    {
        abs_num /= 10;
    }
    // Restore the original sign
    if (num < 0)
    {
        return (int) -abs_num;
    }
    else
    {
        return (int) abs_num;
    }
}
