/* 3. Merge Sort (with recursion)
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

/* Example 2

7 | 2 | 5 | 4 | 1 | 6 | 0 | 3

2 7 | 4 5 | 1 6 | 0 3

2 4 5 7 | 0 1 3 6

0 1 2 3 4 5 6 7

*/