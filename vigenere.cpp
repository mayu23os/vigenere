#include<iostream>
#include<string.h>
using namespace std;
 
string genkey(char msg[],char key[])
{
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
    char newKey[msgLen];
    
    for(i = 0, j = 0; i < msgLen; ++i, ++j)
    {
        if(j == keyLen)
            j = 0; 
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    return newKey;
} 

string encrypt(char msg[],string newKey,int msgLen)
{
    char eMsg[msgLen];
    int i;
    for( i = 0; i < msgLen; i++)
        eMsg[i] = ((msg[i] + newKey[i]) % 26) + 65;
 
    eMsg[i] = '\0'; 
    return eMsg;
}

string decrypt(string eMsg,string newKey,int msgLen)
{
    int i;
    char  dMsg[msgLen];
    for(i = 0; i < msgLen; i++)
        dMsg[i] = (((eMsg[i] - newKey[i]) + 26) % 26) + 65;
    dMsg[i] = '\0';
    return dMsg;
}

int main(){
    char msg[] = "HELLOWORLD";
    char key[] = "YES";
    int msgLen = strlen(msg), keyLen = strlen(key);
 
    string newKey,encryptedMsg,decryptedMsg;
  
    newKey=genkey(msg,key);
    encryptedMsg=encrypt(msg,newKey,msgLen);
    decryptedMsg=decrypt(encryptedMsg,newKey,msgLen);
    cout<<"Original : "<<msg;
    cout<<"\nEncrypted : "<<encryptedMsg;
    cout<<"\nDecrypted : "<<decryptedMsg;
 
	return 0;
}