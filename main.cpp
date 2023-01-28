#include <iostream>
#include <cstdint>
#include <array>
#include <bit>
#include <string_view>

// For program objects that span multiple bytes, we need 2 conventions
// 1.) What the address of the object will be
// 2.) How we will order the bytes in memory
//
// In virtually all machines, a multi-byte object is stored as a contiguous sequence of bytes,
// with the address of the object given by the smallest address of the bytes used.
//
// The order of the bytes is the "controversial" part.
constexpr std::string_view DetermineEndian()
{
    constexpr uint8_t foo = std::bit_cast<std::array<uint8_t, 4>, uint32_t>(0xFF'00'00'AA)[0];

    // If foo is big endian then it would be ordered as:
    // FF 00 00 AA
    //
    // If it's little endian
    // AA 00 00 FF
    //
    // Since in big endian. The most signficiant bit is ordered first in memory.
    // And in little the least signficant bit is ordered first in memory.
    if constexpr (foo == 0xFF)
    {
        return "big";
    }
    else if (foo == 0XAA)
    {
        return "little";
    }
    else
    {
        // Nothing says little/big endian are the only options for CPUs.
        throw std::runtime_error("????");
    }
}

int main()
{
    std::cout << "CPU is " << DetermineEndian() << " endian\n";
}
