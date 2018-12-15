# Mad-Vet-Applied
This is a project from an Applied Algorithms class at my university.

This basic premise of this project is is to take in an amount of A, B, and C and produce the wanted amount of those three, and it is also used to find out how many levels deep the required solution is. 

Another goal of this assignment is to test our ability of performing a BFS(Breadth First Search).

For example:

1 2
0 1 0
1 1 1
1 1 0
1 0 1 1 3 0 0
2 1 0 0 2 0 0

The 1 at the very top stands for the current level of the input. The 2 to the right of it stands for the number of questions. The questions come after the three rows of 3 numbers. Those three rows stand for the three machines. The first machine(010) takes 1 A then produces 0 A's, 1 B, and 0 C's. The second machine(111) takes in 1 B and then produces 1 A, 1 B, and 1 C. The third and last machine(110) takes in 1 C and then produces 1 A, 1 B, and 0 C's. The two lines after that are the "questions." The first 1 in 1011300 identifies it as the first question. The 011 is the starting input, and the 300 is the desired output. Using the machines and the reverse of the machines, (as an example, the second machine would take in 1 A, 1 B, and 1 C and then produce 1 B.) one can find how many levels deep the solution is. If the solution is past 30 levels deep then it is considered a NO SOLUTION as per the guidelines of the assignment.   
