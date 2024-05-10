// Created by Aaron H on 5/8/24.
// template class StaticArray is a container class for arrays with a static size defined at compile time.
/* template <typename T, size_t N>: This line declares a class template StaticArray with two parameters. T is a type parameter and N is a non-type parameter specifying the size of the array.
 * T m_Array[N];: This line declares an array member of type T and size N. Since N is a template parameter, this size must be known at compile time. This is essentially the storage of StaticArray. */
// StaticArray class features methods:
/* Indexing operators operator[]: These overloads allow the StaticArray class to be used like a native array.
 * at() function: This works like the indexing operator, but includes a bounds check. It should throw an exception if index is out of bounds.
 * begin() and end() functions: It returns pointer to the starting and just past the end elements of the array.
 * front() and back() functions: It returns reference to the first and last element of the array.
 * fill(T& value): A member function to fill the array with the specified value.
 * swap(StaticArray<T,N>& other): A function to swap the values of the array with another array.
 * empty(): This function returns true if the array size is 0, false otherwise.
 * size(): This function returns the size of the array.*/

// NOTE: This should be a const complete implementation in regard to its purpose.

// include guards
#ifndef UNDERSTANDINGALGO_STATICARRAY_H
#define UNDERSTANDINGALGO_STATICARRAY_H
#include <cstddef>
template <typename T, size_t N> // size_t represents an integral size and is used for array indexing and loop counting.
class StaticArray {
    T m_Array[N]; // size N known at compile time
public:
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;
    T* data() noexcept { return m_Array; }
    const T* data() const noexcept { return m_Array; }
    T* begin() noexcept { return data(); }
    const T* begin() const noexcept { return data(); }
    T* end() noexcept { return data() + N; }
    const T* end() const noexcept { return data() + N; }

    T& front() { return m_Array[0]; }
    const T& front() const { return m_Array[0]; }
    T& back() { return m_Array[N-1]; }
    const T& back() const { return m_Array[N-1]; }
    void fill(const T& value);
    void swap(StaticArray& other);
    bool empty() const { return N == 0; }
    size_t size() const { return N; }

    // Iterator
    /*
    typedef T* iterator;
    typedef const T* const_iterator;
    iterator begin() { return m_Array; }
    iterator end() { return m_Array + N; }
    */

};

#include "StaticArray.tpp" // Include Implementation File
// templates are compiled when required, meaning the implementation must be available at compile time.

#endif //UNDERSTANDINGALGO_STATICARRAY_H
