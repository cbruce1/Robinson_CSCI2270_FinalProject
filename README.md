# Robinson_CSCI2270_FinalProject

Project: Modified Spotify playlist

<b>Project Summary:</b>

This program creates a mock playlist of songs. The program enables the user to view all the songs in a music library and create, modify and view a playlist. The "music library" is generated from a list of songs in a text file. Each song in the list has a band name, CD name and a song title. (For example, one item in the list looks like this: Grateful Dead,American Beauty,Truckin'). Each item in the list is contained in a struct called a "Track" and these structs comprise the music library. The structs are connected to one another via a hybrid of linked lists and Binary Search Trees (BSTs). Each CD corresponds to one BST. The root of a CD BST links to the root of another CD BST by the same artists. The first struct created for each artist links to the first struct created for another artist. The playlist is stored in a deque (similar to a queue but you can remove objects from the middle, top or bottom.) Each item in the deque is a pointer to a Track struct. 

Grateful Dead


in the program. The music library is a  Once the library has been read in, the user receives a text menu with the options to view library, search library, add music to playlist, remove music from playlist, view playlist or quit. The program runs until (it crashes) or the users chooses to quit. 

