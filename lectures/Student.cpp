#include "Student.h"

//******************
//* Constructors *
//******************

/// default constructor
Student::Student()
{
    name = "John Appleseed";
    state = "CA";
    age = 18;
}
/*
 * parameterized constructor
 * Commented out so that compiler doesn't yell about having two constructors
 * with the same arguments
 */
// Student::Student(std::string name, std::string state, int age) {
//   this->name = name;
//   this->state = state;
//   this->age = age;
// }

/// List initialization constructor
Student::Student(std::string name, std::string state, int age)
    : name{name}, state{state}, age{age} {}

//******************
//* Destructor *
//******************

Student::~Student(){};

//******************
//* Methods *
//******************

std::string Student::getName() { return this->name; }

std::string Student::getState() { return this->state; }

int Student::getAge() { return this->age; }
