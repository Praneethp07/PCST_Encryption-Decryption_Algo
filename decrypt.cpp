#include<bits/stdc++.h>
using namespace std;

void rotateColumnUp(vector<vector<char>>& vec, int colNum, int n) {
    int numRows = vec.size();
    for (int i = 0; i < n; i++) {
        int temp = vec[0][colNum];
        for (int j = 0; j < numRows - 1; j++) {
            vec[j][colNum] = vec[j + 1][colNum];
        }
        vec[numRows - 1][colNum] = temp;
    }
}

void rotateColumnDown(vector<vector<char>>& vec, int colNum, int n) {
    int numRows = vec.size();
    for (int i = 0; i < n; i++) {
        int temp = vec[numRows - 1][colNum];
        for (int j = numRows - 1; j > 0; j--) {
            vec[j][colNum] = vec[j - 1][colNum];
        }
        vec[0][colNum] = temp;
    }
}
void decrypt(){
    int rows,ReadPtr;
    string key;
    cout<<endl<<"Enter The KEY"<<endl;
    cin>>key;
    int n=key.size();
   
    int no_of_characters = n/3;
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
    cout<<"Enter The Cipher-Text To Be Decrypted: "<<endl;
    vector<vector<char>> CipherTextMatrix(rows, vector<char>(no_of_characters));

    // Read input for the 2D vector
    for (int i = 0; i < CipherTextMatrix.size(); i++) {
        for (int j = 0; j < CipherTextMatrix[i].size(); j++) {
            cin >> CipherTextMatrix[i][j];
        }
    }
      
    cout<<endl;

    
    string subkey;
        for(int i = 0; i < n; i += 3) {
            int k = i;
            subkey = key.substr(k, 3);

            char ind = subkey[0];
            int index = ind - '0';
            char m = subkey[1];
            int moves = m - '0';
            char direction = subkey[2];
            // cout<<index<<moves<<direction<<endl;
            if(direction == '|'){
                continue;
            }
            else if(direction == '$'){
                rotateColumnDown(CipherTextMatrix,index,moves);
                // cout<<"rotated down"<<endl;
            }else if(direction == '^'){
                rotateColumnUp(CipherTextMatrix,index,moves);
                // cout<<"rotated up"<<endl;
            }
            
        }
        cout<<"The decryped text is: ";
        for(int i=0;i<no_of_characters;i++){
            cout<<CipherTextMatrix[ReadPtr][i];
        }
        cout<<endl;

}
int main(){
   
    decrypt();
    return 0;
}