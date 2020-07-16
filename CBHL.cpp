/****************************************************************************/
/*FICHIER:      CBHL.cpp                                                    */
/*AUTOR:        Colin Bouchard                      				        */
/*DATE:         09/07/2020                                                  */
/*DESCRIPTION:  This library offer the Hashing Logic.                       */
/*				                                                            */
/*				This is for learning purpose.                               */
/****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>

#include "CBHL.hpp"


using namespace std;
using namespace CBHL;

    unsigned HashingLogic::calculateKey(string key)
    {
        unsigned keyValue = 0;

        for(int i = 0; i <= (int)key.length(); i++)
        {
            keyValue += ((unsigned)key[i] * i * MAGIC_MULTIPLIER);                               //using MAGIC_MULTIPLIER to convert key to numeral
        }

        return keyValue;
    }

    unsigned HashingLogic::calculateHash (unsigned thisValue[], unsigned key, int length)
    {
        unsigned  mKey = UINT_MAX/key;                                                           //mKey start at unsigned max devided by key value
        int i;

        //Calculating mKey
        for(i = 0; i <= length; i++)
        {
            //using MAGIC_MULTIPLIER to generate the final value
            mKey += ((((MAGIC_MULTIPLIER * thisValue[i])* MAGIC_MULTIPLIER * thisValue[i])* MAGIC_MULTIPLIER * thisValue[i]) * key) % UINT_MAX/2;
        }

        return mKey;
    }

    void HashingLogic::calculateNumeral (unsigned numeralValue[], string toHash)
    {
        for(int i = 0; i <= (int)toHash.length(); i++)
        {
            numeralValue[i] = ((unsigned)toHash[i] * i * MAGIC_MULTIPLIER);                       //using MAGIC_MULTIPLIER to convert value to numeral
        }
    }

    string HashingLogic::hexHash (unsigned nValue[], unsigned key, int length)
    {
        char hexValue[MAX_HEX];
        string hashedValue = "";


        for(int i=0; i <= MAGIC_MULTIPLIER; i++ )
        {
            memset(hexValue, 0, MAX_HEX);                                                          //reset hexValue
            //sprintf_s(hexValue, "%x", calculateHash(nValue, key, length));                       //convert numeral to hex (VC++ compiler)
            sprintf(hexValue, "%x", calculateHash(nValue, key, length));                           //convert numeral to hex (GCC compiler)
            key *= (key+1);                                                                        //multiply the key for next run
            hashedValue += (string)hexValue;                                                       //concatenate hashedValue
        }

        return hashedValue;
    }

    string HashingLogic::Hash(string toHash, string key)
    {
        unsigned* nValue = new unsigned[toHash.length()];                                           //create unsigned array the same size as the word to hash
        unsigned thisKey = HashingLogic::calculateKey(key);                                         //calculate the key value


        HashingLogic::calculateNumeral(nValue, toHash);                                             //fill the array with value corresponding to each character

        return HashingLogic::hexHash(nValue, thisKey, toHash.length());                             //hash the value using the key
    }


