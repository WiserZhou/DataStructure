
template <typename T>
T maxTri(T a, T b, T c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
