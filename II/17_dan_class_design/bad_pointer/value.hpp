#ifndef __VALUE__
#define __VALUE__

#include <string>
#include <stdexcept>

struct value {
   std::string value_;

   value() 
   : value_{"TestString"} {}

};


#endif