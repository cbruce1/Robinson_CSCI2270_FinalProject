#include "Playlist.h"

Playlist::Playlist()
{
    //ctor
}

Playlist::~Playlist()
{
    //dtor
}

void Playlist::createLib(){}
void Playlist::addTrack(){}
void Playlist::addCD(){}
void Playlist::removeTrack(){}
void Playlist::removeCD(){}
void Playlist::printList(){}
void Playlist::printLib(){}
void Playlist::trackToFront(std::string title){}
void Playlist::trackToEnd (std::string title){}
void Playlist::CDtoFront (std::string cd){}
void Playlist::CDtoEnd (std::string cd){}
void Playlist::deleteList(){}
track *Playlist::searchTrack(std::string title){}
track *Playlist::searchCd(std::string cd){}
