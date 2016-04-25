#include "Playlist.h"
#include <fstream>
#include <string>
#include <iostream>
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
    ifstream inFile("Final.txt");
    if(inFile.fail()){
        cout<<"There was a problem accessing the music library. Goodbye!"<<endl;
            return false;
    }
    while (getline(inFile, band, ',')){
        getline(inFile, cd, ',');
        getline (inFile, title, '\n');
        //cout<<"Band: "<<band<<" CD: "<<cd<<" Title: "<<title<<endl;
        addTrackToLib(band, cd, title);
    }
    return true;
}
void Playlist::addTrackToLib(std::string in_band, std::string in_cd, std::string in_title){
    Track *song = new Track(in_band, in_cd, in_title);
    Track *tmp=headLib;
    if (tmp==NULL){
        headLib = song;
        //cout<<"Head: "<<headLib->title<<endl;
    }
    else{
        while (song->band!=tmp->band && tmp->nextBand!=NULL){
                tmp=tmp->nextBand;
        }
        if (song->band==tmp->band){
            while (song->cd!=tmp->cd && tmp->nextCD!=NULL){
                tmp=tmp->nextCD;
            }
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
void Playlist::printCDTree(Track* song){
        if (song->lChild!=NULL)
            printCDTree(song->lChild);
        cout<<song->band<<", "<<song->cd<<", "<<song->title<<endl;
        if (song->rChild!=NULL)
            printCDTree(song->rChild);
}
void Playlist::searchLib(){}

Track *Playlist::searchLibByTrack(std::string song){
    Track *tmpTrack;
    Track *tmpCD;
    Track *tmpBand=headLib;
    std::string seval;
    int compareVal;
    int a;
    while (tmpBand!=NULL){
        tmpCD=tmpBand;
        while (tmpCD!=NULL){
            tmpTrack=tmpCD;
            while (tmpTrack!=NULL){
                seval=tmpTrack->title;
                a=seval.size();
                cout<<"seval: "<<seval<<endl;
                compareVal=song.compare(seval);
                cout<<"Looking at: "<<seval<<endl;
                cout<<"Size: "<<a;
                cout<<" Compare value is: "<<compareVal<<endl;
                if (compareVal<0)
                    tmpTrack=tmpTrack->lChild;
                else if (compareVal>0)
                    tmpTrack=tmpTrack->rChild;
                else if (compareVal==0)
                    return tmpTrack;
                if (tmpTrack==NULL)
                    cout<<"At end of while loop, track is NULL"<<endl;
                else
                    cout<<"At end of while loop, track is: "<<tmpTrack->title<<endl;
            }
            tmpCD=tmpCD->nextCD;
        }
        tmpBand=tmpBand->nextBand;
    }
    return NULL;
}
void Playlist::searchLibByCD(){}

void Playlist::addToPL(){
    std::string title;
    Track *song;
    cout<<"Please enter a track name and then press enter."<<endl;
    cout<<"When you are done adding tracks, press 'q' to return to the main menu."<<endl;
    cin>>title;
    cin.ignore();
    while (title!="q"){
        song = searchLibByTrack(title);
        if (song!=NULL)
            q.push_back(song);
        else
            cout<<"Track not found. Enter another track name or press 'Q' to go back to the main menu: ";
        getline(cin, title);
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
        cout<<"**** Playlist ****"<<endl;
        for (int i=0; i<qsize; i++){
        cout<<dequeItem[i].title<<endl;
        }
    }
}
void Playlist::deletePL(){}
Track *Playlist::searchPLByTrack(std::string title){}
Track *Playlist::searchPLByCD(std::string cd){}

void Playlist::trackToFront(std::string title){}
void Playlist::trackToEnd (std::string title){}
void Playlist::CDtoFront (std::string cd){}
void Playlist::CDtoEnd (std::string cd){}


