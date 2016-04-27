# Robinson_CSCI2270_FinalProject

<b>Project: Modified Spotify Playlist</b>

<b>Project Summary</b>

This program creates a mock playlist of songs. The program enables the user to view all the songs in a music library and create, modify and view a playlist. The "music library" is generated from a list of songs in a text file. Each song in the list has a band name, CD name and a song title. (For example, one item in the list looks like this: Grateful Dead,American Beauty,Truckin'). Each item in the list is contained in a struct called a "Track" and these structs comprise the music library. The structs are connected to one another via a hybrid of linked lists and Binary Search Trees (BSTs). Each CD corresponds to one BST. The root of a CD BST links to the root of another CD BST by the same artists. The first struct created for each artist links to the first struct created for another artist. The playlist is stored in a deque (similar to a queue but you can remove objects from the middle, top or bottom.) Each item in the deque is a pointer to a Track struct. 

<b>How to Run</b>

To run the file you will need to compile and run main.cpp, Playlist.h and Playlist.cpp. MusicLibrary.txt must be in the same directory as main.cpp in order for the program to run properly. 

Once you have the program running you will be given the choice of 6 options:
<ol>
<li> View library
<li> Search library
<li> Add music to playlist
<li> Remove music from playlist
<li> View playlist
<li> Quit
</ol>


<ol>
<li><b>View Library</b>

Caution there are 50+ songs in the library so be ready to scroll.  

<li>Search
If you choose to search the library you will be prompted for song title or you can enter "cd" to enter a CD title or "b" to enter a band name. All strings are case sensitive are must match the names exactly as they are written in the text file (see below). You can add as many songs as you want without returning to the main menu just hit enter after each song. 

To quit out of entering songs, enter "q".  

If you enter "cd" or "b" you will be prompted for a cd title or band name.  To quit our of this enter "q"

Easy to type songs (these must be entered individually): 1999, Sunrise, Girls, Free, Unite, Coma
Easy to type CD: 1999
Easy to type band: Prince

If you search on a song, band or CD and it is found, you will have an option to add it to the playlist. Just enter "y" when prompted.

<li>Add to playlist
Same as above for search

<li>Remove from playlist
Same as above for search

<li>View playlist
Depending on how many songs you have in the playlist, be ready to scroll

<b>Dependencies</b>

<i>You will need access to STLs. The includes for these are written into the code so you should not have to do anything.</i>
<i>Also, I am old. If you are unfamiliar with these bands you should ask a parent or older relative about them.</i>

<b>System Requirements</b>
c++11

<b>Group Members</b>
None

<b>Contributors</b>
None, but all are welcome!
