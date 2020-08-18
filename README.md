# Coding Challenge - Implemantation of Graph

>This code implements a directed weighted graph data structure by considering object-oriented programming using the adjacency list method. It is implemented Dijkstra's algorithm of the shortest path algorithms, also implemented to check if is a graph directed acyclic graph or not. This implementation has been tested on the google unit test framework and passed by all cases.

### Installation for Linux
#### Requirements
* [GTest](https://github.com/google/googletest)
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
$ cd <Path of Coding Challenge Folder>
$ g++ vertex.cpp graph.cpp main.cpp -o CodingChallenge
$ ./CodingChallange
```

For build test code...

```sh
$ cd <Path of Coding Challenge Test Folder>
$ g++ pch.cpp test.cpp -o CodingChallangeTest -lgtest -lpthread
$ ./CodingChallengeTest
```

### Installation for Windows
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

