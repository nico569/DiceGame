#include "RandomNumberGenerator.h"

int RandomNumberGenerator::GetRandomNum() // Generate a random number between 1 and 6
{
    // use namespace chrono
    using namespace std::chrono;
    // and include literals to be able to use 0.5s for seconds
    using namespace std::literals::chrono_literals;
    // get the current time in nanoseconds
    nanoseconds ns = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    // store the count in an int to be used as the seed for the random num gen
    int seed = ns.count();
    std::this_thread::sleep_for(1ms); // sleep the thread in order to get a new seed every time

    std::srand(seed); // use the seed in ms to get better random numbers

    int randomNumber = (std::rand() % 6 + 1); // clamp the number to only allow values between 1 and 6
    return randomNumber;
    // return std::rand(); // INFO: this also works and does not require a temporary int.
}
