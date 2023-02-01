/* Selection sort (small to largest) -> worst case O(N^2)
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

*/