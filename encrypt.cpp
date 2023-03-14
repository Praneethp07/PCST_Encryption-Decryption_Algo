#include <bits/stdc++.h>
// #include "decrypt.cpp"
using namespace std;


void Encrypt(){
    char letters [52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int rows;
    int ReadPtr;
    int no_of_characters;
    string message;
    cout<<"Enter the message:"<<endl;
    cin>>message;
    no_of_characters = message.size();
    
    if(no_of_characters > 10){
        rows = 11;
        ReadPtr = 5;
    }else if(no_of_characters < 7){
        rows = 5;
        ReadPtr = 2;
    }
    else{
        rows = 7;
        ReadPtr = 3;
    }
    char CipherTextMatrix[rows][no_of_characters];
    for(int i=0;i<rows;i++){
        for(int j=0;j<no_of_characters;j++){
            CipherTextMatrix[i][j] = '#';
        }
        
    }
    for(int character=0; character<no_of_characters; character++){
            CipherTextMatrix[0+(rand()%rows )][character] = message[character];
    }



    
    //key generation 
    string key = "";
    string symbol;
    for(int row=0;row<rows;row++){    
        for(int col=0; col<no_of_characters; col++){
            if(CipherTextMatrix[col][row]!='#'){
                int val = ReadPtr-col;
                if(val ==  0){
                    symbol = "|";
                }else if(val < 0){
                    symbol = "^";
                }else if(val > 0){
                    symbol = "$";
                }
                string s = to_string(row)+""+to_string(abs(ReadPtr-col));
                key.append(s);
                key.append(symbol);
            }
            else{            
                // key.append(to_string(row));
                // key+=char(col);lse{
                continue;
            }
        }
    }



    //filling the blank spaces


    for(int i=0;i<rows;i++){
        for(int j=0;j<no_of_characters;j++){
            if((CipherTextMatrix[i][j]) == '#'){
                CipherTextMatrix[i][j] = letters[0+(rand()%53)];
            }

        }
    }
    cout<<"_______Cipher-Text________"<<endl;
    cout<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<no_of_characters;j++){
            cout<<CipherTextMatrix[i][j]<<" ";
        }
        cout<<endl;
       
    }
    cout<<"________________________________"<<endl;
    cout<<"Generated key: "<<key<<endl;
    cout<<"________________________________"<<endl;
}


int main(){
    Encrypt();
    return 0;
}






 