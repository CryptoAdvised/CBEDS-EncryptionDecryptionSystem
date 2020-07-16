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

const string b81d895750aed = "7b81d895750aed12c515244cbfab1a76f0834ba31e37591bdf083874570a0c7eda46f848784dc2842aacc9cd1d4338d9b94eaf09f3f4238febcc4e08c7ba288989f9960a29735934d24ec1cae10a28b70d24350b3273a3fc66115c7945e9fa3df7eeaea357e5043420d498a8311a7e19e19124c6684c9c1f057413ce15aebcb8763e6312f1603243658d8d2196ba31c6f8e0b430655af83c89b486ea00bea2f46588f4145063817f0ddc94dbffc9b4e2f833f72c7e6a69c6ce08779c7fdc79982cd8d16fb74";

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
