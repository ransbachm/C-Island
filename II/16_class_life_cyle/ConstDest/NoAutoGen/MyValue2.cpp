#ifndef MYVALUE2
#define MYVALUE2


class MyValue2 {
    const int number_;

    explicit MyValue2(int v)
        : number_{v} {}

    // even if not neccessary, explicitly delete copy/assign constr/op
    MyValue2& operator=(MyValue2&) = delete;
    MyValue2(const MyValue2&) = delete;

};


#endif


int main() {

}