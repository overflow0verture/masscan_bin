// pixie-timer-musl.c
#include <time.h>
#include <unistd.h>
#include <stdint.h>

uint64_t pixie_gettime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000ULL + (uint64_t)ts.tv_nsec / 1000ULL;
}

void pixie_usleep(uint64_t microseconds) {
    usleep(microseconds);
}

void pixie_mssleep(unsigned milliseconds) {
    usleep(milliseconds * 1000ULL);
}

uint64_t pixie_nanotime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
}
