#define MAX_CURRENT_PAIRS_SUPPORTED     100
typedef struct
{
    int lower_limit;
    int upper_limit;
    int count;

}chargeCurrentPair;


int findCurrentPairs(int *chrgeCurrentArray, int size, chargeCurrentPair *pairBuffer);
