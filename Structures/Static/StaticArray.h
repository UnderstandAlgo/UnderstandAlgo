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
    // Access values
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;

    // Access array
    T* data() noexcept { return m_Array; }
    const T* data() const noexcept { return m_Array; }

    // Access array boundaries
    T* begin() noexcept { return data(); }
    const T* begin() const noexcept { return data(); }
    T* end() noexcept { return data() + N; }
    const T* end() const noexcept { return data() + N; }

    // Access specific nodes
    T& front() { return m_Array[0]; }
    const T& front() const { return m_Array[0]; }
    T& back() { return m_Array[N-1]; }
    const T& back() const { return m_Array[N-1]; }

    // Array operations
    void fill(const T& value);
    void swap(StaticArray& other);

    // Array properties
    bool empty() const { return N == 0; }
    size_t size() const { return N; }

    // Iterators, here we'll use raw pointers as random access iterators for now. There are special pointers we can
    // consider later such as auto_ptr, unique_ptr, shared_ptr, weak_ptr
    /* When we have iterator typedefs we can characterize the types of iterators, even though we already have begin()
     and end() member functions which return the actual iterators.
     Why? Well, when writing template code or using algorithms in the STL, these typedefs are essential. They allow
     algorithms and other code to refer to iterator types without actually knowing the exact type. It allows for more
     compatibility with complex templates and STL containers.*/
    typedef T* iterator;
    typedef const T* const_iterator;


    // NOTE: Since we're not working with dynamic memory in this class and all the members are fixed size,
    // the default copy and move semantics within the compiler should be fine for now.
};

#include "StaticArray.tpp" // Include Implementation File
// templates are compiled when required, meaning the implementation must be available at compile time.

#endif //UNDERSTANDINGALGO_STATICARRAY_H
