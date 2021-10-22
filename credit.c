#include <cs50.h>
#include <stdio.h>



int main(void)
{

    int counter = 0; //to store the credit card number of digits
    long n = 0; //to store credit card number
    int sum1 = 0; //to calculate the sum of the last digits
    int s1 = 0; //to store last digit
    int sum2 = 0; //to calculate the sum of second last digits
    int s2 = 0; //to store last digit of the second operation
    int tos2 = 0; //to store last digit*2
    int sumtotal = 0; //sum1 +sum2

    //insert a number and check if it is between 13 and 16 digits
    long number = get_long("Number: ");

    long ccnumber = number;
    while (ccnumber > 0)
    {
        ccnumber = ccnumber / 10;
        counter = counter + 1;
    }
    if (counter != 13 && counter != 15 && counter != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //calculate sum of digits by spliting by 10 and check if last digit of total is 0
   // calculate sum1
   n = number;
   int a;
   int b;
   do
    {
        s1 = n % 10;
        n = n / 10;
        sum1 = sum1 + s1;

    // calculate sum2

        s2 = n % 10;
        n = n / 10;
        tos2 = s2 * 2;
        // check if there are more than a digit
        if (tos2 > 9)
        {
            a = tos2 % 10;
            b = tos2 / 10;
            sum2 = sum2 + a + b;
        }
        else
        {
            sum2 = sum2 +tos2;
        }
    }
    while (n > 0);
    sumtotal = sum1 + sum2;

    //check first digits
    long split; //to divide credit card number and find first two digits
    int firstdigit;
    int first2digit;
    long num = number;
    split = 10;
    for (int p = 0; p < counter - 2; p++)
        {
            split = split * 10;
        }
        firstdigit = num / split;
        first2digit = num / (split / 10);

    if (sumtotal % 10 != 0)
    {
       printf("INVALID\n");
    }
    else if (firstdigit == 4 && (counter == 13 || counter == 16))
        {
            printf("VISA\n");
        }
    else if ((first2digit == 34 || first2digit == 37) && counter == 15)
        {
        printf("AMEX\n");
        }
    else if ((first2digit > 50 && first2digit < 56) && counter == 16)
        {
        printf("MASTERCARD\n");
        }
   else
        {
        printf("INVALID\n");
        }
}