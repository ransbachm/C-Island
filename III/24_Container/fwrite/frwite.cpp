#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>
#include <stdexcept>

using std::cout; using std::vector;


using count_type = size_t; // type used for counting how many elements are in the file

template<typename T>
void vecToFile(const char* filename, const vector<T>& vec) {
    // open file
    auto fd = fopen(filename, "wb");
    if(fd == nullptr) throw "error opening file";

    // write num of elements
    count_type elements = vec.size();
    auto okCount = fwrite(&elements, sizeof(count_type), 1, fd);
    if(okCount != 1) throw "error writing count to file";

    // write actual data
    auto ok = fwrite(vec.data(), sizeof(T), vec.size(), fd);
    if(ok != vec.size()) throw "error writing to file";

    // close file
    fclose(fd);
}

template<typename T>
vector<T> fileToVec(const char* filename) {
    // open file
    auto fd = fopen(filename, "rb");
    if(fd == nullptr) throw "error opening file";

    // get num of elements
    count_type elements;
    auto okElements = fread(&elements, sizeof(count_type), 1, fd);
    if(okElements != 1) throw "error reading number of elements";

    // set up according vector
    vector<T> vec{};
    vec.resize(elements);

    // read from file
    auto ok = fread(vec.data(), sizeof(T), elements, fd);
    if(ok != elements) throw "error reading from file";
    
    // close file
    fclose(fd);
    return vec;
}


// used for printing vector<T>
template<typename T>
std::ostream& operator<<(std::ostream& os, const vector<T> vec) {
    os << "[";
    for(int i=0; i<vec.size(); i++) {
        os << (int) vec[i];

        if(i < vec.size() - 1) { // if not last element
            os << ", ";
        }
    }
    
    return os << "]";
}

int main() {
    using contType = unsigned char; // type of the vector elements
    vector<contType> nums; // vector that should be saved to file

    // int max = 500'000;
    int max = 200; // how many entries should be written
    for(int i=0; i<max; i++) {
        if(i > std::numeric_limits<contType>::max())
            throw std::out_of_range("cannot store i, it is too large to fit into the given type");
        nums.push_back(i);
    }

    // write vector to file
    vecToFile("numbers.dat", nums);

    // read file into a new vector
    vector<contType> fromFile = fileToVec<contType>("numbers.dat");

    // print vector
    cout << fromFile << "\n";

    // test with another vector
    // this time with a cstring
    vector<const char*> text = {"This", "is", "a", "fruit", "but it's", "not a Banana"};
    vecToFile("banana.dat", text);
}

