#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_card_number(void);

int get_card_length(long card_number);

int check_sum(long card_number);
int get_sum1(long card);
int get_sum2(long card);

int get_first_digit(long card_number, int n);
int get_second_digit(long card_number, int n);

int main(void)
{
    // Get card number
    long card_number = get_card_number();

    //Checksum
    bool is_valid = check_sum(card_number);

    // Get number of digits
    int card_length = get_card_length(card_number);

    // Get first digit and first-second digit
    int first_digit = get_first_digit(card_number, card_length - 1);
    int first_second_digit = get_first_second_digit(card_number, card_length - 2);

    if (is_valid && card_length == 15 && (first_second_digit == 34 || first_second_digit == 37))
    {
        printf("AMEX\n");
    }
    else if (is_valid && card_length == 16 && (first_second_digit == 51 || first_second_digit == 52  || first_second_digit == 53
    || first_second_digit == 54 || first_second_digit == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (is_valid && (card_length == 13 || card_length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_card_number(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    return card_number;
}

int check_sum(long card_number)
{
    long card = card_number;
    int sum1 = 0;
    int sum2 = 0;
    int total_sum;

    sum1 = get_sum1(card);
    sum2 = get_sum2(card);
    total_sum = sum1 + sum2;

    if (total_sum % 10 == 0)
    {
        return true;
    }

    return false;
}

int get_sum1(long card)
{
    int digit;
    int sum = 0;

    card = card / 10;
    while (card > 0)
    {
        digit = card % 10;
        card = card / 100;
        digit = digit * 2;
        //if digit have second digit, seperate them and add them individually
        if (digit > 9)
        {
            int first_digit;
            int second_digit;

            first_digit = digit % 10;
            digit = digit / 10;
            second_digit = digit % 10;
            digit = first_digit + second_digit;
        }
        sum = sum + digit;
    }
    return sum;
}

int get_sum2(long card)
{
    int digit;
    int sum = 0;

    while (card > 0)
    {
        digit = card % 10;
        card = card / 100;
        //if digit have second digit, seperate them and add them individually
        if (digit > 9)
        {
            int first_digit;
            int second_digit;

            first_digit = digit % 10;
            digit = digit / 10;
            second_digit = digit % 10;
            digit = first_digit + second_digit;
        }
        sum = sum + digit;
    }
    return sum;
}

int get_card_length(long card_number) // get number of digits in card
{
    int digits = 0;
    while (card_number != 0)
    {
        card_number = card_number / 10;
        digits++;
    }
    return digits;
}

int get_first_digit(long card_number, int n)
{
    long card = card_number;
    int digit = 0;

    card = card / pow(10, n);
    digit = card % 10;

    return digit;
}

int get_first_second_digit(long card_number, int n)
{
    long card = card_number;
    int digit = 0;

    card = card / pow(10, n);

    return card;
}