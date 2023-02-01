/* Algorithms

- Algorithms are programs that take an input and return an output

Example: array[] of values and our target is 50

Linear Search -> input array is NEVER sorted
For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false


Binary Search -> input array needs to be sorted in advance
If no doors
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] through doors[middle-1]
Else if 50 > doors[middle]
    Search doors[middle+1] through doors[n-1]

Big O Notation
- running time involves analysis with Big O Notation
- we only care about the worst case scenario for algorithm to run
-> O(n^2) quadratic
-> O(n log n) n log n
-> O(n) linear
-> O(log n) log n
-> O(1) constant

Best Case Scenarios (lowerbound)
- omega symbol

Worst/Best Case Scenarios (upper & lowerbound)
- theta symbol

Data Structures
- C allows us to create our own data structure via "struct"

// Define a Structure named "person" and initialize string name, number
// we may think "struct" is an object but C is NOT an object-oriented program; in fact it's a procedural language
typedef struct
{
    string name;
    string number;
}
person; // creates datatype "person"

Sorting
- act of taking an unsorted list of values and transform the list into a sorted one
- we can use binary search on a sorted list, but not on an unsorted list

1. Selection sort (small to largest) -> worst case O(N^2)
- select the smallest element and keep track of it
- keep looping and correctly fit into right place
- swap places with largest value
- continue process...
** ULTIMATELY it takes n-1 + n-2 + n-3... + 1 = n(n-1)/2 -> O(n^2) Time complexity

For i from 0 to n-1 (begin to end of array)
    Find smallest number between nums[i] and nums[n-1]
    Swap smallest number with nums[i]

Given array[] = {5, 2, 7, 4, 1, 6, 3, 0};
1. select smallest element and swap current position

  5 2 7 4 1 6 3 0
  ^                 -> current at i
  x                 -> smallest = 5; keep going
    x               -> smallest = 2; keep going
      x             -> smallest = 7; keep going
        x           -> smallest = 4; keep going
          x         -> smallest = 1; keep going
            x       -> smallest = 6; keep going
              x     -> smallest = 3; keep going
                x   -> smallest = 0 we will swap with current position at i (5)

  0 | 2 7 4 1 6 3 5
      ^             -> current at i
        x
          x
            x       -> smallest = 1; swap with position at i (2)
              x
                x
                  x

  0 1 | 7 4 2 6 3 5
        ^           -> current at i
          x
            x       -> smallest = 2; swap with current position at i (7)
              x
                x
                  x

  0 1 2 | 4 7 6 3 5
          ^         -> current at i
            x
              x
                x   -> smallest = 3; swap with current position at i (4)
                  x

  0 1 2 3 | 7 6 4 5
            ^       -> current at i
              x
                x   -> smallest = 4; swap with current position at i (7)
                  x

  0 1 2 3 4 | 6 7 5
              ^     -> current at i
                x
                  x -> smallest = 5; swap with current position at i (6)

  0 1 2 3 4 5 | 7 6
                ^   -> current at i
                  x -> smallest = 6; swap with current position at i (7)

  0 1 2 3 4 5 6 7


2. Bubble sort -> O(n^2)
- larger elements "bubble" to the end
- we compare first element to second element; first < second ? we keep : we switch places
- keep looping
** IF INPUT ARRAY IS SORTED WE CAN PERFORM O(log n) TIME COMPLEXITY

Repeat n-1 times
For i from 0 to n-2
    If nums[i] and nums[i+1] out of order
        Swap them
    If no swaps
        Quit

  5 2 7 4 1 6 3 0
  ^ ^               -> compare 5 vs. 2; if out of order we swap

  2 5 7 4 1 6 3 0
    ^ ^             -> compare 5 vs. 7; in order so we continue

  2 5 7 4 1 6 3 0
      ^ ^           -> compare 7 vs. 4; if out of order we swap

  2 5 4 7 1 6 3 0
        ^ ^         -> compare 7 vs. 1; if out of order we swap

  2 5 4 1 7 6 3 0
          ^ ^       -> compare 7 vs. 6; if out of order we swap

  2 5 4 1 6 7 3 0
            ^ ^     -> compare 7 vs. 3; if out of order we swap

  2 5 4 1 6 3 7 0
              ^ ^   -> compare 7 vs. 0; if out of order we swap

  2 5 4 1 6 3 0 7
                x   -> 7 is highest number so we'll work on remaining

  2 5 4 1 6 3 0 | 7
  ^ ^               -> compare 2 vs. 5; in order

  2 5 4 1 6 3 0 | 7
    ^ ^             -> compare 5 vs. 4; swap

  2 4 5 1 6 3 0 | 7
      ^ ^           -> compare 5 vs. 1; swap

  2 4 1 5 6 3 0 | 7
        ^ ^         -> compare 5 vs. 6; in order

  2 4 1 5 6 3 0 | 7
          ^ ^       -> compare 6 vs. 3; swap

  2 4 1 5 3 6 0 | 7
            ^ ^     -> compare 6 vs. 0; swap

  2 4 1 5 3 0 6 | 7
              x     -> 6 is lower than 7; work on remaining

  2 4 1 5 3 0 | 6 7
  ^ ^               -> compare 2 vs. 4; in order

  2 4 1 5 3 0 | 6 7
    ^ ^             -> compare 4 vs. 1; swap

  2 1 4 5 3 0 | 6 7
      ^ ^           -> compare 4 vs. 5; in order

  2 1 4 5 3 0 | 6 7
        ^ ^         -> compare 5 vs. 3; swap

  2 1 4 3 5 0 | 6 7
          ^ ^       -> compare 5 vs. 0; swap

  2 1 4 3 0 5 | 6 7
            x       -> 5 is lower than 6, 7; work on remaining

  2 1 4 3 0 | 5 6 7
  ^ ^               -> compare 2 vs. 1; swap

  1 2 4 3 0 | 5 6 7
    ^ ^             -> compare 2 vs. 4; in order

  1 2 4 3 0 | 5 6 7
      ^ ^           -> compare 4 vs. 3; swap

  1 2 3 4 0 | 5 6 7
        ^ ^         -> compare 4 vs. 0; swap

  1 2 3 0 4 | 5 6 7
          x         -> 4 is lower than 5, 6, 7; work on remaining

  1 2 3 0 | 4 5 6 7
  ^ ^               -> compare 1 vs. 2; in order

  1 2 3 0 | 4 5 6 7
    ^ ^             -> compare 2 vs. 3; in order

  1 2 3 0 | 4 5 6 7
      ^ ^           -> compare 3 vs. 0; swap

  1 2 0 3 | 4 5 6 7
        x           -> 3 is lower than 4, 5, 6, 7; work on remaining

  1 2 0 | 3 4 5 6 7
  ^ ^               -> compare 1 vs. 2; in order

  1 2 0 | 3 4 5 6 7
    ^ ^             -> compare 2 vs. 0; swap

  1 0 2 | 3 4 5 6 7
      x             -> 2 is lower than 3, 4, 5, 6, 7; work on remaining

  1 0 | 2 3 4 5 6 7
  ^ ^               -> compare 1 vs. 0; swap

  0 1 | 2 3 4 5 6 7
    x               -> 1 is lower than 2, 3, 4, 5, 6, 7; work on remaining

  0 | 1 2 3 4 5 6 7
  ^                 -> 0 is lower than 1, 2, 3, 4, 5, 6, 7; we're DONE

  0 1 2 3 4 5 6 7

Recursion
- concept in programming where a function calls itself
- with recursion we always have a base case (exit case) so cycle closes

If no doors
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door
    Search right half

3. Merge Sort (with recursion) -> O(n log n) Time Complexity
If only one number
    Quit
Else
    Sort left half of numbers
    Sort right half of numbers
    Merge sorted halves


Consider the following list of numbers:

  7254
First, merge sort asks, “is this one number?” The answer is “no,” so the algorithm continues.

  7254
Second, merge sort will now split the numbers down the middle (or as close as it can get) and sort the left half of numbers.

  72|54
Third, merge sort would look at these numbers on the left and ask, “is this one number?” Since the answer is no, it would then split the numbers on the left down the middle.

  7|2
Fourth, merge sort will again ask , “is this one number?” The answer is yes this time! Therefore, it will quit this task and return to the last task it was running at this point:

  72|54
Fifth, merge sort will sort the numbers on the left.

  27|54
Now, we return to where we left off in the pseudocode now that the left side has been sorted. A similar process of steps 3-5 will occur with the right-hand numbers. This will result in:

  27|45
Both halves are now sorted. Finally, the algorithm will merge both sides. It will look at the first number on the left and the first number on the right. It will put the smaller number first, then the second smallest. The algorithm will repeat this for all numbers, resulting in:

  2457

*/
