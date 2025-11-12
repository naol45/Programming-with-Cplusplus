Player vs. Monster: A C++ Duel Simulator 🐲
Engage in a simple, turn-based duel against a monster in this command-line C++ application. Track your health, choose your attacks, and try to defeat the monster before it takes you down with its fireball!

This program demonstrates a basic game loop, input handling, and state management in C++.

Game Rules
Health: Both the Player and the Monster start with 10 HP.

Player Attacks: On your turn, you can choose from two attacks:

Monster Behavior: The monster follows a strict, alternating pattern:

    Block: On its first turn (and every odd-numbered turn), it blocks, negating all of your damage.

    Attack: On its second turn (and every even-numbered turn), it shoots a fireball, dealing 2 damage to you.

The duel ends when either combatant's health drops to 0 or less.