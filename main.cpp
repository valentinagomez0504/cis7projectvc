//Valentina Gomez
//Dec 8th, 2024

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

//extend length of the keyword to match plaintext.
string extendKeyword(string plaintxt, string keyword)
{
    //repeat until the keyword matches the length or goes over.
    while (keyword.length()< plaintxt.length())
    {
        //add keyword to itself.
        keyword += keyword;
    }
    
    //keyword will now match the length exactly
    return keyword.substr(0, plaintxt.length());
}
//encrypt using the vigenere cipher system.
string encrypt(string plaintxt, string keyword)
{
    //the encrypted text will be stored in the string
    string ciphertxt = "";
    for (int i = 0; i < plaintxt.length(); i++)
    {
        //convert the plain text and the keyword into number values.
        char p = plaintxt[i] - 'a';
        char k = keyword[i] - 'a';
        //    (P[i] + K[i]) % 26 and convert to letter
        char c = (p+k) % 26 + 'a';
        //add letter to cipher text
        ciphertxt += c;
    }
    //Display
    return ciphertxt;
}

//Start decrypting process using vigenere system
string decrypt(string ciphertxt, string keyword)
{
    //the decrypted text will be stored in the string
    string decryptedtxt = "";
    for (int i = 0; i < ciphertxt.length(); i++)
    {
        //convert cipher text and keyword into number values.
        char c = ciphertxt[i] - 'a';
        char k = keyword[i] - 'a';
        // (E[i] - K[i] +26) % 26) and convert result back into letter form
        char p = (c - k + 26) % 26 + 'a';
        //Add decrypted letter to the plain text
        decryptedtxt += p;

    }
    return decryptedtxt;
}
int main() 
{
    string plaintxt, keyword;
    
    cout << "Enter plain text: \n";
    cin >> plaintxt;
    cout << "Enter keyword: \n";
    cin >> keyword;
    
    //extend the keyword length
    keyword = extendKeyword(plaintxt, keyword);
    
    string ciphertxt = encrypt(plaintxt, keyword);
    cout << "Cipher text: " << ciphertxt << endl;
    
    //Decrypt cipher text back to plain text with the keyword
    string decryptedtxt = decrypt(ciphertxt, keyword);
    
    cout << "Decrypted text: \n" << decryptedtxt << endl;
    
    return 0;
}

