// dont do this, this is just for compactness

#include "value_impl.hpp"

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


Date Year::lastDay() const {
	return Date{Year{value_}, Month{12}, Day{31}};
}
