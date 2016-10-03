#include "diag.hpp"

#include <memory>
#include <stdio.h>

int main(void)
{
    // Create shared instance of diag.
    auto d = std::make_shared<diag>("super-id", 42);
    // Wrap in python callable thing.

    // Call python, pass wrapped thing.
}

