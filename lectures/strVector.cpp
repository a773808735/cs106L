// /*
//  * Classes lecture code example credit to Sarah McCarthy
//  */

// //dont forget to include the .h file!
// //implementation for strvector.cpp goes here!
#include "StrVector.h"

StrVector::StrVector() : logicalSize{0}, allocatedSize{kInitialSize}
{
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), "");
}

StrVector::StrVector(size_t n, const std::string &val) : logicalSize{n}, allocatedSize{n * 2}
{
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), val);
}

StrVector::~StrVector()
{
    delete[] elems;
}

StrVector::iterator StrVector::begin()
{
    return elems;
}

StrVector::iterator StrVector::end()
{
    return (elems + logicalSize);
}

size_t StrVector::size()
{
    return logicalSize;
}

bool StrVector::empty()
{
    return logicalSize == 0;
}

void StrVector::push_back(const std::string &elem)
{
    logicalSize += 1;
    if (logicalSize == allocatedSize)
    {
        std::string *cur = new std::string[logicalSize * 2];
        allocatedSize *= 2;
        for (int i = 0; i < logicalSize; i++)
        {
            cur[i] = elems[i];
        }
        delete[] elems;
        elems = cur;
    }
    elems[logicalSize] = elem;
}

// void StrVector::grow() {
//   /// TODO
// }

std::string &StrVector::operator[](size_t index)
{
    return *(begin() + index);
}

std::string &StrVector::at(size_t index)
{
    return *(begin() + index);
}

// for (vector::iterator it = vec.begin(); it != vec.end(); it++)

// using iterator = T*