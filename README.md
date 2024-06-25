# XORShift Random Number Generator (RNG)

This repository contains a simple and efficient implementation of the XORShift random number generator (RNG) in C. XORShift RNGs are known for their high speed and reasonable randomness, and are suitable for applications requiring random number generation such as simulations, games, and randomized algorithms.

## Features

- **Efficient Generation**: Uses XORShift algorithm, which is fast and consumes minimal system resources.
- **Thread-Safe**: Utilizes `_Thread_local` for maintaining thread-local state to ensure that the RNG is thread-safe.
- **Easy Initialization**: Offers functions to initialize the RNG state either with a specific seed or with the current system time for varied starting conditions.
- **Range Function**: Generate random integers within a specified range.
- **Boolean Generation**: Conveniently generate a true or false value, which can be useful for making binary decisions.

## Usage

### Installation

This a header only library. Simply include the `rng.h` header file in your C project to use the RNG functions.

### Functions

#### `void RNG_Init(uint64_t seed)`

Initializes the RNG state with a user-provided seed.

#### `void RNG_InitWithCurrentTime(void)`

Initializes the RNG state with the current system time as the seed.

#### `uint64_t RNG_Next()`

Generates a raw 64-bit random number.

#### `int RNG_FromRange(int min, int max)`

Generates a random integer within the specified range `[min, max]`.

#### `bool RNG_TrueOrFalse()`

Generates a boolean value (true or false).

### Example

Here's a simple example demonstrating how to use the RNG:

```c
#include "rng.h"

int main() {
    // Initialize RNG with current time
    RNG_InitWithCurrentTime();

    // Print random numbers
    printf("Random number: %llu\n", RNG_Next());
    printf("Random number from 0 to 10: %d\n", RNG_FromRange(0, 10));
    printf("Random true or false: %d\n", RNG_TrueOrFalse());

    return 0;
}
