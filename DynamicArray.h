/*
 * Author: Christopher McCooey
 * Date Created: January 29, 2020
 * Description: This class is an object used to represent a dynamic array data structure that stores integers. This class
 *              does not sort the values stored in the array and should allow for repeated values.
 */

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <string>

class DynamicArray {
    private:
        // the number of items currently in the array
        unsigned int m_length;
        // the number of available spaces in the array
        unsigned int m_capacity;
        // the scaling factor when resizing the array (always > 1)
        double m_scaling_factor;
        // pointer to the array of integers
        int *m_data;

    public:
        // default constructor, capacity = 0, no need to allocate an internal array yet
        DynamicArray();
        // default constructor with a scaling factor, creates an array with capacity = capacity
        DynamicArray(double scaling_factor, unsigned int capacity);
        // fill constructor, creates an array of capacity = length, and set all values to `default_value`
        DynamicArray(double scaling_factor, unsigned int length, int default_value);
        // copy constructor
        DynamicArray(const DynamicArray& other);
        // default destructor, free memory of the array here
        ~DynamicArray();

        // get the number of elements in the array
        unsigned int getLength();
        // get the capacity of the array
        unsigned int getCapacity();
        // get scaling factor Needed by GUI
        double getScalingFactor();
        // set the scaling factor of the array
        void setScalingFactor(double value);
        // convert the vector into a printable string
        std::string toString();

        // find the first occurrence of "value" in the array. Return false if the value is not found
        // [10 points if correct]
        bool findFirstOf(int value, unsigned int* index);
        // find the last occurrence of "value" in the array. Return false if the value is not found
        // [10 points if correct]
        bool findLastOf(int value, unsigned int* index);

        // add a value to the end of the array (resize if necessary)
        // [10 points if correct]
        void append(int value);
        // add a value to the beginning of the array (resize if necessary)
        // [10 points if correct]
        void prepend(int value);
        // remove the last value from the array
        // [10 points if correct]
        void removeLast();
        // remove the first value from the array
        // [10 points if correct]
        void removeFirst();
        // remove all elements from the array
        // allocated memory should be deleted and the array pointer should now point to NULL
        // capacity and length should be reset to zero
        // [10 points if correct]
        void clear();

        // overloading the [] operator for read/write access
        int& operator[](unsigned int index);
        // assignment operator
        DynamicArray& operator=(const DynamicArray &other);
};

#endif