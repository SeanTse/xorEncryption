#ifndef ENCODER_H
#define ENCODER_H
#include <string>
#include <fstream>
class encoder
{
public:
    encoder(const std::string);
    encoder();
    void setKey(const std::string);
    void encrypt(std::ifstream&,std::ofstream&);
    ~encoder();
private:
    std::string mkey;  // the key for encryption
    size_t keyBytes;
};
#endif
