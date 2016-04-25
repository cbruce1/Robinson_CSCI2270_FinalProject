#include "Playlist.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

Playlist::Playlist(){
    headLib=NULL;
    //ctor
}
Playlist::~Playlist(){
    //dtor
}
bool Playlist::createLib(){
    return readInTracks();
}
bool Playlist::readInTracks(){
    headLib = NULL;
    std::string title;
    std::string cd;
    std::string band;
    std::string textIn;
    ifstream inFile("Final4.txt");
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

void Playlist::addTrackToLib(std::string in_band, std::string in_cd, std::string in_title){
    Track *song = new Track(in_band, in_cd, in_title);
    Track *tmp=headLib;
    if (tmp==NULL){
        headLib = song;
    }
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
void Playlist::addTrackToTree(Track* song, Track* tmp){
    //std::string titleToAdd=song->title;
    int a=0;
    Track *prev=tmp;
    while (tmp!=NULL){
        prev=tmp;
        a = song->title.compare(tmp->title);
        if (a<0)
            tmp=tmp->lChild;
        else
            tmp=tmp->rChild;
    }
    if (a <0){
        prev->lChild=song;
        song->parent=prev;
    }
    else if (a>0){
        prev->rChild=song;
        song->parent=prev;
    }
}
void Playlist::printLib(){
    if (headLib==NULL)
        cout<<"Music library is empty."<<endl;
    else {
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

void Playlist::printLibByBand(){
    if (headLib==NULL)
        cout<<"Music library is empty."<<endl;
    else {
        Track *tmpBand=headLib;
        Track *tmpCD, *tmpTrack;
        while (tmpBand!=NULL){
            tmpCD=tmpBand;
            cout<<"** "<<tmpBand->band<<" **"<<endl;
            while (tmpCD!=NULL){
                cout<<tmpCD->cd<<":\n";
                tmpTrack=tmpCD;
                printCDTreeSongOnly(tmpTrack);
                tmpCD=tmpCD->nextCD;
                cout<<"\n"<<endl;
            }
            tmpBand=tmpBand->nextBand;
        }
    }
}

void Playlist::searchLibByBand(){
    cout<<"\n";
    if (headLib==NULL)
        cout<<"Music Library is empty."<<endl;
    else{
        string in_band;
        Track *tmpBand, *tmpCD, *tmpTrack;
        cout<<"Enter a band or artist name: ";
        getline(cin, in_band);
        while (in_band!="q"){
            tmpBand=headLib;
            while (tmpBand!=NULL && tmpBand->band!=in_band){
                tmpBand=tmpBand->nextBand;
            }
            if (tmpBand->band==in_band){
                tmpCD=tmpBand;
                while (tmpCD!=NULL){
                    tmpTrack=tmpCD;
                    printCDTreeSongOnly(tmpTrack);
                    tmpCD=tmpCD->nextCD;
                }
            }
            else{
                cout<<"Band/Artist not found."<<endl;
                cout<<"Enter another band/artist or 'q' to return to main menu: ";
                getline (cin, in_band);
            }
        }
    }
}

void Playlist::printCDTree(Track* song){
        if (song->lChild!=NULL)
            printCDTree(song->lChild);
        cout<<song->band<<", "<<song->cd<<", "<<song->title<<endl;
        if (song->rChild!=NULL)
            printCDTree(song->rChild);
}

void Playlist::printCDTreeSongOnly(Track* song){
        if (song->lChild!=NULL)
            printCDTreeSongOnly(song->lChild);
        cout<<song->title<<", ";
        if (song->rChild!=NULL)
            printCDTreeSongOnly(song->rChild);
}

void Playlist::searchLib(){
    string songTitle;
    string add;
    Track *found;
    cout<<"Enter a song title: ";
    getline(cin, songTitle);
    found = searchLibByTrack(songTitle);
    if (found!=NULL){
        cout<<"Found track: "<<found->title<<endl;
        cout<<"Do you want to add it to your playlist? ('y' for yes, 'n' for no)"<<endl;
        getline(cin, add);
        if (add=="y"){
            addToPL(found);
            cout<<found->title<<" has been added!"<<endl;
        }
    }
    else
        cout<<"Track not found."<<endl;

}

Track *Playlist::searchLibByTrack(std::string song){
    Track *tmpTrack;
    Track *tmpCD;
    Track *tmpBand=headLib;
    int compareVal;
    while (tmpBand!=NULL){
        tmpCD=tmpBand;
        while (tmpCD!=NULL){
            tmpTrack=tmpCD;
            while (tmpTrack!=NULL){
                compareVal=song.compare(tmpTrack->title);
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

void Playlist::searchLibByCD(){}

void Playlist::addToPL(Track *in_song){
    if (in_song!=NULL)
        q.push_back(in_song);
    else{
        std::string title;
        Track *song;
        cout<<"Please enter a track name and then press enter."<<endl;
        cout<<"When you are done adding tracks, press 'q' to return to the main menu."<<endl;
        getline(cin, title);
        while (title!="q"){
            song = searchLibByTrack(title);
            if (song!=NULL){
                q.push_back(song);
                cout<<song->title<<" added to playlist."<<endl;
            }
            else
                cout<<"Track not found. Enter another track name or press 'Q' to go back to the main menu: ";
            getline(cin, title);
        }
    }
}

Track *Playlist::addTrackToPL(std::string song){}
void Playlist::addCDToPL(){}
void Playlist::removeFromPL(){}
void Playlist::removeTrackFromPL(){}
void Playlist::removeCDFromPL(){}

void Playlist::printPL(){
    Track *dequeItem = q.front();
    int qsize=q.size();
    if (qsize==0)
        cout<<"There are no songs in the playlist."<<endl;
    else{

        cout<<"\n"<<"************ Playlist ************"<<endl;
        for (int i=0; i<qsize; i++){
            cout<<q[i]->title<<endl;
        }
        cout<<"**********************************\n"<<endl;
    }
}

void Playlist::deletePL(){}
Track *Playlist::searchPLByTrack(std::string title){}
Track *Playlist::searchPLByCD(std::string cd){}

void Playlist::trackToFront(std::string title){}
void Playlist::trackToEnd (std::string title){}
void Playlist::CDtoFront (std::string cd){}
void Playlist::CDtoEnd (std::string cd){}


