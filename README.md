# Covid_19_Grocery_Shopping

Program to calculate the maximum number of people living in Manhattan that can go to the supermarket without ever encountering each other and therefore getting infected.

Description:
-> In this project I considered a city like Manhattans that is laid out on a uniform grid of streets and avenues 
-> People can circulate streets in both ways
-> Avenues are numbered from 1 to M and their direction is NORTH-SOUTH
-> Streets are numbered from 1 to N and their direction is EAST-WEST
-> Crossroads are defined by a pair of numbers. Example: (A,B) corresponds to the interception of avenue A and street B
-> There can be more than one supermarket in a crossroad

The input is given by:
-> A line with the number of avenues and streets (M and N)
-> A line with the number of supermarket and number of residents (S and C)
-> S lines, which one with the location of a supermarket, defined by the avenue and street number
-> C lines, which one with the address of which citizen, defined by the avenue and street number
 
 The output is the maximum number of citizens that can go to the supermarket without ever crossing eachother in any street, avenue or crossroad.
