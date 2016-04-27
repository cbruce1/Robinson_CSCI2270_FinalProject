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

<b>View Library</b>

Caution there are 50+ songs in the library so be ready to scroll.  

<b>Search</b>

If you choose to search the library you will be prompted for song title or you can enter "cd" to enter a CD title or "b" to enter a band name. All strings are case sensitive are must match the names exactly as they are written in the text file (see below). You can add as many songs as you want without returning to the main menu just hit enter after each song.

To quit out of entering songs, enter "q".  

If you enter "cd" or "b" you will be prompted for a cd title or band name.  To quit our of this enter "q"

Easy to type songs (these must be entered individually): 1999, Sunrise, Girls, Free, Unite, Coma
Easy to type CD: 1999
Easy to type band: Prince

If you search on a song, band or CD and it is found, you will have an option to add it to the playlist. Just enter "y" when prompted.

<b>Add to playlist</b>

Same as above for search

<b>Remove from playlist</b>

Same as above for search

<b>View playlist</b>

Depending on how many songs you have in the playlist, be ready to scroll

<b>Dependencies</b>

You will need access to STLs. The includes for these are written into the code so you should not have to do anything.

<i>Btw... I am old. If you are unfamiliar with these bands ask a parent or older relative about them. (Some of them are really good!)</i>

<b>System Requirements</b>
c++11

<b>Group Members</b>
None

<b>Contributors</b>
None, but all are welcome!



<i><b>For reference: Music Library</b></i>

MUSIC LIBRARY FOR FINAL PROJECT

Prince,Purple Rain,Let's Go Crazy,

Prince,Purple Rain,Take Me With U,

Prince,Purple Rain,The Beautiful Ones,

Prince,Purple Rain,Computer Blue,

Prince,Purple Rain,Darling Nikki,

Prince,Purple Rain,When Doves Cry,

Prince,Purple Rain,I Would Die 4 U,

Prince,Purple Rain,Baby I'm A Star,

Prince,Purple Rain,Purple Rain,

Prince,1999,1999,

Prince,1999,Little Red Corvette,

Prince,1999,Delirious,

Prince,1999,Let's Pretend We're Married,

Prince,1999,D.M.S.R.,

Prince,1999,Automatic,

Prince,1999,Something In The Water,

Prince,1999,Free,

Prince,1999,Lady Can Driver,

Prince,1999,All The Critics Love U  In New York,

Prince,1999,International Lover,

Grateful Dead,American Beauty,Box Of Rain,

Grateful Dead,American Beauty,Friend Of The Devil,

Grateful Dead,American Beauty,Sugar Magnolia,

Grateful Dead,American Beauty,Operator,

Grateful Dead,American Beauty,Candyman,

Grateful Dead,American Beauty,Ripple,

Grateful Dead,American Beauty,Brokedown Palace,

Grateful Dead,American Beauty,Till The Morning Comes,

Grateful Dead,American Beauty,Attics Of My Life,

Grateful Dead,American Beauty,Truckin',

Grateful Dead,Terrapin Station,Estimated Prophet,

Grateful Dead,Terrapin Station,Dancin' In The Streets,

Grateful Dead,Terrapin Station,Passenger,

Grateful Dead,Terrapin Station,Samson and Delilah,

Grateful Dead,Terrapin Station,Sunrise,

Grateful Dead,In the Dark,Touch Of Grey,

Grateful Dead,In the Dark,Hell In A Bucket,

Grateful Dead,In the Dark,When Push Comes to Shove,

Grateful Dead,In the Dark,West L.A. Fadeaway,

Grateful Dead,In the Dark,Tons Of Steel,

Grateful Dead,In the Dark,Throwing Stones,

Grateful Dead,In the Dark,Black Muddy River,

Gwen Stefani,The Sweet Escape,Wind It Up,

Gwen Stefani,The Sweet Escape,The Sweet Escape,

Gwen Stefani,The Sweet Escape,Orange County Girl,

Gwen Stefani,The Sweet Escape,Early Winter,

Gwen Stefani,The Sweet Escape,Now That You Got It,

Gwen Stefani,The Sweet Escape,4 In The Morning,

Gwen Stefani,The Sweet Escape,Yummy,

Gwen Stefani,The Sweet Escape,Flourescent,

Gwen Stefani,The Sweet Escape,Breakin' Up,

Gwen Stefani,The Sweet Escape,Don't Get It Twisted,

Gwen Stefani,The Sweet Escape,U Started It,

Gwen Stefani,The Sweet Escape,Wonderful Life,

Gwen Stefani,Love Angel Music Baby,What You Waiting For?,

Gwen Stefani,Love Angel Music Baby,Rich Girl,

Gwen Stefani,Love Angel Music Baby,Hollaback Girl,

Gwen Stefani,Love Angel Music Baby,Cool,

Gwen Stefani,Love Angel Music Baby,Bubble Pop Electric,

Gwen Stefani,Love Angel Music Baby,Luxurious,

Gwen Stefani,Love Angel Music Baby,Harajuku Girls,

Gwen Stefani,Love Angel Music Baby,Crash,

Gwen Stefani,Love Angel Music Baby,The Real Thing,

Gwen Stefani,Love Angel Music Baby,Serious,

Gwen Stefani,Love Angel Music Baby,Danger Zone,

Gwen Stefani,Love Angel Music Baby,Long Way To Go,

Beastie Boys,Hello Nasty,Super Disco Breakin',

Beastie Boys,Hello Nasty,The Move,

Beastie Boys,Hello Nasty,Remote Control,

Beastie Boys,Hello Nasty,Song For The Man,

Beastie Boys,Hello Nasty,Just A Test,

Beastie Boys,Hello Nasty,Body Movin',

Beastie Boys,Hello Nasty,Intergalactic, 

Beastie Boys,Hello Nasty,Sneakin' Out The Hospital,

Beastie Boys,Hello Nasty,Putting Shame In Your Game,

Beastie Boys,Hello Nasty,Flowin' Prose,

Beastie Boys,Hello Nasty,And Me,

Beastie Boys,Hello Nasty,Three MC's and One DJ,

Beastie Boys,Hello Nasty,The Grasshopper Unit (Keep Movin'),

Beastie Boys,Hello Nasty,Song For Junior,

Beastie Boys,Hello Nasty,I Don't Know,

Beastie Boys,Hello Nasty,The Negotiation Limerick File,

Beastie Boys,Hello Nasty,Electrify,

Beastie Boys,Hello Nasty,Picture This,

Beastie Boys,Hello Nasty,Unite,

Beastie Boys,Hello Nasty,Dedication,

Beastie Boys,Hello Nasty,Dr. Lee PhD,

Beastie Boys,Hello Nasty,Instant Death,

Beastie Boys,Licensed To Ill,Rhymin & Stealin, 

Beastie Boys,Licensed To Ill,The New Style,

Beastie Boys,Licensed To Ill,She's Crafty,

Beastie Boys,Licensed To Ill,Posse In Effect,

Beastie Boys,Licensed To Ill,Slow Ride,

Beastie Boys,Licensed To Ill,Girls,

Beastie Boys,Licensed To Ill,Fight For You Right,

Beastie Boys,Licensed To Ill,No Sleep Till Brooklyn,

Beastie Boys,Licensed To Ill,Paul Revere,

Beastie Boys,Licensed To Ill,Hold It Now Hit It,

Beastie Boys,Licensed To Ill,Brass Monkey,

Beastie Boys,Licensed To Ill,Slow and Low,

Beastie Boys,Licensed To Ill,Time To Get Ill,

Beastie Boys,Ill Communication,Sure Shot,

Beastie Boys,Ill Communication,Tough Guy, 

Beastie Boys,Ill Communication,B-Boys Makin' With the Freak Freak,

Beastie Boys,Ill Communication,Bobo On The Corner,

Beastie Boys,Ill Communication,Root Down,

Beastie Boys,Ill Communication,Sabotage,

Beastie Boys,Ill Communication,Get It Together,

Beastie Boys,Ill Communication,Sabrosa,

Beastie Boys,Ill Communication,The Update,

Beastie Boys,Ill Communication,Futterman's Rule,

Beastie Boys,Ill Communication,Alright Hear This,

Beastie Boys,Ill Communication,Eugene's Lament,

Beastie Boys,Ill Communication,Flute Loo,p 

Beastie Boys,Ill Communication,Do It,

Beastie Boys,Ill Communication,Ricky's Theme,

Beastie Boys,Ill Communication,Heart Attack Man,

Beastie Boys,Ill Communication,The Scoop,

Beastie Boys,Ill Communication,Shambala,

Beastie Boys,Ill Communication,Bodhisattva Vow,

Beastie Boys,Ill Communication,Transitions,

Guns N'Roses,Appetite For Destruction,Welcome To The Jungle,

Guns N'Roses,Appetite For Destruction,It's So Easy,

Guns N'Roses,Appetite For Destruction,Nightrain,

Guns N'Roses,Appetite For Destruction,Out Ta Get Me,

Guns N'Roses,Appetite For Destruction,Mr. Brownstone,

Guns N'Roses,Appetite For Destruction,Paradise City,

Guns N'Roses,Appetite For Destruction,My Michelle,

Guns N'Roses,Appetite For Destruction,Think About You,

Guns N'Roses,Appetite For Destruction,Sweet Child O' Mine,

Guns N'Roses,Appetite For Destruction,You're Crazy,

Guns N'Roses,Appetite For Destruction,Anything Goes,

Guns N'Roses,Appetite For Destruction,Rocket Queen,

Guns N'Roses,Use Your Illusion I,Right Next Door To Hell,

Guns N'Roses,Use Your Illusion I,Dust N' Bones,

Guns N'Roses,Use Your Illusion I,Live And Let Die,

Guns N'Roses,Use Your Illusion I,Don't Cry,

Guns N'Roses,Use Your Illusion I,Perfect Crime,

Guns N'Roses,Use Your Illusion I,You Ain't The First,

Guns N'Roses,Use Your Illusion I,Bad Obsession,

Guns N'Roses,Use Your Illusion I,Back Off Bitch,

Guns N'Roses,Use Your Illusion I,Double Talkin' Jive,

Guns N'Roses,Use Your Illusion I,November Rain,

Guns N'Roses,Use Your Illusion I,The Garden,

Guns N'Roses,Use Your Illusion I,Garden Of Eden,

Guns N'Roses,Use Your Illusion I,Don't Damn Me,

Guns N'Roses,Use Your Illusion I,Bad Apples,

Guns N'Roses,Use Your Illusion I,Dead Horse,

Guns N'Roses,Use Your Illusion I,Coma,

Guns N'Roses,Use Your Illusion II,Civil War,

Guns N'Roses,Use Your Illusion II,14 Years,

Guns N'Roses,Use Your Illusion II,Yesterdays,

Guns N'Roses,Use Your Illusion II,Knockin' On Heaven's Door,

Guns N'Roses,Use Your Illusion II,Get In The Ring,

Guns N'Roses,Use Your Illusion II,Shotgun Blues,

Guns N'Roses,Use Your Illusion II,Breakdown,

Guns N'Roses,Use Your Illusion II,Pretty Tied Up,

Guns N'Roses,Use Your Illusion II,Locomotive,

Guns N'Roses,Use Your Illusion II,So Fine,

Guns N'Roses,Use Your Illusion II,Estranged,

Guns N'Roses,Use Your Illusion II,You Could Be Mine,

Guns N'Roses,Use Your Illusion II,Don't Cry,

Guns N'Roses,Use Your Illusion II,My World,
