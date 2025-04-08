# Encryption
## Description
This is a basic project of encryption, the method of encryption that is used in these files is XOR. Which transfornm a password into a encrypted password, and it is saved in a txt file.
### explanation of Code

#### XOR

Inside of the encrypion file, It is found the XOR algorithm.

                string encrypt(const string pass, const string key){
                    string result = pass;
                    for(size_t i = 0; i<pass.size(); i++){
                    result[i] = pass[i] ^ key[i % key.size()];
                    }
                    return result;
                }

1. The loops works on every character (i)

2. key[i % key.size()] :Allows the key to repeat if it's shorter than the password.

