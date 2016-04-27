#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <fstream>
#include <deque>


//The library of music is stored in structs. Each struct represents a song and contains
//the song title, the CD name the song is on, and the band name of the band that created the song
//Each song is stored alphabetically in a CD binary search tree.
//The CDs trees are each a node in a linked list of bands CDs
//Each Band is a node in a linked list of bands
struct Track{
    std::string title;
    std::string cd;
    std::string band;

    Track *parent;      //struct parent in "CD song BST
    Track *rChild;      //struct right child in "CD song BST
    Track *lChild;      //struct left child in "CD song BST
    Track *nextBand;    //links to next struct in band linked list. Only the root of the first CD tree read into the library contains a pointer to another band.
    Track *nextCD;      //links to next struct in a CD linked list. Only the root of the CD tree points to the next CD tree.


    Track(){};

    Track(std::string in_band, std::string in_cd, std::string in_title)
	{
		title = in_title;
		cd = in_cd;
		band = in_band;
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

        void printLib();    //prints library in table format
        void printCDTree(Track *song);  //called by printLib() to print all songs on a CD
        void searchLib();       //search library function.
        Track *searchLibByTrack(std::string in_song); //search library by song title (called by searchLib())
        Track *searchLibByCD(std::string in_cd);    //search library by CD (called by searchLib())
        Track *searchLibByBand(std::string in_band); //searchelibrary by band (called by searchLib())
        void addToPL();         //add item(s) to playlist
        void addToDeque(Track *song); //add track to playlist (called by addtoPL())
        void addCDToPL(Track *song);    //add all songs no a CD to playlist (called by addToPL())
        void removeFromPL();    //remove item from playlist
        void removeTrackFromPL(std::string in_song);    //remove individual track from playlist (called by removeFromPL())
        void removeCDFromPL(std::string in_cd);         //remove all songs from a CD from playlist (called by removeFromPL())
        void removeBandFromPL(std::string in_band);     //remove all band's songs from playlist (called by removeFromPL())
        void printPL();     //prints playlist
        void deletePL();    //deletes enter playlist


    protected:

    private:

        Track *headLib; //root of first CD tree
        std::deque<Track*> dq;  //deque containing the plaulist
        bool readInTracks(); //function that reads each line from the music library text file
        void addTrackToLib(std::string in_band, std::string in_cd, std::string in_title); //add individual track to music library
        void addTrackToTree(Track *song, Track *tmp); //adds track to album tree

        int numTracks;  //used for testing. Contains number of elements in the playlist


};

#endif // PLAYLIST_H
