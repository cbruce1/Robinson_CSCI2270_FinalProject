#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <fstream>
#include <deque>

struct Track{
    std::string title;
    std::string cd;
    std::string band;
    //std::string genre;
    //track *nextLib;
    //track *prevLib;
    Track *parent;
    Track *rChild;
    Track *lChild;
    Track *nextBand;
    Track *nextCD;

    Track(){};

    Track(std::string in_band, std::string in_cd, std::string in_title)
	{
		title = in_title;
		cd = in_cd;
		band = in_band;
    //  nextList = NULL;
	//	prevList = NULL;
        parent = NULL;
        rChild = NULL;
        lChild = NULL;
        nextBand=NULL;
        nextCD=NULL;
	}

};


class Playlist
{
    public:
        Playlist();
        virtual ~Playlist();
        bool createLib(); //reads in track information from txt file
        bool readInTracks();
        void addTrackToLib(std::string in_band, std::string in_cd, std::string in_title); //add individual track to music library
        void addTrackToTree(Track *song, Track *tmp); //adds track to album tree
        void printLib();
        void printCDTree(Track *song);
        void searchLib();
        Track *searchLibByTrack(std::string song);
        void searchLibByCD();
        void addToPL(); //
        Track *addTrackToPL(std::string song);
        void addCDToPL();
        void removeFromPL();
        void removeTrackFromPL();
        void removeCDFromPL();
        void printPL();
        void deletePL();
        Track *searchPLByTrack(std::string title);
        Track *searchPLByCD(std::string cd);


        void trackToFront(std::string title);
        void trackToEnd (std::string title);
        void CDtoFront (std::string cd);
        void CDtoEnd (std::string cd);


    protected:

    private:

        Track *headLib;
        int numTracks;
        std::deque<Track*> q;




};

#endif // PLAYLIST_H
