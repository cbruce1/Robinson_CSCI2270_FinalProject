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
        void addTrackToLib(std::string in_band, std::string in_cd, std::string in_title); //add individual track to music library
        void addTrackToAlbumTree(Track *song, Track *tmp); //adds track to album tree
        void addMusic(); //
        void addTrack();
        void addCD();
        void removeMusic();
        void removeTrack();
        void removeCD();
        void searchMusic();
        void searchTrack();
        void searchCD();
        void printList();
        void printLib();
        void trackToFront(std::string title);
        void trackToEnd (std::string title);
        void CDtoFront (std::string cd);
        void CDtoEnd (std::string cd);
        void deleteList();
        Track *searchTrack(std::string title);
        Track *searchCd(std::string cd);

        //void addTrackPub();
        //void addCDPub();
        //void removeTrackPub();
        //void removeCDPub();

    protected:

    private:

        Track *headLib;
        //Track *lastLib;
        //Track *headList;
        //Track *lastList;
        int numTracks;
        std::deque<Track> q;
};

#endif // PLAYLIST_H
