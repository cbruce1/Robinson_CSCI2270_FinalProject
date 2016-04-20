#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <fstream>

struct track{
    std::string title;
    std::string cd;
    std::string band;
    //std::string genre;
    track *nextLib;
    track *prevLib;
    track *next;
    track *prev;

    track(){};

    track(std::string in_title, std::string in_cd, std::string in_band)
	{
		title = in_title;
		cd = in_cd;
		band = in_band;
		next = NULL;
		prev = NULL;
        nextLib = NULL;
        prevLib = NULL;
	}

};


class Playlist
{
    public:
        Playlist();
        virtual ~Playlist();
        void createLib();
        void addTrack();
        void addCD();
        void removeTrack();
        void removeCD();
        void printList();
        void printLib();
        void trackToFront(std::string title);
        void trackToEnd (std::string title);
        void CDtoFront (std::string cd);
        void CDtoEnd (std::string cd);
        void deleteList();
        track *searchTrack(std::string title);
        track *searchCd(std::string cd);

        //void addTrackPub();
        //void addCDPub();
        //void removeTrackPub();
        //void removeCDPub();

    protected:

    private:

        track *first;
        track *last;
        int numTracks;
};

#endif // PLAYLIST_H
