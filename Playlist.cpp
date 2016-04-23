#include "Playlist.h"
#include <fstream>
#include <string>
#include <iostream>
#include <deque>

using namespace std;

Playlist::Playlist()
{
    //ctor
}

Playlist::~Playlist()
{
    //dtor
}

bool Playlist::createLib(){
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
        cout<<"Band: "<<band<<" CD: "<<cd<<" Title: "<<title<<endl;
        addTrackToLib(band, cd, title);
    }
    return true;
}

void Playlist::addTrackToLib(std::string in_band, std::string in_cd, std::string in_title){
    Track *song = new Track(in_band, in_cd, in_title);
    Track *tmp=headLib;
    if (tmp==NULL){
        headLib = song;
        cout<<"Head: "<<headLib->title<<endl;
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
                addTrackToAlbumTree(song, tmp);
            else
                tmp->nextCD=song;
        }
        else
            tmp->nextBand=song;
    }
}

void Playlist::addTrackToAlbumTree(Track *song, Track *tmp){
    std::string titleToAdd=song->title;
    int a=0;
    Track *prev=tmp;
    while (tmp!=NULL){
        prev=tmp;
        a = titleToAdd.compare(tmp->title);
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

void Playlist::addMusic(){}
void Playlist::addTrack(){}
void Playlist::addCD(){}
void Playlist::removeMusic(){}
void Playlist::removeTrack(){}
void Playlist::removeCD(){}
void Playlist::searchMusic(){}
void Playlist::searchTrack(){}
void Playlist::searchCD(){}
void Playlist::printList(){}
void Playlist::printLib(){}
void Playlist::trackToFront(std::string title){}
void Playlist::trackToEnd (std::string title){}
void Playlist::CDtoFront (std::string cd){}
void Playlist::CDtoEnd (std::string cd){}
void Playlist::deleteList(){}
Track *Playlist::searchTrack(std::string title){}
Track *Playlist::searchCd(std::string cd){}
