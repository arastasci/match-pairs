# Introduction

This project is an implementation of a well known game where the player is expected to match pairs of cards in a given amount of tries. The program has a graphics user interface (GUI) that the player can interact with. The program is written in C++ with the Qt framework.

This documentation aims to provide a description of the program and its implementation details. It might be beneficial for the reader to be familiar with the following words in order to make full use of this documentation:

-   Event-driven programming: a programming paradigm in which the flow of the program is determined by events such as user actions. [1]
-   Qt: a widely used framework for creating GUIs.
-   Slot (Qt): the procedure that gets invoked by the event that's connected to it.
-   Signal (Qt): the specific behaviour that triggers slots that are connected to it.

# Program Interface

To start the program, the user must first compile the program. As it is a Qt application, the user can run `qmake` at the root of the source code to create a Makefile. Then, running `make` at the root creates an executable `match-pairs` which can be run with the command `./match-pairs` which starts the program.

# Program Execution (Gameplay)

As explained in the `Introduction` section, the program is a match pairs game. The cards contain words which are initially not known by the player and the player chooses to reveal pairs of cards in order to match them. The player must match them in a given amount of tries.

Source:

[1] https://en.wikipedia.org/wiki/Event-driven_programming
