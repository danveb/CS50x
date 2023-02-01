#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define a Structure named "person" and initialize string name, number
// we may think "struct" is an object but C is NOT an object-oriented program; in fact it's a procedural language
typedef struct
{
    string name;
    string number;
}
person; // creates datatype "person"

int main(void)
{

    // define array from structure "person"
    person people[2];
    // assign name attribute
    people[0].name = "Carter";
    people[1].name = "David";
    // assign number attribute
    people[0].number = "+1-617-495-1000";
    people[1].number = "+1-949-468-2750";

    string name = get_string("Name: ");

    // Perform linear search
    // iterate through
    for (int i = 0; i < sizeof(people); i++)
    {
        // check: compare name in people[] with name to equal 0
        if (strcmp(people[i].name, name) == 0)
        {
            // we can return the number of person
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}