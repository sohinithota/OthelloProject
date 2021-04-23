To run game:
>>cmake .
>>make 
>>./bin/othello_demo

To run GTests:
>> cmake .
>> make
>> ./bin/othello_tests

The code compiles using cmake. Please reach out to me if it does not or if there are any other issues!

Concepts utilized in this project:
 - intro to C items: strings, pointers, chars, ints
 - abstract data structure development
 - manipulating a 2d array with user input

 how to gdb:

gcc ./othello.c othello_demo.c -g -o ./othello.o
gdb ./othello.o
>> c (USUALLY. SOMETIMES U DONT NEED)
>> run

>>start = start from beginning
