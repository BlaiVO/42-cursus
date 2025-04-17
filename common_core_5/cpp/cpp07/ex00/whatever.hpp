
template <class T>
void swap(T &n1, T &n2)
{
    T aux = n1;
    n1 = n2;
    n2 = aux;
}

template <class T>
T min(T n1, T n2)
{
    if (n1 < n2)
        return n1;
    return n2;
}

template <class T>
T max(T n1, T n2)
{
    if (n1 > n2)
        return n1;
    return n2;
}
