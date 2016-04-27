# Robinson_CSCI2270_FinalProject
CSCI 2270 (S16) Final Project
Project: Modified Spotify playlist

Project Summary:

This program creates a mock playlist of songs from a set of CDs. The program enables the user to view all the songs in the library, add or delete songs, CD and/or all the CDs of a band to a playlist and/or view the playlist. A "music library" is generated from a text file containing a list of songs. Each song in the list has a band name, CD name and a song title. Each of these are separated by commas (for example, one item in the list looks like this:Grateful Dead,American Beauty,Truckin'). The program reads each item in the list into a struct called a "Track." These Tracks are linked together via two linked lists - a linked list of bands and a linked list of CDs -- and binary search trees (BST) of songs. Each BST represents a CD in the music library. The nodes of the BST are Track structs. 

Grateful Dead


in the program. The music library is a  Once the library has been read in, the user receives a text menu with the options to view library, search library, add music to playlist, remove music from playlist, view playlist or quit. The program runs until (it crashes) or the users chooses to quit. 

