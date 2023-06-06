/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: nickvandaele
 *
 * Created on May 23, 2023, 11:38 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Cipher {

public:
    string key;

    Cipher(string pass) {
        
        for (int i = 0; i < pass.size(); i++) {
            if (pass[i] >= 'A' && pass[i] <= 'Z') {
                this->key += pass[i];
            }
            if (pass[i] >= 'a' && pass[i] <= 'z') {
                this->key += toupper(pass[i]);
            }
        } 
    }
    void encrypt(string &encrypt) {
        
        string out;
        int key_index = 0;
        
        for (int i = 0; i < encrypt.length(); i++) {
            
            encrypt[i] = toupper(encrypt[i]); 
            out += (encrypt[i] + key[key_index] - 2 * 'A') % 26 + 'A';
            key_index = (key_index + 1) % key.length();
        }
        encrypt = out; 
    }
    
    void decrypt(string &decrypt) {
        
        string out;
        int key_index = 0;
        
        for (int i = 0; i < decrypt.length(); i++) {
            
            decrypt[i] = toupper(decrypt[i]); 
            out += (decrypt[i] - key[key_index] + 26) % 26 + 'A';
            key_index = (key_index + 1) % key.length();   
        }
        decrypt = out;
    }
};

void decode(string key, string text) {
    
    Cipher cip(key);
    
    cout << "The key is " << key << " and the encoded text is " << text << endl;
    cip.decrypt(text);
    cout << "Decoding the cipher results in " << text << endl;
    
}

void encode(string key, string text) {
    
    Cipher cip(key);
    
    cout << "The key is " << key << " and the plain text is " << text << endl;
    cip.encrypt(text);
    cout << "Encoding with the cipher results in " << text << endl;
    
}

int main(int argc, char** argv) {

    char usr;
    string key, text;
    bool cont = true;
    
    cout << "Vignere Cipher Decoding and Encoding!" << endl;
    
    while (cont) {
    
        cout << "Would you like to encode or decode text (1 for encode, 0 for decode) ";
        cin >> usr;

        if (usr == '1') {
            cout << "Please input key for cipher: ";
            cin >> key;
            cout << "Please input plain text to encode: ";
            cin >> text;
            cout << endl;
            encode(key, text);
        }
        if (usr == '0') {
            cout << "Please input key for cipher: ";
            cin >> key;
            cout << "Please input cipher text to decode: ";
            cin >> text;
            cout << endl;
            decode(key, text);
        }

        cout << endl << "Would you like to use this tool again? (y/n) ";
        cin >> usr;

        if (usr == 'y') {
            cont = true;
            cout << endl;
        }
        else if (usr == 'n') {
            cout << endl <<"Thank you!";
            cont = false;
    }
   
    }        
    return 0;
}

