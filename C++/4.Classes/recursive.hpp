#ifndef RECURSIVE_HPP
#define RECURSIVE_HPP

#include <iostream>

// a silly implementation of * printing
void print2(int n, int i);
void pattern2(unsigned n);
void print2_version2(unsigned n);

// pa15 assignm,ent
void pattern(unsigned n);
double power(double base, int exp);

namespace cs202
{
    template <class Iter>
    size_t size(Iter first, Iter last);

    template <class Iter, class T>
    size_t count(Iter first, Iter last, const T &value);

    template <class Iter, class T>
    auto sum(Iter first, Iter last, T init) -> decltype(init);

    template <class Iter>
    Iter smallest(Iter first, Iter last);

    template <class Iter>
    Iter largest(Iter first, Iter last);

    template <class Iter>
    void sort(Iter first, Iter last);

    template <class Iter>
    void fprint(Iter first, Iter last);

    template <class Iter>
    void rprint(Iter first, Iter last);
} // namespace cs202

/// --------------------------------------------------
///     @note Functions definition -
/// --------------------------------------------------

/// @paragraph second approach
/// EFFECT: return the size of the container
template <class Iter>
size_t cs202::size(Iter first, Iter last)
{
    size_t size_var = 0;

    if (first == last)
    {
        return size_var;
    }
    else
    {
        return 1 + cs202::size(++first, last);
    }
}

/// @paragraph second approach
/// EFFECT: return counts and returns the number
///         of occurrences of value within the range
template <class Iter, class T>
size_t cs202::count(Iter first, Iter last, const T &value)
{
    if (first == last)
    {
        return 0;
    }
    else if (*first == value)
    {
        return 1 + cs202::count(++first, last, value);
    }
    else
    {
        return cs202::count(++first, last, value);
    }
}

/// @paragraph return the sum of a range of elements
/// @param first iterator to the first element in the range
/// @param last iterator to the last element in the range
/// @return the sum of the elements in the range
template <class Iter, class T>
auto sum(Iter first, Iter last, T init) -> decltype(init)
{
    if (first == last)
    {
        return init;
    }

    auto next = first;

    if (++next == last)
    {
        return *first;
    }

    return *first + sum(next, last, *first);
}

template <class Iter>
Iter cs202::smallest(Iter first, Iter last)
{ // empty range and 1 element
    if (first == last)
    {
        return last;
    }
    else if (size(first, last) == 1)
    {
        return first;
    }

    Iter temp = first;
    if (*first < *smallest(++temp, last))
    {
        return first;
    }
    else
    {
        return smallest(temp, last);
    }
}

/// @paragraph second approach
/// @param first iterator to the first element in the range
/// @param last iterator to the last element in the range
/// EFFECT: return the largest element in the range
template <class Iter>
Iter cs202::largest(Iter first, Iter last)
{ // empty range and 1 element
    if (first == last)
    {
        return last;
    }
    else if (size(first, last) == 1)
    {
        return first;
    }

    Iter temp = first;
    if (*first > *largest(++temp, last))
    {
        return first;
    }
    else
    {
        return largest(temp, last);
    }
}

template <class Iter>
void cs202::sort(Iter first, Iter last)
{
    if (first == last)
    {
        return;
    }

    // smallest first occurence in the range
    Iter smol = smallest(first, last);
    // swap the smallest with the first element
    std::swap(*first, *smol);

    // sort the rest of the range
    cs202::sort(++first, last);
}

template <class Iter>
void cs202::fprint(Iter first, Iter last)
{
    if (first == last)
    {
        return;
    }
    else
    {
        std::cout << *first << " ";
        fprint(++first, last);
    }
}

template <class Iter>
void cs202::rprint(Iter first, Iter last)
{
    if (first != last)
    { // temp so we won't derefencing nullptr
        Iter temp = first;
        rprint(++temp, last);
        std::cout << *first << " ";
    }
}

/// NOTES: Non-namespace functions definitions
/// --------------------------------------------------
/// --------------------------------------------------

/// @paragraph first approach
/// EFFECT: print the * pattern
void pattern(unsigned n)
{
    char star = '*';
    // base case
    if (n == 0)
        return;
    else
    {
        pattern(n - 1);

        std::cout << std::string(n, '*') << std::endl;
    }
}

/// @paragraph first approach
/// EFFECT: return the power of base to exp
double power(double base, int exp)
{
    // general case
    if (exp > 0)
    { // non-zero value of base
        return base * power(base, exp - 1);
    }
    else if (exp < 0)
    { // negative value of exp
        return 1 / power(base, -exp);
    }
    else
    { // base case
        return 1.0;
    }
}

#endif /* EOF */