typedef struct
{
    int pair_startValue;
    int pair_endvalue;
    int pair_count;
}valuePair;

valuePair findValuePair(int *chrgeCurrentArray, int size);
int findPairCount(int *chrgeCurrentArray, int size, valuePair valuePair);
