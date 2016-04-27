#include "Playlist.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include <iomanip>

using namespace std;

Playlist::Playlist(){
    headLib=NULL;
    //ctor
}

Playlist::~Playlist(){
    //dtor
}

//program initializes object of playlist class
//Music library of structs successfully created from list of songs, albums and bands listed in a text file.
bool Playlist::createLib(){
    return readInTracks();
}

//PRIVATE: program initializes object of playlist class. Called by public createLib()
//Music library text file successfully opened music library of structs successfully created from list of songs, albums and bands listed in a text file.
bool Playlist::readInTracks(){
    headLib = NULL;
    std::string title;
    std::string cd;
    std::string band;
    ifstream inFile("MusicLibrary.txt");
    if(inFile.fail()){
        cout<<"There was a problem accessing the music library. Goodbye!"<<endl;
            return false;
    }
    string s;
    getline(inFile,s);
    string pieceOfData;
    while(getline(inFile,s)){
        stringstream myStringStream(s);
        getline(myStringStream, pieceOfData, ',');
        band = pieceOfData;
        getline(myStringStream, pieceOfData, ',');
        cd = pieceOfData;
        getline(myStringStream, pieceOfData, ',');
        title = pieceOfData;
        addTrackToLib(band, cd, title);
    }
    return true;
}


//three strings - band name, cd name, and song title
//Track struct created with band, cd and title string variables
//Band's first song struct linked to from previous band
//Band's first song CD struct linked to from previous CD song strucct
void Playlist::addTrackToLib(std::string in_band, std::string in_cd, std::string in_title){
    Track *song = new Track(in_band, in_cd, in_title);
    Track *tmp=headLib;
    if (tmp==NULL)
        headLib = song;
    else{
        while (song->band!=tmp->band && tmp->nextBand!=NULL)
                tmp=tmp->nextBand;
        if (song->band==tmp->band){
            while (song->cd!=tmp->cd && tmp->nextCD!=NULL)
                tmp=tmp->nextCD;
            if (song->cd==tmp->cd)
                addTrackToTree(song, tmp);
            else
                tmp->nextCD=song;
        }
        else
            tmp->nextBand=song;
    }
}

//song struct created. Placed in linked list of bands or CDs if it is the Band's first CD or CDs first song
//song placed in CD BST. Pointers to parent, right child and left child.
void Playlist::addTrackToTree(Track* song, Track* tmp){
    int sCompareVal=0;
    Track *prev=tmp;
    while (tmp!=NULL){
        prev=tmp;
        sCompareVal = song->title.compare(tmp->title);
        if (sCompareVal<0)
            tmp=tmp->lChild;
        else
            tmp=tmp->rChild;
    }
    if (sCompareVal <0){
        prev->lChild=song;
        song->parent=prev;
    }
    else if (sCompareVal>0){
        prev->rChild=song;
        song->parent=prev;
    }
}

//music library read in from text file
//traverse the Band linked list, and the CD linked list until each Band and CD in library accessed
void Playlist::printLib(){
    if (headLib==NULL)
        cout<<"Music library is empty."<<endl;
    else {
        cout<<left;
        Track *tmpBand=headLib;
        Track *tmpCD;
        Track *tmpTrack;
        while (tmpBand!=NULL){
            tmpCD=tmpBand;
            while (tmpCD!=NULL){
                tmpTrack=tmpCD;
                printCDTree(tmpTrack);
                tmpCD=tmpCD->nextCD;
            }
            tmpBand=tmpBand->nextBand;
        }
    }
}

//struct is in CD tree
//print each song in a CD tree in alphabetical order
void Playlist::printCDTree(Track* song){
        if (song->lChild!=NULL)
            printCDTree(song->lChild);
        cout<<setw(15)<<song->band<<setw(26)<<song->cd<<song->title<<endl;
        if (song->rChild!=NULL)
            printCDTree(song->rChild);
}

//library has been read in from text file
//confirm struct is found. Add found struct(s) to playlist deque if requested.
void Playlist::searchLib(){
    if (headLib==NULL)
        cout<<"Music library is empty."<<endl;
    else{
        string in_title;
        string add;
        Track *found;
        cout<<"Enter a song title (to search for a CD enter 'cd', to search for a band enter 'b'): ";
        getline(cin, in_title);
        if (in_title=="cd"){
            cout<<"CD title: ";
            getline (cin, in_title);
            found = searchLibByCD(in_title);
            if (found!=NULL){
                cout<<"Found: "<<found->cd<<endl;
                cout<<"Add to playlist? ('y' or 'n'): ";
                getline(cin, add);
                if (add=="y"){
                    addCDToPL(found);
                    cout<<found->cd<<" added!"<<endl;
                }
            }
            else
                cout<<"CD not found."<<endl;
        }
        else if (in_title=="b"){
            cout<<"Band name: ";
            getline (cin, in_title);
            found = searchLibByBand(in_title);
            if (found!=NULL){
                cout<<"Found: "<<found->band<<endl;
                cout<<"Add to playlist? ('y' or 'n'): ";
                getline(cin, add);
                if (add=="y"){
                    while (found!=NULL){
                        addCDToPL(found);
                        cout<<in_title<<": "<<found->cd<<" added!"<<endl;
                        found=found->nextCD;
                    }
                }
            }
            else
                cout<<"Band not found."<<endl;
        }
        else {
            found = searchLibByTrack(in_title);
            if (found!=NULL){
                cout<<"Found: "<<found->title<<endl;
                cout<<"Add to playlist? ('y' or 'n'): ";
                getline(cin, add);
                if (add=="y"){
                    addToDeque(found);
                    cout<<found->title<<" added!"<<endl;
                }
            }
            else
                cout<<"Track not found."<<endl;
        }
    }

}

//music library successfully read in, user enters valid string for song title
//return pointer to struct if found
Track *Playlist::searchLibByTrack(std::string in_song){
    Track *tmpTrack, *tmpCD, *tmpBand;
    tmpBand=headLib;
    int compareVal;
    while (tmpBand!=NULL){
        tmpCD=tmpBand;
        while (tmpCD!=NULL){
            tmpTrack=tmpCD;
            while (tmpTrack!=NULL){
                compareVal=in_song.compare(tmpTrack->title);
                if (compareVal<0)
                    tmpTrack=tmpTrack->lChild;
                else if (compareVal>0)
                    tmpTrack=tmpTrack->rChild;
                else
                    return tmpTrack;
            }
            tmpCD=tmpCD->nextCD;
        }
        tmpBand=tmpBand->nextBand;
    }
    return NULL;
}

//music library successfully read in, user enters valid string for CD name
//return pointer to first struct in CD BST
Track *Playlist::searchLibByCD(std::string in_cd){
    Track *tmpBand, *tmpCD, *tmpTrack;
    tmpBand=headLib;
    while (tmpBand!=NULL){
        tmpCD=tmpBand;
        while (tmpCD!=NULL){
            if (tmpCD->cd==in_cd)
                return tmpCD;
            else
                tmpCD=tmpCD->nextCD;
        }
        tmpBand=tmpBand->nextBand;
    }
    return NULL;
}

//music library successfully read in, user enters valid string for band name
//return pointer to struct in linked list of bands. Struct also points to the Band's first CD list and the first song in the first CD's BST.
Track* Playlist::searchLibByBand(std::string in_band){
    Track *tmpBand, *tmpCD, *tmpTrack;
    tmpBand=headLib;
    while (tmpBand!=NULL){
        if (tmpBand->band==in_band)
            return tmpBand;
        tmpBand=tmpBand->nextBand;
    }
    return NULL;
}

//music library successfully read in, user enters valid string for band, song or CD title
//pointer(s) to struct(s) added to playlist deque
void Playlist::addToPL(){
    std::string in_title;
    //bool found = false;
    Track *found;
    cout<<"Enter song title and then press <enter>. When are done adding tracks, press 'q' (to add a CD enter 'cd', to add a Band enter 'b'): ";
    getline(cin, in_title);
    if (in_title=="cd"){
        cout<<"Enter a CD title: ";
        getline(cin, in_title);
        found = searchLibByCD(in_title);
        if (found!=NULL){
            addCDToPL(found);
            cout<<in_title<<" added!\n";
        }
        else
            cout <<"CD not found."<<endl;
    }
    else if (in_title=="b"){
        cout<<"Enter a band: ";
        getline(cin, in_title);
        found = searchLibByBand(in_title);
        if (found!=NULL){
            while (found!=NULL){
                addCDToPL(found);
                cout<<found->cd<<" by "<<found->band<<" added!"<<endl;
                found=found->nextCD;
            }
        }
        else
            cout<<"Band not found."<<endl;
    }
    else{
        while (in_title!="q"){
            found = searchLibByTrack(in_title);
            if (found!=NULL){
                addToDeque(found);
                cout<<found->title<<" added!"<<endl;
            }
             else
                cout<<"Track not found. Enter another track or press 'q' to return to the main menu: ";
            getline(cin, in_title);
        }
    }
}

//music library successfully read in, valid pointer to song struct received
//pointer to song struct added to playlist deque
void Playlist::addToDeque(Track *song){
    dq.push_back(song);
    ++numTracks;
}

//music library successfully read in, valid pointer to CD BST root received
//pointer to each song/struct in CD BST added to playlist deque
void Playlist::addCDToPL(Track* song){
        if (song->lChild!=NULL)
            addCDToPL(song->lChild);
        addToDeque(song);
        if (song->rChild!=NULL)
            addCDToPL(song->rChild);
}

//music library successfully read in, valid string for band name, song title or CD title received
//pointer(s) removed from playlist deque
void Playlist::removeFromPL(){
    if (dq.size()==0)
        cout<<"The playlist is empty."<<endl;
    else{
        string in_song;
        cout<<"Which song would you like to remove?\n to remove a CD enter 'cd'\n to remove a band enter 'b'\n to clear all enter 'delete'\n ";
        getline(cin, in_song);
        if (in_song=="cd"){
            cout<<"Enter a CD title: ";
            getline (cin, in_song);
            removeCDFromPL(in_song);
        }
        else if (in_song=="b"){
            cout<<"Enter a band: ";
            getline (cin, in_song);
            removeBandFromPL(in_song);
        }
        else if (in_song=="delete")
            deletePL();
        else
            removeTrackFromPL(in_song);
    }
}

//music library successfully read in, valid string song title received
//pointer to struct removed from deque, debug deque element count decremented
void Playlist::removeTrackFromPL(std::string in_song){
    bool found = false;
    int dqSize=dq.size();
    for (int i=0; i<dqSize; i++){
        if (dq.at(i)->title==in_song){
            dq.erase(dq.begin()+i);
            found = true;
            --numTracks;
            cout<<in_song<<" removed.\n";
            break;
        }
    }
    if (!found)
        cout<<"Song not found."<<endl;
}

//music library successfully read in, valid string CD title received
//pointer to structs with matching cd string var removed from deque, debug deque element count decremented
void Playlist::removeCDFromPL(std::string in_song){
    bool found = false;
    int i=0;
    int dqSize=dq.size();
    while (i<dqSize){
        if (dq.at(i)->cd==in_song){
            dq.erase(dq.begin()+i);
            --dqSize;
            found = true;
            i=i;
            --numTracks;
        }
        else
            ++i;
    }
    if (found==false)
        cout<<"CD not found."<<endl;
    else
        cout<<in_song<<" removed.\n";
}


//music library successfully read in, valid band name string  received
//pointer to structs with matching band string var removed from deque, debug deque element count decremented
void Playlist::removeBandFromPL(std::string in_song){
    bool found = false;
    int i=0;
    int dqSize=dq.size();
    while (i<dqSize){
        if (dq.at(i)->band==in_song){
            dq.erase(dq.begin()+i);
            --dqSize;
            found = true;
            i=i;
            --numTracks;
        }
        else
            ++i;
    }
    if (found==false)
        cout<<"Band not found."<<endl;
    else
        cout<<in_song<<" removed.\n";

}

//playlist deque is not empty
//all title string from struct pointers in deque output in order
void Playlist::printPL(){
    int dqSize=dq.size();
    if (dqSize==0)
        cout<<"There are no songs in the playlist."<<endl;
    else{
        cout<<"\n"<<"************ Playlist ************"<<endl;
        for(int i=0; i<dqSize; i++){
            cout<<dq.at(i)->title<<endl;
        }
        cout<<"**********************************\n"<<endl;
    }
}

//playlist deque not empty
//all items from playlist removed
void Playlist::deletePL(){
    string y;
    cout<<"Are you sure you want to delete the playlist? ('y' or 'n'): ";
    getline(cin, y);
    if (y=="y"){
        dq.clear();
        cout<<"Playlist deleted."<<endl;
        numTracks=0;
    }
}



