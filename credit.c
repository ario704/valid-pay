#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long j = 0;
    long digits, digits2 = 0;
    int timestwo = 0;
    int sum = 0;
    int a, b = 0;
    int len = 0;
    // Checksum:
    // second to last numbers:
    for (long i = 100; i < number * 10; i *= 100)
    {
        len += 1;
        j = i / 10;
        digits = number % i;
        digits = digits / j;
        // printf("%ld ", digits);
        timestwo = digits * 2;
        // printf("%i ", timestwo);
        if (timestwo < 10)
        {
            sum += timestwo;
        }
        else
        {
            a = timestwo % 10;
            b = a + 1;
            sum += b;
        }
    }
    // other numbers:
    for (long i = 10; i < number * 10; i *= 100)
    {
        len += 1;
        j = i / 10;
        digits2 = number % i;
        digits2 = digits2 / j;
        sum += digits2;
    }
    if (sum % 10 == 0)
    {
        if (digits2 == 3 && len == 15)
        {
            if (digits == 4 || digits == 7)
            {
                printf("AMEX\n");
            }
            else
                printf("INVALID\n");
        }
        else if (digits == 5 && len == 16)
        {
            if (digits2 > 0 && digits2 < 6)
            {
                printf("MASTERCARD\n");
            }
            else
                printf("INVALID\n");
        }
        else if (len == 13 && digits2 == 4)
        {
            printf("VISA\n");
        }
        else if (len == 16 && digits == 4)
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
