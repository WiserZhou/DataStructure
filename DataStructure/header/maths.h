
template <typename T>
T maxTri(T a, T b, T c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

template <typename T>
int lengthOfArray(T a[])
{
    return sizeof(a) / sizeof(T);
}