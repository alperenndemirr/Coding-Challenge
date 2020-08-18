# Coding Challenge - Implemantation of Graph

>This code implements a directed weighted graph data structure by considering object-oriented programming using the adjacency list method. It is implemented Dijkstra's algorithm of the shortest path algorithms, also implemented to check if is a graph directed acyclic graph or not. This implementation has been tested on the google unit test framework and passed by all cases.

### Installation for Linux
#### Requirements
* [Google Test](https://github.com/google/googletest)
* [Linux](https://www.linux.org/)
* [g++](https://gcc.gnu.org/)

>This code run with g++ 4:9.3.0-1ubuntu2 and ubuntu 20.04.

Install the test dependencies.

```sh
$ sudo apt-get install libgtest-dev
$ sudo apt-get update
$ sudo apt-get upgrade
```

For build code...

```sh
$ cd path/of/file/Linux/CodingChallenge
$ g++ vertex.cpp graph.cpp main.cpp -o CodingChallenge
$ ./CodingChallenge
```

For build test code...

```sh
$ cd path/of/file/Linux/CodingChallengeTest
$ g++ pch.cpp test.cpp -o CodingChallengeTest -lgtest -lpthread
$ ./CodingChallengeTest
```

### Installation for Windows
#### Requirements
* [Visual Studio 2019](https://visualstudio.microsoft.com/)
* [Windows](https://www.microsoft.com/en-us/windows)
> This code run with Visiual Studio 2019 and Windows 10 (2004).

For build code...

```sh
 Go to the Windows/CodingChallenge directory.
 Run Coding Challenge.sln
 Run with Debug x86
```

For build test code...

```sh
 Go to the Windows/CodingChallenge directory.
 Run Coding Challenge.sln
 Solution Explorer > Right-click the Solution > Properties > Change Single Startup Project to CodingChallengeTest
 Run with Debug x86 
```
