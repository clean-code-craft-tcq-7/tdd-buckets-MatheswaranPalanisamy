Assumptions:- 
	a) When the length of input is 1, then the output shall be empty [].
    b) When the values are discontinous, nearest range shall be taken into account.

1) Get input array with length 0 and 1 and generate empty output
    
    int findCurrentPairs(int *chrgeCurrentArray, int size, chargeCurrentPair *pairBuffer)

	a) method shall return count as 0 and [] in pairBuffer if [] is passed as input.
	b) method shall return count as 0 and [] in pairBuffer if [1] is passed as input.(1 is e.g meaning single value is passed).

2) Get values in single set of continuous ascending order and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values as input in the single set of continuous ascending order and shall return the list of continuous range, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 1 and [[2, 3, 2]] in pairBuffer if [2, 3] is passed as input.
        b) method shall return count as 1 and [[4, 8, 5]] in pairBuffer if [4, 5, 6, 7, 8] is passed as input.

3) Get values in multiple sets of continuous ascending order and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values, as input in the multiple sets of continuous ascending orders and shall return the list of continuous ranges, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 2 and ([[[1-3], 3], [[7-10], 4]]) in pairBuffer if [1, 2, 3, 7, 8, 9, 10] is passed as input.
        b) method shall return count as 2 and ([[[1-3], 3], [[7-9], 4], [[11-12], 2]]) in pairBuffer if [1, 2, 3, 7, 8, 9, 11, 12] is passed as input.

4) Get values in multiple sets of continuous mixed order and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values as input in the single set of continuous order with unsorted manner and shall return the list of continuous range, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 1 and [[2, 3, 2]] in pairBuffer if [3, 2] is passed as input.
        b) method shall return count as 1 and [[4, 8, 5]]) in pairBuffer if [6, 4, 7, 8, 5] is passed as input.
        c) method shall return count as 3 and [[2, 3, 2], [7, 9, 3], [11, 12, 2]] in pairBuffer if [7, 8, 3, 12, 2, 9, 11] is passed as input.

5) Get values in multiple sets of continuous mixed order with repeated numbers and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values as input in the single set of continuous order with unsorted manner with repeated numbers and shall return the list of continuous range, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 0 and [] in pairBuffer if [3, 3] is passed as input
        a) method shall return count as 1 and [[2, 3, 4]] in pairBuffer if [3, 2, 2, 3] is passed as input.
        b) method shall return count as 1 and [[4, 8, 7]] in pairBuffer if [6, 4, 6, 7, 8, 5, 8] is passed as input.
        c) method shall return count as 3 and [[2, 3, 3], [7, 9, 7], [11, 12, 2]] in pairBuffer if [7, 8, 3, 12, 2, 9, 11, 2, 7, 9, 7, 9] is passed as input.

6) Get values in multiple sets of discontinuous order and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values as input in the single set of discontinuous order with unsorted manner and shall return the list of nearest possible continuous range, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 1 and [[2, 4, 2]] in pairBuffer if [4, 2] is passed as input.
        b) method shall return count as 1 and [[4, 8, 4]] in pairBuffer if [6, 4, 7, 8] is passed as input.
        c) method shall return count as 3 and [[2, 3, 2], [5, 9, 4], [11, 13, 2]] in pairBuffer if [7, 8, 3, 13, 2, 5, 9, 11] is passed as input.
        d) method shall return count as 2 and [[3, 11, 8], [11, 13, 2]] in pairBuffer if [6, 3, 4, 5, 7, 9, 8, 11] is passed as input.

7) Generate output in csv format for passed array
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)
	
	The method an array of values, find best possible ranges and number of readings and shall return the csv formatted string.
        a) method will return "Range, Readings\n4-5, 2", if [4, 5] is passed as input.
        b) method will return "Range, Readings\n4-5, 2\n7-8, 2", if [4, 5, 7, 8] is passed as input.
        d) method shall return "Range, Readings\n3-11, 8\n11-13, 2" if [6, 3, 4, 5, 7, 9, 8, 11] is passed as input.