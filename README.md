# C++20 Determine Endianness

While pointless given that std::endian exists. Still fun usage of std::bit_cast and std::string_view

- X86-x64 gcc trunk (-std=c++20 -O3) : https://godbolt.org/z/KKh9Ehv4h
- ARM64 gcc trunk (-std=c++20 -O3 -mbig-endian) : https://godbolt.org/z/TE1ee9o3e
