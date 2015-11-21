#include <cstdint>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++)
        // ret << 1 + (0x1 & n >> i) is WRONG.
        ret = ret << 1 | (0x1 & n >> i);
    return ret;
}

int main() {

}
