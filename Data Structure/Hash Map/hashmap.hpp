/// @brief Assignment 7
/// Header file for Hash Map Class
#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <iostream>
#include <vector>
#include <mutex>

template <typename t1, typename t2>
class hashMap
{
public:
    hashMap();
    hashMap(const hashMap<t1, t2> &);
    const hashMap &operator=(const hashMap<t1, t2> &);
    ~hashMap();
    t2 &operator[](t1);

private:
    int items;
    int tableSize;

    struct tableItem
    {
        t1 key;
        t2 value;
    };

    tableItem *table1;
    tableItem *table2;
    int h1(char) const;
    int h2(char) const;

    void resize();
};

template <typename t1, typename t2>
int hashMap<t1, t2>::h1(char key) const
{
    int value = (key + 20) % tableSize;

    if (key >= 'A')
    {
        value = (key - 50) % tableSize;
    }

    return value;
}

template <typename t1, typename t2>
int hashMap<t1, t2>::h2(char key) const
{

    int value = (key + 50) % tableSize;

    if (key >= 'a')
    {
        value = (key + 20) % tableSize;
    }

    return value;
}

template <typename t1, typename t2>
void hashMap<t1, t2>::resize()
{

    tableItem temptable1[tableSize];
    tableItem temptable2[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        temptable1[i].key = table1[i].key;
        temptable1[i].value = table1[i].value;
        temptable2[i].key = table2[i].key;
        temptable2[i].value = table2[i].value;
    }
    delete[] table1;
    delete[] table2;

    int upsize = tableSize * 2;
    table1 = new tableItem[upsize];
    table2 = new tableItem[upsize];
    for (int i = 0; i < upsize; i++)
    {
        table1[i].key = t1();
        table1[i].value = t2();
        table2[i].key = t1();
        table2[i].value = t2();
    }

    int oldSize = tableSize;
    tableSize = upsize;
    items = 0;

    for (int i = 0; i < oldSize; i++)
    {
        if (temptable1[i].key != t1())
        {
            (*this)[temptable1[i].key] = temptable1[i].value;
        }
    }

    for (int i = 0; i < oldSize; i++)
    {
        if (temptable2[i].key != t1())
        {
            (*this)[temptable2[i].key] = temptable2[i].value;
        }
    }
}

template <typename t1, typename t2>
hashMap<t1, t2>::hashMap()
{
    items = 0;
    tableSize = 10;

    table1 = new tableItem[tableSize];
    table2 = new tableItem[tableSize];

    for (int i = 0; i < tableSize; i++)
    {
        table1[i].key = t1();
        table1[i].value = t2();

        table2[i].key = t1();
        table2[i].value = t2();
    }
}

template <typename t1, typename t2>
hashMap<t1, t2>::hashMap(const hashMap<t1, t2> &copy)
{
    tableSize = copy.tableSize;
    items = copy.items;
    table1 = new tableItem[tableSize];
    table2 = new tableItem[tableSize];
    for (int i = 0; i < tableSize; i++)
    {

        table1[i].key = copy.table1[i].key;
        table1[i].value = copy.table1[i].value;

        table2[i].key = copy.table2[i].key;
        table2[i].value = copy.table2[i].value;
    }
}

template <typename t1, typename t2>
const hashMap<t1, t2> &hashMap<t1, t2>::operator=(const hashMap<t1, t2> &rhs)
{
    delete[] table1;
    delete[] table2;

    tableSize = rhs.tableSize;
    items = rhs.items;
    table1 = new tableItem[tableSize];
    table2 = new tableItem[tableSize];

    for (int i = 0; i < tableSize; i++)
    {

        table1[i].key = rhs.table1[i].key;
        table1[i].value = rhs.table1[i].value;

        table2[i].key = rhs.table2[i].key;
        table2[i].value = rhs.table2[i].value;
    }

    return *this;
}

template <typename t1, typename t2>
hashMap<t1, t2>::~hashMap()
{
    delete[] table1;
    delete[] table2;
}

template <typename t1, typename t2>
t2 &hashMap<t1, t2>::operator[](t1 key)
{
    int x = h1(key);
    int y = h2(key);

    float load = static_cast<float>(items) / static_cast<float>(tableSize);
    if (load >= 0.5)
    {
        resize();
    }

    t2 *value;
    int i = 0;
    int counter = 0;
    bool set = false;

    while (!set)
    {

        if (counter % 2 == 0)
        {

            if (table1[(x + i * y) % tableSize].key == t1())
            {
                table1[(x + i * y) % tableSize].key = key;
                items++;
                value = &table1[(x + i * y) % tableSize].value;
                set = true;
            }
            else if (table1[(x + i * y) % tableSize].key == key)
            {
                value = &table1[(x + i * y) % tableSize].value;
                set = true;
            }
        }
        else
        {

            if (table2[(y + i * x) % tableSize].key == t1())
            {
                table2[(y + i * x) % tableSize].key = key;
                items++;
                value = &table2[(y + i * x) % tableSize].value;
                set = true;
            }
            else if (table2[(y + i * x) % tableSize].key == key)
            {
                value = &table2[(y + i * x) % tableSize].value;
                set = true;
            }
        }

        if (counter % 2 == 0)
        {
            i += x;
        }
        else
        {
            i += y;
        }
        counter++;
    }

    return *value;
}

#endif // HASHMAP_H_
