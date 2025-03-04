#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_COUNT 50
#define MAX_AMPLITUDE 100

void generate_sine_wave(int16_t samples[], int amplitude) {
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        double angle = (2.0 * M_PI * i) / SAMPLE_COUNT;
        samples[i] = (int16_t)(amplitude * sin(angle));
    }
}

void apply_clipping(int16_t samples[], int16_t clip_value) {
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        if (samples[i] > clip_value) {
            printf("Overflow! Clipping %d to %d\n", samples[i], clip_value);
            samples[i] = clip_value;
        } else if (samples[i] < -clip_value) {
            printf("Overflow! Clipping %d to %d\n", samples[i], -clip_value);
            samples[i] = -clip_value;
        }
    }
}

int main() {
    int16_t samples[SAMPLE_COUNT];
    generate_sine_wave(samples, MAX_AMPLITUDE);

    printf("Original Sine Wave:\n");
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        printf("%d ", samples[i]);
    }
    printf("\n\nApplying Clipping:\n");

    int16_t clip_value = 80;
    apply_clipping(samples, clip_value);

    for (int i = 0; i < SAMPLE_COUNT; i++) {
        printf("%d ", samples[i]);
    }
    return 0;
}

