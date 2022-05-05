# CBEDS-EncryptionDecryptionSystem
This library offer an Encryption/Decryption system. It is capable of encrypting and decrypting : StringToString, FileToString, StringToFile, FileToFile. So you can encrypt string and file and decrypt them very easily. You can use a key of any length making it conveniant, simple and easy to use.

For learning purpose only!

# How to use it
1. Copy CBHL.cpp, CBEDS.cpp, CBHL.hpp and CBEDS.hpp to your project directory.
2. Use this code where you need it:
```c++
[...]

#include <string>
#include "CBEDS.hpp"

CBEDS::Encrypt E;
CBEDS::Decrypt D;

string regularText, cipherText, key="thisKey";

[...]
//Encryption 
cipherText = E.String(regularText, key);
cipherText = E.FileToString("c:\\thisfile.txt", key);
E.StringToFile (regularText, "c:\\encrypted.enc", key);
E.FileToFile ("c:\\thisfile.txt", "c:\\encrypted.enc", key);

[...]
//Decryption
regularText = D.String(cipherText, key);
regularText = D.FileToString("c:\\encrypted.enc", key);
E.StringToFile (cipherText, "c:\\decrypted.txt", key);
D.FileToFile ("c:\\encrypted.enc", "c:\\decrypted.txt", key);

[...]
```

# Compiler
If you use GCC you shouldn't have any problem. 

However ***if you use VC++ compiler you'll have to uncomment line 67 and comment line 68 inside CBHL.cpp***

# Found this useful (buy me a coffee)
BTC: 3ELnV2YudPrYHmoxcSFHoLJVioVHtBLNyC

ETH: 0xd0559695c5E8907beE93Ddada87647f887F536c0

XRP: rw2ciyaNshpHe7bCHo4bRWq6pqqynnWKQg TAG: 3752863116

LTC: MNNvm3VWCRV22pQvVxDqeVb3EA5nSuCAZD

LINK: 0x21a61Ef34B058FD873bF18f848e543aF076d3A86

XTZ: tz1ZvktvngLFhpyr8JLzESWAcEJaXqQhkvUj
