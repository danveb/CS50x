// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
   float bill_after_tax = bill * ( tax / 100.0 ) + bill;
   float bill_after_tax_tip = bill_after_tax * ( tip / 100.0 ) + bill_after_tax;float half = bill_after_tax_tip / 2;
   return half;
}

// make sure to use floating-point division 100.0 instead of 100 because C  incorrectly converts to integer result.

// test: $ check50 cs50/labs/2023/x/half
// style: $ style50 debug.c
// submit: $ N/A