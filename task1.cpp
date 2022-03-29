/*
FCAI - programming 1 - 2022 - Assignment 2
Program Name:    Rail-fence Cipher
Program Description:
Last Modification Date: 28\03\2022
Author and ID and Groub: Mina sobhy markam,20210419,B
Purpose:


*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void encrypt_message();
void discrypt_message();
int main()
{
    int answer = 0;
    while (answer != 3)
    {
        cout << "ahlan user 7abiby \nthis program work to encrypt and discrypt messages.\nplz enter number of thing what you went. \n1_encrypt.\n2_discrypt.\n3_end program.\n";
        cin >> answer;
        if (answer == 1)
            encrypt_message();
        if (answer == 2)
            discrypt_message();
        if (answer == 3) {
            cout << "good bye user (:";
            break;
        }
        else if((answer!=1)&&(answer!=3)&&(answer!=2))
            cout << "invaild number."<<endl;
        }

}

void encrypt_message()
{

    int key, i = 0 ,raws = 0;
    string word;
    cout << "plz enter key of encrypt message (number) : \n";
    cin >> key;
    cin.ignore();
    cout << "plz enter you message :\n";
    getline(cin, word);
    char arr_word[100][100];
    for (int raws = 0;raws < key;raws++) {
        for (int colm = 0;colm < size(word);colm++) {
            arr_word[raws][colm] = '*';
        }
    }

  
    int raw=0, check = 0;
    for (i = 0;i < word.length();i++) {


        if (check == 0)
        {
            arr_word[raw][i] = word[i];
            raw++;
        }
         if (raw==key)

        {
            check = 1;
            raw--;

        }
        else if (check == 1) 
        {
            raw--;
            arr_word[raw][i] = word[i];

        }
         if (raw == 0) 
         {
             check = 0;
             raw = 1;
         }

         
        

    }
    for (int k = 0;k < key;k++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr_word[k][j] != '*')
                cout << arr_word[k][j];
            }
       
    


    }
    cout << endl;

}
void discrypt_message() 
{
    int key;
    string word;
    cout << "please enter the key: ";
    cin >> key;
    cin.ignore();
    cout << "please enter the encrypted word: ";
    getline(cin, word);
    char arr_word[100][100];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < word.length(); j++)
            arr_word[i][j] = '\n';
    bool dir;
    int row = 0, colm = 0;
    for (int i = 0; i < word.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir = true;
        if (row == key - 1)
            dir = false;
        arr_word[row][colm++] = '*';
        if (dir == true)
            row++;
        if (dir == false)
            row--;
    }
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < word.length(); j++)
            if (arr_word[i][j] == '*' && index < word.length())
                arr_word[i][j] =word[index++];
    string result;
    row = 0, colm = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (row == 0)
            dir = true;
        if (row == key - 1)
            dir = false;
        if (arr_word[row][colm] != '*')
            result.push_back(arr_word[row][colm++]);
        if (dir == true)
            row++;
        if (dir == false)
            row--;
    }
    cout << "the word is: " << result << endl;






}







