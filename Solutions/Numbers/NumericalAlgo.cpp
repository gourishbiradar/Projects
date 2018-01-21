double BinaryExponentiation(double x, int n)
{
    if(n<0)
        return BinaryExponentiation(1/x, -n);
    if(n==0)
        return 1;
    if(n==1)
        return x;
    if(n&1) //is n odd?
        return x*BinaryExponentiation(x*x,(n-1)>>1);
//if n is even
return BinaryExponentiation(x*x,n>>1);
}
//TODO improve the expo%2 test by getting the binary vector for expo first
int ModularExpo(int base, int expo, int modulus)
{
    if(modulus==1)
        return 0;
    assert((modulus-1)*(modulus-1)<=base);
    int result = 1;
    base = base % modulus;
    // Perform the binary expo and summing 
    while(expo>0)
    {
        if(expo%2 == 1) //is b[i] set?
            result = (result*base)%modulus;
        expo = expo>>1;
        base = (base*base)%modulus;
    }
    return result;
}