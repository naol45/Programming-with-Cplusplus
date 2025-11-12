Character Break Time Calculator 🏰
A C++ command-line utility for processing character break schedules. This tool reads data from an input file, calculates each character's return time while handling data errors, and writes a clean summary to an output file.

It's designed to easily process logs of character breaks and produce a simple report.

How It Works
The program first prompts you to enter the name of an input file.

It reads the input file line-by-line, expecting four columns of data.

It validates each line to ensure all time values are valid, non-negative numbers. Any invalid lines are reported in the terminal and skipped.

For all valid entries, it calculates the time until the character is scheduled to return.

The final results are saved to a new file named howLongTilCharacter.txt.

Input File Format
The input file must be a text file with a header, where each subsequent line contains four columns separated by spaces:

    character breaktime downtime delaytime

    character: The character's name (string).

    breaktime: The total scheduled break duration in minutes (integer).

    downtime: The time already spent on break in minutes (integer).

    delaytime: Any additional delay in minutes (integer).