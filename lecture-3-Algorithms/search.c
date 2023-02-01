#include <cs50.h>
#include <stdio.h>
#include <string.h>

// int main(void)
// {
//     // initialize static numbers array of size based on values inside
//     int numbers[] = {20, 500, 10, 5, 100, 1, 50};
//     int n = get_int("Number: ");

//     // linear search
//     // iterate through input array from i at 0 until end of array
//     for (int i = 0; i < sizeof(numbers)/sizeof(int); i++)
//     {
//         // check: if current element at i == "n"
//         if (numbers[i] == n)
//         {
//             printf("Found\n");
//             return 0; // success
//         }
//     }
//     printf("Not Found\n");
//     return 1; // error
// }

int main(void)
{
    // initialize strings array
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    string s = get_string("String: ");
    for (int i = 0; i < sizeof(strings)/sizeof(string); i++)
    {
        // check: if current element at i == "s"
        // C: we need to use strmp (string compare) to check if current element is same as "s" and equal to 0
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0; // success
        }
    }
    printf("Not Found\n");
    return 1; // error
}