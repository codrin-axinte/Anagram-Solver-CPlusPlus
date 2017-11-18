# Anagram Solver CPlusPlus
> Design a system that will allow the player to enter up to 3 random letters. The system will return the beste, largest, valid English word that can be made up of the 3 letters(blanks/spaces are not allowed). For example: TCA should return CAT, OZR should return OR, ZZA should return A.
> **Extension: Expand the project so that it supports 4 letter anagrams(optional: up to max of 6)**

![Screenshot](https://github.com/codrin-axinte/Anagram-Solver-CPlusPlus/blob/master/Flowchart.png)

It searches for the best valid english word from a given file, matching criterias explained below. It will also provide some other suggestions if found.

## Installation

Windows:

```
> Open in visual studio and compile it.
> Run the executable
```
### Algorithm
* Get the database file path
* Get the angram input from the user
* Validate the input:
	- to have only letters
	- to not have any blank/empty space
	- to have a maximum and minimum length
* We read each line of the database file from a the given path
* At this point we parse the line:
	- Check if the given word length is less or equals the anagram length
	- Check if the given word contains one or more of the anagram characters
	- Add the valid line to the list of solutions
	- Return the all valid solutions as a list
* Check if there are any solutions
* Before we finish we do another step to sort the valid solutions by length and letter order
* Output the best solution
* Output other solutions as suggestions, if exists

## Solve Flowchart
![Anagram Solve Flowchart](https://github.com/codrin-axinte/Anagram-Solver/blob/master/Solve.png)

## Usage example

The program allows the player to specify a file to read, if left blank, a default database will be used. On the next step the user will be asked to input the anagram until it matches the selected algorithm rules. Finally a solution may be displayed, if was found. In addition if there are other suggestions, those will be displayed too.



## Possible Features
    * Having multiple algorithms
    * Better console menu, choose between algos
    * Command line argument execution
    * User can specify database

## Release History
* 0.1.1
    * Improved the algorithm    
* 0.1.0
    * The first proper release
    * Solve the anagram    
* 0.0.1
    * Work in progress
    * Parse the csv file

## Meta

Codrin Axinte – [@LinkedIn](https://www.linkedin.com/in/codrin-axinte-93776814b/) – xntcodrin@yahoo.com – loopbytes@yahoo.com

Distributed under the MIT license. See ``LICENSE`` for more information.

[https://github.com/codrin-axinte](https://github.com/codrin-axinte)

## Contributing

1. Fork it (<https://github.com/codrin-axinte/Anagram-Solver-CPlusPlus/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request
