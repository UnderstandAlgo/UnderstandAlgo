// Created by Aaron H on 5/8/24.
// This is the implementation of the StaticArray template class declared in StaticArray.h
/* Each of these methods are defined for any StaticArray instance of size N and type T.
 * 1. operator[](size_t index): Overloads the indexing operator [], providing direct access to the elements of the
 *    StaticArray instance via their indexes.
 * 2. at(size_t index): Similar to indexing operator but includes bounds checking. If the provided index is outside the
 *    valid range (i.e., index >= N, it throws a std::out_of_range exception).
 * 3. fill(const T& value): A method that assigns the given value to all elements of the StaticArray instance.
 * 4. swap(StaticArray& other): This method iterates over each element in the StaticArray instance, swapping it with the
 *    corresponding element in the other instance passed as a parameter.
 * */

// NOTE:
/* The way templates are separated between header (.h) and implementation (.tpp) is common practice to get around C++
 * standard's requirement that templates must be defined in every translation unit they are used.*/

#include "StaticArray.h"
#include <stdexcept>

template <typename T, size_t N>
T& StaticArray<T, N>::operator[](size_t index) { return m_Array[index]; }

template <typename T, size_t N>
const T& StaticArray<T, N>::operator[](size_t index) const { return m_Array[index]; }

template <typename T, size_t N>
T& StaticArray<T, N>::at(size_t index) {
    if (index >= N) throw std::out_of_range("Index out of bounds");
    return m_Array[index];
}

template <typename T, size_t N>
const T& StaticArray<T, N>::at(size_t index) const {
    if (index >= N) throw std::out_of_range("Index out of bounds");
    return m_Array[index];
}

template <typename T, size_t N>
void StaticArray<T, N>::fill(const T& value) {
    for (size_t i = 0; i != N; ++i) {
        m_Array[i] = value;
    }
}

template <typename T, size_t N>
void StaticArray<T, N>::swap(StaticArray& other) {
    for (size_t i = 0; i != N; ++i) {
        T temp = m_Array[i];
        m_Array[i] = other.m_Array[i];
        other.m_Array[i] = temp;
    }
}