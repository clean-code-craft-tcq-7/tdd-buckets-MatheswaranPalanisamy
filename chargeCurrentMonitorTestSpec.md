## Assumptions
	a) When the length of input is 1, then the output shall be empty [].
    b) Maximum possible pairs is limited to 100

### TDD steps
#### Step 1: Get input array with length 0 and 1 and generate empty output
    
    int findCurrentPairs(int *chrgeCurrentArray, int size, chargeCurrentPair *pairBuffer)

	a) method shall return count as 0 and [] in pairBuffer if [] is passed as input.
	b) method shall return count as 0 and [] in pairBuffer if [1] is passed as input.(1 is e.g meaning single value is passed).

#### Step 2: Get values in single set of continuous ascending order and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values as input in the single set of continuous ascending order and shall return the list of continuous range, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 1 and [[2, 3, 2]] in pairBuffer if [2, 3] is passed as input.
        b) method shall return count as 1 and [[4, 8, 5]] in pairBuffer if [4, 5, 6, 7, 8] is passed as input.

#### Step 3: Get values in multiple sets of continuous ascending order and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values, as input in the multiple sets of continuous ascending orders and shall return the list of continuous ranges, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 2 and ([[[1-3], 3], [[7-10], 4]]) in pairBuffer if [1, 2, 3, 7, 8, 9, 10] is passed as input.
        b) method shall return count as 2 and ([[[1-3], 3], [[7-9], 4], [[11-12], 2]]) in pairBuffer if [1, 2, 3, 7, 8, 9, 11, 12] is passed as input.

#### Step 4: Get values in multiple sets of continuous mixed order and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values as input in the single set of continuous order with unsorted manner and shall return the list of continuous range, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 1 and [[2, 3, 2]] in pairBuffer if [3, 2] is passed as input.
        b) method shall return count as 1 and [[4, 8, 5]]) in pairBuffer if [6, 4, 7, 8, 5] is passed as input.
        c) method shall return count as 3 and [[2, 3, 2], [7, 9, 3], [11, 12, 2]] in pairBuffer if [7, 8, 3, 12, 2, 9, 11] is passed as input.

#### Step 5: Get values in multiple sets of continuous mixed order with repeated numbers and generate output
    Note: Refactoring is required in method int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)

    The method can take an array of values as input in the single set of continuous order with unsorted manner with repeated numbers and shall return the list of continuous range, number of readings in the respective range and generate output in csv format.
        a) method shall return count as 0 and [] in pairBuffer if [3, 3] is passed as input
        b) method shall return count as 1 and [[2, 3, 4]] in pairBuffer if [3, 2, 2, 3] is passed as input.
        c) method shall return count as 1 and [[4, 8, 7]] in pairBuffer if [6, 4, 6, 7, 8, 5, 8] is passed as input.
        d) method shall return count as 3 and [[2, 3, 3], [7, 9, 7], [11, 12, 2]] in pairBuffer if [7, 8, 3, 12, 2, 9, 11, 2, 7, 9, 7, 9] is passed as input.

#### Step 6: Generate output in csv format for passed array
    Note: New methods int formatCurrentPairInCsv(chargeCurrentPair *pairBuffer, int pairCount, char *formattedBuffer) and int getFormattedCurrentPairs(int *chrgeCurrentArray, int size, char *formattedBuffer) are required

	The method an array of values, find best possible ranges and number of readings and shall return the csv formatted string.
        a) method will return "Range, Readings\n4-5, 2\n", if [4, 5] is passed as input.
        b) method will return "Range, Readings\n4-5, 2\n7-8, 2\n", if [4, 5, 7, 8] is passed as input.
        d) method shall return "Range, Readings\n3-11, 8\n11-13, 2\n" if [6, 3, 4, 5, 7, 9, 8, 11] is passed as input.


### Extensions
#### Step 7: Validate a A2D sample to be in range between 0 to 4095
    int validateA2DSample(int sample)
    
    The method will get A2D sample and validate it to be within range 0 to 4094
        a) Method will return 0, if -1 is passed as sample.
        b) Method will return 1, if 0 is passed as sample.
        c) Method will return 1, if 4094 is passed as sample.
        d) Method will return 1, if 4095 is passed as sample.

#### Step 8: Write a pure function to validate range and convert the A2D samples to current in terms of integer
    int convertA2DSample(int sample)
    
    The method shall validate the sample with 0 - 4094 range and convert A2D sample to current as 0-4094 = 0-10 in linear basis and round it off to nearest integer
        b) Method will return -1, if -5 is passed as sample
        b) Method will return 0, if 0 is passed as sample
        c) Method will return 0, if 100 is passed as sample
        d) Method will return 1, if 210 is passed as sample
        e) Method will return 4, if 1800 is passed as sample
        f) Method will return 4, if 2047 is passed as sample
        g) Method will return 10, if 2000 is passed as sample
        h) Method will return -1, if 4095 is passed as sample

#### Step 9: Convert the A2D samples to charge current
    int ConvertA2DSamplestoCurrent(int *inputsample, int sampleSize, int *outputsample)

    The method will take the list of samples from 12bit A2D converter, validate them against valid range, ignores invalid samples and convert the valid samples to current values
	    a) The 12bit integer value has limits from 0 - 4094.
	    b) Any value above 4094 will be ignored in the output current value array.
        c) Round off the value to nearest integer

#### Step 10: Integrate the A2D converted samples with current range formatter:
    int getFormattedCurrentPairsFromADCSamples(unsigned int *inputsample, int sampleSize, char *formattedBuffer)

        a) Get input as A2D samples array in integer range from 0 to 4095 and convert the samples to current.
        b) Find the current range and count and return csv formatted current pairs.

#### Step 11: Support another type of sensor which has sample range from 0 to 1022, current range from -15 to +15 Amps
    Note: Refactor the methods to get sensor type, configure sensor dependent information to calculate the current as such.
        Refactoring is required in existing test case level also.

        a) Get input as per the supported range for sensor type 1 and get the formatted current value pair
        b) Get input as per the supported range for sensor type 2 and get the formatted current value pair
