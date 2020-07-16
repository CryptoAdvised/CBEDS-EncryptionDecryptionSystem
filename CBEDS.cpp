/****************************************************************************/
/*FICHIER:      CBEDS.cpp                                                   */
/*AUTOR:        Colin Bouchard                      				        */
/*DATE:         10/07/2020                                                  */
/*DESCRIPTION:  This library offer the Encryption/Decryption system.        */
/*				                                                            */
/*				This is for learning purpose.                               */
/****************************************************************************/


#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "CBHL.hpp"
#include "CBEDS.hpp"

using namespace std;
using namespace CBHL;
using namespace CBEDS;

HashingLogic EDHL;


string Encrypt::String(string value, string key)
{

    int thisKey = EDHL.calculateKey(key)%CRYPT_MOD;                                             //Generate the key
    int i;


    for(i=0 ; i <= (int)value.length(); i++)
    {
        value[i] = value[i] + thisKey;
    }

    return value;
}


string Encrypt::FileToString(string nameOfInputFile, string key)
{
ifstream inputFile(nameOfInputFile);
string iFile((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
string cFile(Encrypt::String(iFile, key));

return cFile;
}

void  Encrypt::StringToFile(string value, string nameOfOutputFile, string key)
{
    ofstream outputFile(nameOfOutputFile);
    outputFile << Encrypt::String(value, key);
    outputFile.close();
}

void Encrypt::FileToFile(string nameOfInputFile, string nameOfOutputFile, string key)
{
    ofstream outputFile(nameOfOutputFile);
    outputFile << Encrypt::FileToString(nameOfInputFile, key);
    outputFile.close();
}



string Decrypt::String(string value, string key)
{


    int thisKey = -(int)(EDHL.calculateKey(key)%CRYPT_MOD);
    int i;

    for(i=0 ; i <= (int)value.length(); i++)
    {
        value[i] = value[i] + thisKey;
    }



    return value;
}

string Decrypt::FileToString(string nameOfInputFile, string key)
{
    ifstream inputFile(nameOfInputFile);
    string cFile((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    string oFile(Decrypt::String(cFile, key));

    return oFile;
}

void Decrypt::StringToFile(string value, string nameOfOutputFile, string key)
{
    ofstream outputFile(nameOfOutputFile);
    outputFile << Decrypt::String(value, key);
    outputFile.close();
}

void Decrypt::FileToFile(string nameOfInputFile, string nameOfOutputFile, string key)
{

    ofstream outputFile(nameOfOutputFile);

    outputFile << Decrypt::FileToString(nameOfInputFile, key);
    outputFile.close();

}
