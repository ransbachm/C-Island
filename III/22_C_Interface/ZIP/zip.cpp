// apt install libz-dev
// COMPILE WITH -lz -Lzlib -Izlib/include 
// "real" cp headers
#include <iostream>
#include <string>
#include <vector> 
#include <fstream> // ifstream
#include <stdexcept>
#include <string>
#include <memory>


/*
// actual c stuff
#include <zlib.h>
[...]
typedef struct gzFile_s *gzFile;
extern "C" gzFile gzopen (const char *path, const char *mode);
extern "C" int gzwrite (gzFile file, voidpc buf, unsigned len);
extern "C" int gzclose (gzFile file);
*/

// c header via extern (same thing as above)
extern "C" {
   #include<zlib.h> 
}

// cpp provided compatibility headers
#include <cerrno>
#include <cstring>

using std::string; using std::vector; using std::cout;
using std::shared_ptr;

namespace {

class GzWriteStream {
public:
    gzFile gz_;

    explicit GzWriteStream(const string& filename) 
        : gz_{gzopen(filename.c_str(), "wb9")} // write, binary, compr. lvl 9
    {
        if(gz_ == NULL) throw std::runtime_error(std::strerror(errno));
    }
    ~GzWriteStream() {
        gzclose(gz_);
    }
    GzWriteStream& operator<<(const vector<char> &data) {
        write(data.data(), data.size());
        return *this; // copy ellusion
    }

private:
    void write(const char* data, size_t len) {
        auto res = gzwrite(gz_, data, len);
        if(res == 0) throw std::runtime_error(std::strerror(errno));
    }

    GzWriteStream(const GzWriteStream&) = delete; // delete copy
    GzWriteStream operator=(const GzWriteStream) = delete; // delete assign
};


}

int main() {
    cout << "Hello world!\n";

    GzWriteStream zStream("cmpress.gz");
    string str = "MAYDAY - The Fat Rat";
    vector<char> data{str.begin(), str.end()};
    zStream << data;

    string str2 = "HYPE MODE - Reol";
    vector<char> data2{str2.begin(), str2.end()};
    shared_ptr<gzFile_s> gz2{
        gzopen("cmpress_too.gz", "wb9"),
        [=](gzFile_s* f) {gzclose(f); cout<< "Close 2.nd file\n";} // "custom deleter"  withlambda
    };
    if(gz2.get() == NULL) throw std::runtime_error("Error opeining the second file");
    auto res = gzwrite(gz2.get(), data.data(), data.size());
    if(res == 0) throw std::runtime_error("Error writing to the second file");
}
