/****************************************************************************/
/*FICHIER:      CBHL.hpp                                                    */
/*AUTOR:        Colin Bouchard                      				        */
/*DATE:         09/07/2020                                                  */
/*DESCRIPTION:  This library offer the Hashing Logic.                       */
/*				                                                            */
/*				This is for learning purpose.                               */
/****************************************************************************/

#include <string>

using namespace std;

//Constant variable
const int MAX_HEX = 10;
const int MAX_HASH_SIZE = 390;
const int MAGIC_MULTIPLIER = 49;


namespace CBHL {

class HashingLogic {
    public:
    unsigned calculateKey(string key);
    void calculateNumeral (unsigned numeralValue[], string toHash);
    unsigned calculateHash (unsigned thisValue[], unsigned key, int length);
    string hexHash (unsigned nValue[], unsigned key, int length);
    string Hash(string toHash, string key);
    };

}
