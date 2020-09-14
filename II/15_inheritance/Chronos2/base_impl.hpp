#ifndef DATE_IMPL
#define DATE_IMPL

#include "base.hpp"

namespace chronos2 {
    class day : public base {
    public:
        explicit day(int v) : base{v} {}
    };

    class month : public base {
    public:
        explicit month(int v) : base{v} {}
    };

    class year : public base {
    public:
        explicit year(int v) : base{v} {}
    };

    class date {
        year year_;
        month month_ {1};
        day day_ {1};

    public:
        explicit date(int y) : year_{y} {}
        date(year y, month m, day d) : year_{y}, month_{m}, day_{d} {}
        std::ostream& print(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, date date);
}



#endif