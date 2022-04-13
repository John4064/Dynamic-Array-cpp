#include "DynamicArray.h"
#include <cstring>

DynamicArray::DynamicArray()
    : m_length(0), m_capacity(0), m_scaling_factor(2.0), m_data(nullptr) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    m_scaling_factor = scaling_factor;
    m_capacity = capacity;
    m_length = capacity;
    m_data = new int[m_capacity];
    //..............
    // TODO
    //..............
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    m_scaling_factor = scaling_factor;
    m_length = length;
    m_capacity = m_length;
    m_data = new int[m_capacity];
    for( unsigned int i = 0; i < m_length; i ++){
        m_data[i] = default_value;
    }
    //..............
    // TODO
    //..............
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
    for ( unsigned int i = 0; i < m_length; i++){
        if(m_data[i] == value ){
            found = true;
            *index = i+1;
            break;
        }
    }
    //..............
    // TODO
    //..............
    for ( int i = 0; i < m_lenght; i++){
        if(m_data[i] == value;){
            found = true;
            *index = i;
            break;
        }
    }
    return found;
}

bool DynamicArray::findLastOf(int value, unsigned int *index) {
    bool found = false;
    for ( unsigned int i = m_length - 1; i >=0; i--){
        if(m_data[i] == value ){
            found = true;
            *index = i+1;
            break;
        }
    }
    //..............
    // TODO
    //..............
    for ( int i = m_lenght-1; i >= 0; i--){
        if(m_data[i] == value;){
            found = true;
            *index = i;
            break;
        }
    }
    
    return found;
}

void DynamicArray::append(int value) {
    //Works When tested was able to add to the array properly Then Randomly a segmentations fault
    //Checks if an addition of element will exceed capacity
    if(m_capacity<= m_length+1){
        if(m_scaling_factor>1){
            m_capacity = (m_capacity*m_scaling_factor);
        }else{
            m_capacity = (m_capacity+m_capacity*m_scaling_factor);
        }
        int *curr = new int[m_capacity];
         //Transfers over all the old elements
        for(unsigned int i = 0; i < m_length;i++){
            curr[i]= m_data[i];
        }
        curr[m_length] = value;
        m_length++;
        //Set The old arr to the new array
        delete[] m_data;
        m_data = curr;
        //delete the temporary array
        //delete [] curr; This breaks the code
    }else{
        m_data[m_length] = value;
        m_length++;
    }
    return;

    //..............
    // TODO
    //..............
}

void DynamicArray::prepend(int value) {
    //..............
    // TODO
    //..............
    if(m_capacity<= m_length+1){
        //Scaling factor on github says is always greater than 1 but on the test code its .5?
        if(m_scaling_factor>1){
            m_capacity = (m_capacity*m_scaling_factor);
        }else{
            m_capacity = (m_capacity+m_capacity*m_scaling_factor);
        }
        int *curr = new int[m_capacity];
        curr[0] = value;//ADDING THE NEW VALUE
        m_length++;//Accounting for new value
        for(unsigned int i = 1; i < m_length;i++){
            curr[i]= m_data[i-1];
        }
        //Setting the array to the new one
        delete [] m_data;
        m_data = curr;
        //delete[] curr; this breaks the code Gotta figure out why
    }else{
        int *curr = new int[m_capacity];
        m_length++;//Accounting for new value
        curr[0] = value;//ADDING THE NEW VALUE
        for(unsigned int i = 1; i < m_length;i++){//Readding all the values
            curr[i]= m_data[i-1];
        }
        delete[] m_data;
        m_data = curr;
        //delete[] curr; this breaks the code Gotta figure out why
    }
    return;
}

void DynamicArray::removeLast() {
    //In Progress
    int *curr = new int[m_capacity];
    m_length--;
    for (unsigned int i = 0; i< m_length; i++){
        curr[i]=m_data[i];
    }
    delete[] m_data;
    m_data = curr;
    return;
}

void DynamicArray::removeFirst() {
    for (int i = 0; i< m_length; i++){
        m_date[i]= m_data[i-1];
        m_data[m_lenght-1]= NULL;
        m_lenght = m_length-1;
    }    
    //..............
    // TODO
    //..............
    int *curr = new int[m_capacity];
    for(unsigned int i = 1; i <m_length;i++){
        curr[i-1]=m_data[i];
    }
    delete[] m_data;
    m_data = curr;
    m_length--;
    return;
}

void DynamicArray::clear() {
    //IN Progress
    delete[] m_data;
    m_data = nullptr;
    m_length =0;
    m_capacity = 0;
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
