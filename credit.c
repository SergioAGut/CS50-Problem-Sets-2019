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
}
