#ifndef REPSTRING_H
#define REPSTRING_H

#include <iostream>
#include <string>

template<typename T>
class basic_repeating_string
{
public:
    basic_repeating_string()
        : _data(), _rep(1)
    {}

    void repeating_string_push_back(const T &c)
    {
        _data.push_back(c);
    }

    void set_repeating(int rep)
    {
        _rep = rep;
    }

    void print() const
    {
        for(int i=0; i<_rep; ++i)
            std::cout<<_data;
    }

    int size() const
    {
        return _data.size() * _rep;
    }

    int find(const T *h) const
    {
        return create().find(h);
    }

    T&
    operator [] (int pos)
    {
        return _data[pos%_data.size()];
    }

    const T&
    operator [] (int pos) const
    {
        return _data[pos%_data.size()];
    }

    int compare(const T *h) const
    {
        return create().compare(h);
    }

    class iterator: public std::iterator<std::forward_iterator_tag, T>
    {
    public:
        iterator(std::basic_string<T> &data, int pos)
            : _data(data), _pos(pos)
        {}

        T&
        operator * () const
        {
            return _data[_pos%_data.size()];
        }

        bool
        operator == (iterator rhs) const
        {
            return _pos == rhs._pos;
        }

        bool
        operator != (iterator rhs) const
        {
            return ! (*this == rhs);
        }

        iterator&
        operator ++ ()
        {
            ++_pos;
            return *this;
        }

        int
        operator - (iterator rhs)
        {
            return _pos - rhs._pos;
        }

    private:
        std::basic_string<T> &_data;
        int _pos;
    };

    iterator
    begin()
    {
        return iterator(_data, 0);
    }

    iterator
    end()
    {
        return iterator(_data, size());
    }

private:
    std::basic_string<T> create() const
    {
        std::basic_string<T> tmp;
        for(int i=0; i<_rep; ++i)
            tmp+=_data;
        return tmp;
    }

    std::basic_string<T> _data;
    int _rep;
};

#endif//REPSTRING_H
