#include <iostream>
#include <string.h>

using  namespace std;

int main()
{
    char message[500];
    int i, j, lenght, choice, key;
    
    cout<<"enter message :";
    cin.getline(message, 100);
    
    cout<<"enter key"; cin>>key;
    lenght = strlen(message);
    cout<<"1. Encrypt "<<endl<<"2. decrypt "<<endl;
    cout<<"enter choice: "; cin>>choice;

    if(choice == 1)
    {
        char ch;
        for(int i =0; message[i] != '\0'; i++)
        {
            ch = message[i];
            if(ch >= 'a' && ch <= 'z')
            {
                ch = ch + key;
                if(ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                ch = ch + key;
                if(ch > 'Z')
                {
                    ch = ch - 'Z' + 'A' -1;
                }
                message[i] = ch;
            }
        }
        printf("message: %s",message);
    }
    else if(choice == 2)
    {
        char ch;
        for(int i =0; message[i] != '\0'; i++)
        {
            ch = message[i];
            if(ch>= 'a' && ch <= 'Z')
            {
                ch = ch - key;
                if(ch < 'a')
                {
                    ch = ch + 'z' - 'a' + 1;
                }
                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                ch = ch - key;
                if(ch < 'A')
                {
                    ch = ch + 'Z' - 'A' + 1;
                }
                message[i] = ch;
            }
        }
        cout<<"decrypt message :"<<message;
    }
    return 0;
}