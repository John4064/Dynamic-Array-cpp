#include "DynamicArray.h"
#include <cstring>

DynamicArray::DynamicArray()
    : m_length(0), m_capacity(0), m_scaling_factor(2.0), m_data(nullptr) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity): m_length(0), m_capacity(capacity),m_scaling_factor(scaling_factor),  m_data(nullptr)  {
    //Check this one later Not 100% sure if done right
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value): m_length(length), m_capacity(length*scaling_factor), m_scaling_factor(scaling_factor) {
    for(unsigned int i = 0;i<m_length;i++){
        m_data[i] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other;
}

DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::getLength() {
    return m_length;
}

unsigned int DynamicArray::getCapacity() {
    return m_capacity;
}

double DynamicArray::getScalingFactor() {
    return m_scaling_factor;
}

void DynamicArray::setScalingFactor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::toString() {
    std::string str("{");
    for (unsigned int i = 0 ; i < m_length ; i++) {
        str.append(std::to_string(m_data[i]));
        if (i < m_length - 1) {
            str.push_back(' ');
        }
    }
    str.push_back('}');
    return str;
}

bool DynamicArray::findFirstOf(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    return found;
}

bool DynamicArray::findLastOf(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    return found;
}

void DynamicArray::append(int value) {
    //Works When tested was able to add to the array properly
    if(m_capacity<= m_length+1){
        m_capacity = (m_capacity*m_scaling_factor);
         int *curr = new int[m_capacity];
        for(unsigned int i = 0; i < m_length;i++){
            curr[i]= m_data[i];
        }
        curr[m_length] = value;
        m_length++;
        m_data = curr;
        delete[] curr;
    }else{
        m_data[m_length] = value;
        m_length++;
    }
}

void DynamicArray::prepend(int value) {
    //..............
    // TODO
    //..............
}

void DynamicArray::removeLast() {
    //..............
    int max = getLength();
    // TODO
    //..............
}

void DynamicArray::removeFirst() {
    //..............
    // TODO
    //..............
}

void DynamicArray::clear() {
    //..............
    // TODO
    //..............
}

int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this);
}
