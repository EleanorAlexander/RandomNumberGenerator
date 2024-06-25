#ifndef RNG_H
#define RNG_H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

static _Thread_local uint64_t STATE;

static void RNG_Init(uint64_t seed) { STATE = seed;}

static void RNG_InitWithCurrentTime(void) {
    RNG_Init((uint64_t)time(NULL));
}

static uint64_t RNG_Next() {
  uint64_t x = STATE;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  STATE = x;
  return x * 0x2545F4914F6CDD1DULL;
}

static int RNG_FromRange(int min, int max) {
  if (min >= max) {
    return min;
  }
  uint64_t range = (uint64_t)(max - min) + 1;
  uint64_t buckets = UINT64_MAX / range;
  uint64_t limit = buckets * range;
  uint64_t randomNumber;
  do {
    randomNumber = RNG_Next();
  } while (randomNumber >= limit);

  return (randomNumber / buckets) + min;
}

static bool RNG_TrueOrFalse() {
  return RNG_Next() & 1; 
}

#endif // RNG_H

