#include <iostream>
#include <fstream>
using namespace std;
void encryptAndWrite(string message){
    ofstream outFile("data.txt");
    for(int i=0; i<message.length(); i++){
        message[i]=message[i]+3;
    }
    outFile<<message;
    outFile.close();
    cout<<"Message encrypted and stored in the file\n";
}
string readAndDecrypt(){
    ifstream inFile("data.txt");
    string message;
    getline(inFile, message);
    inFile.close();
    for(int i = 0; i<message.length(); i++){
        message[i]=message[i]-3;
    }
    return message;
}
void displayFileContents(){
    string decryptedMessage=readAndDecrypt();
    cout<<"Decrypted Message:"<<decryptedMessage<<"\n";
}
int main(){
    string message;
    cout<<"Enter data:";
    getline(cin, message);
    encryptAndWrite(message);
    cout<<"Reading and decrypting file\n";
    displayFileContents();
    return 0;
}
