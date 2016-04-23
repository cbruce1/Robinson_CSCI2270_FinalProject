//Kristin Robinson
//CSCI 2270
//Final Project
//**PLaylist**

#include <fstream>
#include <string>
#include <iostream>
#include "Playlist.h"

using namespace std;

int menu(){
    int choice = 0;

    cout<<"1. View music library"<<endl;
    cout<<"2. Search music library"<<endl;
    cout<<"3. Add music to playlist"<<endl;
    cout<<"4. Remove music from playlist"<<endl;
    cout<<"5. View playlist"<<endl;
    cout<<"6. Quit"<<endl;
    cin>>choice;
    while (choice > 6 || choice <1){
        cout<<"Please enter a valid choice: ";
        cin>>choice;
    }
    return choice;

}

int main()
{
    Playlist p;

    bool fileOK = p.createLib();
    if (!fileOK)
        return 0;

    int choice = menu();
    while (choice !=6){
        if (choice==1)
            p.printLib();
        else if (choice==2)
            p.searchMusic();
        else if (choice==3)
            p.addMusic();
        else if (choice==4)
            p.removeMusic();
        else if (choice==5)
            p.printList();
    }
    cout <<"Goodbye!"<<endl;
    return 0;
}
