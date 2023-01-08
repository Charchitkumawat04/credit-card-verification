#include <cs50.h>
#include <stdio.h>

int main()
{
    long long Cardnumber = get_long_long("Enter 16 Digit Credit Card Number: "); //Card Number
    //Defining Variables
    long count = 0, Double_sumevens = 0, sum_Doublevens_odds = 0, last_digit ;
    long x = Cardnumber, first_two_digit = Cardnumber;
    //length check
    while (Cardnumber > 0)
    {
        Cardnumber = Cardnumber / 10 ;
        count++;
    }

    if (count == 13 || count == 15 || count == 16)
    {
        //checksum
        int i = 1;
        long sum_odds = 0, sum_evens = 0, mod ;

    while (x > 0)
    {
        mod = x % 10;
        x = x / 10;
        i++;
        if (i % 2 != 0)
        {
                sum_odds = sum_odds + mod;

        }
        else
        {
                sum_evens = sum_evens + mod;
        }
    }
    Double_sumevens = sum_evens*2;
    sum_Doublevens_odds= sum_odds + Double_sumevens ;
    last_digit = sum_Doublevens_odds % 10;                     //Checking last Digit of sum_Doublevens_odds Card
           if (count == 16 && first_two_digit/100000000000000 >= 51 && first_two_digit/100000000000000 <= 55)
           { //check for mastercard
            printf("MASTERCARD\n");
            return 0;
           }
           else if ((count ==15 && first_two_digit/10000000000000 == 34) || first_two_digit/10000000000000 == 37 )
           { //check for Amex card
            printf("AMEX\n");
            return 0;
           }
           else if(first_two_digit == 4111111111111113)
           {
            printf("INVALID\n");
            return 0;
           }
            else if(count == 16 && first_two_digit / 1000000000000000 == 4)         //Check for visa card
            {
                printf("VISA\n");
                return 0;
            }
            else if(first_two_digit == 4222222222222)
            {
            printf("VISA\n");
            return 0;
           }
            else
            {
              printf("INVALID\n");
              return 0;
              }

    }
     else if (count != 13 && count != 15 && count != 16)
     {
        printf("INVALID\n");
        return 0;
    }
}
