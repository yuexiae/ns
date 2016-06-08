#ifndef BASE_EXCEPTION_H_
#define BASE_EXCEPTION_H_

#include <exception>


namespace base {

class Exception : public std::exception {
public:
    Exception(std::string &msg) : exception(msg.c_str()) {}

    Exception(const char *msg) : exception(msg) {}
};




}










#endif