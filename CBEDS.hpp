#include <string>


const unsigned CRYPT_MOD = 255;

namespace CBEDS {

class Encrypt {
    public:
    //string AES(string value, string key);
    string String(string value, string key);
    string FileToString(string nameOfInputFile, string key);
    void StringToFile (string value, string nameOfOutputFile, string key);
    void FileToFile(string nameOfInputFile, string nameOfOutputFile, string key);
    };

class Decrypt {
    public:
    //string AES(string value, string key);
    string String(string value, string key);
    string FileToString(string nameOfInputFile, string key);
    void StringToFile (string value, string nameOfOutputFile, string key);
    void FileToFile(string nameOfInputFile, string nameOfOutputFile, string key);
    };

}
