/**
 * The decorator pattern is a design pattern that allows you to dynamically add new behavior to an existing object, without changing its code.
 * In this example, Encrypted behaviour and Compressed behaviour can be simply added to CloudStream without modifying the code of CloudStream.
 */

#include <iostream>
#include <string>

class Stream {
public:
    virtual void write(std::string date) = 0; // pure virtual function
};

class CloudStream : public Stream{
public:
    virtual void write(std::string data) {
        std::cout<<"Storing: "<<data<<std::endl;
    }
};

class EncryptedCloudStream: public Stream {
private:
    Stream* stream;
    std::string encrypt(std::string data) {
        return "!@&@(@^#(&#";
    };
public:
    EncryptedCloudStream(Stream* stream): stream(stream) {};
    void write(std::string data) override {
        std::string encrypted = encrypt(data);
        stream->write(encrypted);
    }
};

class CompressedCloudStream: public Stream {
private:
    Stream* stream;
    std::string compress(std::string data) {
        return data.substr(0, 5);
    }
public:
    CompressedCloudStream(Stream* stream): stream(stream) {};
    void write(std::string data) {
        std::string compressed = compress(data);
        stream->write(compressed);
    }
};

void storeCreditCard(Stream* stream) {
    stream->write("1234-1234-1234-1234");
};

int main() {
    storeCreditCard(new CloudStream());
    storeCreditCard(new EncryptedCloudStream(new CloudStream()));
    storeCreditCard(new CompressedCloudStream(new CloudStream()));
    storeCreditCard(new EncryptedCloudStream(new CompressedCloudStream(new CloudStream())));
    return 0;
};