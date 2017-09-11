# SHDocument

SHDocument is simple project in my school to know about networking.

Project provide client and server, server can save file from client and send file to client. Server can't handle multi connection from some client.
And project have some Handler useful for newbie lean C and C++.

It run on ubuntu, I use GCC version 5.4.0 to compile and valgrind to check memory leak, 
cmake version 3.5.1 to auto generate makefile. 

**How to run**<br>
First step is open terminal and cd in to SHDocument and run come code in terminal:<br>
_cmake ._<br>
_make_<br>
_./Alltest_ (to test some feature)<br>
_./ServerRun_ (to run server)<br>
_./ClientRun_ (to run client)<br>
_make check_leak_test_ (to check leak memory)<br>