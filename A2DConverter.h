#define A2D_SAMPLE_MIN_VALUE        0
#define A2D_SAMPLE_MAX_VALUE        4094

#define MAX_CURRENT_VALUE           10.0
#define MAX_SAMPLES_SUPPORTED       1000

int validateA2DSample(int sample);
int convertA2DSample(int sample);
int ConvertA2DSamplesToCurrent(int *inputsample, int sampleSize, int *outputsample);

