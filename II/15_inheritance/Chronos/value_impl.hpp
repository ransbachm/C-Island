
#ifndef VALUE_IMPL
#define VALUE_IMPL

class Date; // fordward declaration

class Year : public Value {
public:
        explicit Year(int v) : Value{v, 4} {}
        Date lastDay() const;
};

class Month : public Value {
public:
        explicit Month(int v) : Value{v, 2} {}
};

struct Day : public Value {
        explicit Day(int v) : Value{v, 2} {}
};

#endif
