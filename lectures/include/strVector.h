// /*
//  * Classes lecture code example credit to Sarah McCarthy
//  */

// //in case mutliple files in a project include strvector,
// //this instruction says only compile this file once!
#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>

class StrVector
{
public:
    // type alias (this is how iterator types work!)
    using iterator = std::string *;

    const size_t kInitialSize = 2;

    // Constructors & Destructor
    StrVector();
    StrVector(size_t n, const std::string &val);
    ~StrVector();

    // Low hanging fruit
    size_t size();
    bool empty();

    // Adding and Removing Elements from Vector
    void push_back(const std::string &elem);
    std::string &operator[](size_t index);
    std::string &at(size_t index);

    // OUR ITERATORS :)
    iterator begin();
    iterator end();

private:
    size_t logicalSize;
    size_t allocatedSize;
    std::string *elems;
    void grow();
};

#endif // STRVECTOR_H