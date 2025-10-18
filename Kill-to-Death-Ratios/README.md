C++ K/D Ratio Tracker
A simple C++ console tool for tracking a video game player's kill-to-death (K/D) ratio.

It reads existing match data from text files, calculates the average K/D, allows you to add new match results, and saves the updated stats back to the files.

How It Works
Select a file (1, 2, or 3) to load.

The program reads input/killsX.txt and input/deathsX.txt and shows the current average.

Enter new kill/death scores. The average is recalculated each time.

When you quit ('s'), the program overwrites the files in input/ with the new, complete data.