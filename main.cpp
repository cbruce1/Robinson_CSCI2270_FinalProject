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
    string schoice;
    int choice = 0;
    cout<<"\n************ Main Menu ************"<<endl;
    cout<<"*                                 *"<<endl;
    cout<<"*  1) View music library          *"<<endl;
    //cout<<" 1) View library"<<endl;
    cout<<"*  2) Search music library        *"<<endl;
    cout<<"*  3) Add music to playlist       *"<<endl;
    cout<<"*  4) Remove music from playlist  *"<<endl;
    cout<<"*  5) View playlist               *"<<endl;
    cout<<"*  6) Quit                        *"<<endl;
    cout<<"*                                 *"<<endl;
    cout<<"***********************************"<<endl;
    cout<<"Please enter your selection: ";
    std::getline(std::cin, schoice);
    choice=stoi(schoice);
//    cin.ignore();
    while (choice > 6 || choice <1){
        cout<<"Please enter a valid choice: ";
        std::getline(std::cin, schoice);
        choice=stoi(schoice);
    }
    return choice;

}

int main()
{
    Playlist p;
    if (!p.createLib())
        return 0;

    int choice = menu();
    while (choice !=6){
        if (choice==1)
            p.printLib();
            //p.printLibByBand();
        else if (choice==2)
            p.searchLib();
        else if (choice==3)
            p.addToPL(NULL);
        else if (choice==4)
            p.removeFromPL();
        else if (choice==5)
            p.printPL();
        choice=menu();
    }
    cout <<"Goodbye!"<<endl;
    return 0;
}
