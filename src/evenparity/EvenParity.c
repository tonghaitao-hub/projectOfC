uint32 CountOneBits(uint32 value)
{
    uint32 ones;
    for (ones = 0; value != 0; value >>= 1)
    {
        if ((value & 1) != 0)
        {
            ones += 1;
        }
    }
    return ones;
}

uint32 EvenParity(uint32 value, uint32 n_bits)
{
    int parity = 0;
    while(n_bits > 0)
    {
        parity += value & 1;
        value >>= 1;
        n_bits -= 1;
    }
    return (parity % 2) == 0;
}
