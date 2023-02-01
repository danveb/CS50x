/* Bubble sort -> O(n^2)
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

  */