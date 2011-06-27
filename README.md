Bot Trust
=========

This program solves the [Bot Trust challenge](http://code.google.com/codejam/contest/dashboard?c=975485#s=p0) in the 2011 qualification round of Google Code Jam.

Building
--------

Run the following at the project root ([CMake](http://www.cmake.org/) 2.6 or later is required):

    cmake CMakeLists.txt
    make

Executables are written to bin. bot\_trust is the main executable to run and bot\_trust\_tests is the unit tests executable.

Usage
-----

On the command line:

    bot_trust < input.txt

Where input.txt is the file downloaded from the challenge server.

