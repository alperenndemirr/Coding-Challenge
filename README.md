# Coding Challenge - Implemantation of Graph

### Installation for Linux
#### Requirements
* [GTest](https://github.com/google/googletest)
* [Linux](https://www.linux.org/)
* [g++](https://gcc.gnu.org/)

This code requires g++ 4:9.3.0-1ubuntu2 and ubuntu 20.04 to run.

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
> This code requires Visiual Studio 2019 and Windows 10 v2004 to run.
