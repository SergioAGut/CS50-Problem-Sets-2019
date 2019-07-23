/**
 ** 
 ** cs50
 ** week 1
 ** credit.c assignment
 ** http://docs.cs50.net/2017/x/psets/1/pset1.html
 **
 ** by: Sergio A. Gutierrez
 ** 
 ** A program for checking the validity and type of a given credit card number
 ** 
 ** 
 **/
#include <cs50.h>
#include <stdio.h>
#include <math.h>

void company_check(long long n);

int main(void)
{
    long long n = get_long("Number: ");
    //long long t = n
    int sum = 0;
    
    for (int j = 2; j >= 1; j -= 1)
    {
        long long t = n;
        for ( int i = j - 1; t > 0; i += 2)
        {
            long long dec = pow(10, i);
            t = n / dec;
            int remainder = t % 10;
            if (j == 2)
            {
                remainder *=2;
            }
            if (remainder > 9)
            {
                int re_1 = remainder % 10;
                remainder /= 10;
                int re_2 = remainder % 10;
                remainder = re_1 + re_2;
            }            
            sum += remainder;
        }
        
    }
    if (sum % 10 != 0)
    {
        printf("INVALID");
    }
    else
    {
        printf("Great! It is working\n");
    }
    company_check(n);
}

void company_check(long long n)
    //Calculates length and selects first two digits to know which company issued the card
{
    int length = 0;
    long long t = n;
    //Calculate length by dividing by ten until t is zero
    for (int i = 0; t > 0; i++ )
    {
        t /= 10;
        length ++;
    }
    printf("The length of card is %i\n", length);
    
    // select and check the first two digits of the card number
    int two_digits = n / pow(10, length - 2);
    //checks two_digits with the known types
    if ((length == 15) &&((two_digits == 34) || (two_digits == 37)))
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if(((length == 13) || (length == 16)) && ((two_digits >= 40) && (two_digits < 50)))
    {
        printf("VISA\n");
    }
    else if ((length == 16) && ((two_digits >= 51) && (two_digits < 56)))
    {
        printf("MASTERCARD\n");
    }
               
}
