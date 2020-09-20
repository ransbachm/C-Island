#include <iostream>
#include <stdexcept>
#include "database.hpp"


class database {
    db_handle_t db_;
public:
    database(const char* filename) {
        db_ = db_open(filename);
        if(nullptr == db_) throw std::invalid_argument{""}; // yoda condition (literal == variable)
    }

    ~database() {db_close(db_);}
    int execute(const char* query) {return db_execute(db_, query);}
};
