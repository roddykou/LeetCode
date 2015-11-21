int trailingZeroes(int n) {
    int ret = 0;
    for (long i = 5; i <= n; i *= 5)
        ret += n / i;
    return ret;
}

int main() {
    
}
