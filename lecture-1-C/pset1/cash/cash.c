#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // initialize cents as integer
    // perform a do... while loop
    // condition is if cents are less than 0 we repeat
    int cents;
    do
    {
        cents = get_int("Enter number of cents: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // initialize quarter as integer at 25c
    // initialize r as cents / quarter
    // while r > 0 we can return r
    int quarter = 25;
    int r = cents / quarter;
    while (r > 0)
    {
        return r;
    }
    return 0;
}

int calculate_dimes(int cents)
{
    // initialize dime as integer at 10c
    int dime = 10;
    int r = cents / dime;
    while (r > 0)
    {
        return r;
    }
    return 0;
}

int calculate_nickels(int cents)
{
    // initialize nickel as integer at 5c
    int nickel = 5;
    int r = cents / nickel;
    while (r > 0)
    {
        return r;
    }
    return 0;
}

int calculate_pennies(int cents)
{
    // initialize penny as integer at 1c
    int penny = 1;
    int r = cents / penny;
    while (r > 0)
    {
        return r;
    }
    return 0;
}

// test: $ check50 cs50/problems/2023/x/cash
// style: $ style50 cash.c
// submit: $ submit50 cs50/problems/2023/x/cash