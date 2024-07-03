#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int i)
{
    typename T::iterator res;
    res = std::find(container.begin(), container.end(), i);

    if (res == container.end())
        throw (NotFoundException());
    return (res);
}

#endif