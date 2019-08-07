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
    int sum = 0;
    
    for (int j = 2; j >= 1; j -= 1) //this loop iterates every two digits. The idea is
        //to change the starting point with this loop so that I can get odd and even-positioned numbers
    {
        long long t = n;
        for (int i = j - 1; t > 0; i += 2)
        {
            long long dec = pow(10, i);
            t = n / dec;
            int remainder = t % 10;
            if (j == 2)
                // here we are doubling every two numbers starting from the second
            {
                remainder *= 2;
            }
            if (remainder > 9)
                // digital sum of products of numbers that have two digits
            {
                int re_1 = remainder % 10;
                remainder /= 10;
                int re_2 = remainder % 10;
                remainder = re_1 + re_2;
            }            
            sum += remainder; //accumulates the sum, which can be done because we already added every digit in the multiplication
        }
        
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (sum % 10 == 0)
    {
        company_check(n);
    }
    
    return 0;
}

void company_check(long long n)
//Calculates length and selects first two digits to know which company issued the card
{
    int length = 0;
    long long t = n;
    //Calculate length by dividing by ten until t is zero
    for (int i = 0; t > 0; i++)
    {
        t /= 10;
        length ++;
    }
    
    // select and check the first two digits of the card number
    int two_digits = n / pow(10, length - 2);
    //checks two_digits with the known types
    if ((length == 15) && ((two_digits == 34) || (two_digits == 37)))
    {
        printf("AMEX\n");
    }
    else if (((length == 13) || (length == 16)) && ((two_digits >= 40) && (two_digits < 50)))
    {
        printf("VISA\n");
    }
    else if ((length == 16) && ((two_digits >= 51) && (two_digits < 56)))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
               
}
