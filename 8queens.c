/*
 ============================================================================
 Name        : queens
 Author      : Nathan Christian
 Version     : 4.0
 Copyright   : Not copyrighted
 Description : 8 Queen problem
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 64 //defines the size of a standard chess board

int isEmpty(int *s, int *top2); //check for empty stack
int isFull(int *s, int *top2); //check for full stack
int pop(int *s, int *top2);    //pop a queen off the stack
int isSafe(int *s, int j2);    //check to determine that a position is safe
void push(int *s, int *top2, int location); // //push a queen onto the stack
int getRow(int *s, int top2);  //convert the numeric position (0-63) into a row

int main(void) {

	int top, queens, n, j, queenCount, max2; //top used in stack, n/j used in loops, queenCount, used to decrement queens, max2 used to convert double MAX to integer
	max2=sqrt(MAX); //used to determine number of rows/columns (square root of total spaces on board)
	top=-1; //begin with an empty stack

	setbuf(stdout, NULL);
	printf("This program finds safe locations for 1-%d queens on a symmetrical board.\n", max2);
	printf("The standard chess board is 8X8. Queens are placed such that they cannot attack each other.\n");
	printf("Note: It is impossible to place more than %d queens safely.", max2);
	printf("Please enter the number of queens to be used: ");
	scanf("%d", &queens); //explanation the program and read the number of queens*/

	while (queens>max2 || queens<1){
		printf("Error: Please enter a number between 1 and %d.\n", max2);
		scanf("%d", &queens); //limit number of queens to number of rows & columns
	}

	queenCount=queens; //used to decrement total queens in order to allow for a quick exit once all queens have been placed (see line 57)

	int stack[queens]; //create a stack with enough room to hold all queens

	for (n=0;n<queens;n++)
		stack[n]=-1; //initialize all locations to -1

	for (n=0; n<MAX; n++){ //look at every space
		if (isSafe(stack, n)){
			push(stack, &top, n); //if that spot is safe push it onto the stack
			queens--; //decrement number of queens waiting to be placed
			if (queens==0){
				printf("Final placement of the queens is\nrow\tcolumn\n");
				for(n=0;n<queenCount;n++)
					printf("%d\t%d\n", getRow(stack, n)+1, stack[n]%8+1);
				exit(1); //Exit program when all queens are placed to reduce compilation time
			}

			printf("Placing a queen in (row/column) (%d %d)\n", getRow(stack, top)+1, (stack[top]%max2)+1);
			printf("Current queen placement is\nrow\tcolumn\n"); //print placement of queen at each step

			for (j=0; j<queenCount; j++)
				if (stack[j]==-1)
						printf("-1\t-1\n"); //if a queen has not been placed in this location print -1 as its row and column
				else
					printf("%d\t%d\n", getRow(stack, j)+1, (stack[top]%max2)+1); //else print teh location of the queen
		}

		if (n==MAX-1 && queens>0) //if you reach the end of the board and not all queens are placed
		{
			printf("\nReached end of board with %d queens left to place. Re-working...\n", queens);
			if(n==MAX-1){
				n=stack[top-1];
				printf("Removing queen placed at (%d, %d) and re-working.\n", getRow(stack, top)+1, (stack[top]%max2)+1);
				stack[top]=-1;
				pop(stack, &top);
				stack[top]=-1;
				pop(stack, &top);
				queens+=2;
			} //if you are at the end of the board, pop the last two queens placed and move on

			else{
				n=stack[top];
				stack[top]=-1;
				pop(stack, &top);
				queens++;
			} //if not at the end of the board, pop only the last placed queen off and move to the next space
		}//end if

	}
	printf("Final placement of the queens is\nrow\tcolumn\n");
	for(n=0;n<queenCount;n++)
		printf("%d\t%d\n", getRow(stack, n)+1, (stack[top]%max2)+1); //when the program ends, print the final position

	return 0;
}// end main

int isEmpty(int *s, int *top2){
	if(*top2==-1)
		return 1;
	else
		return 0;
}//isEmpty

int isFull(int *s, int *top2){
	if(*top2==MAX-1)
		return 1;
	else
		return 0;
} // isFull

int pop(int *s, int *top2){
	if(!isEmpty(s, top2)){
		int location;
		location = s[*top2];
		*top2=*top2-1;
		return location;
	}//if isEmpty
	else{
		printf("Error: Stack read as empty.");
		return -1;
	}// full stack error
}//pop

int isSafe(int *queensLoc, int j2){
	int row, column, n, j, max2;
	max2=sqrt(MAX); //convert global variable MAX to integer and find square root (number of rows and columns)
	row=j2/max2+1; //this converts the location into a row for easy comparison
	column=j2%max2; //this converts the location into a column

	for (n=0; queensLoc[n]!=-1;n++){ //loops until all placed queens have been compared to the space passed from main
		if (j2<max2 && queensLoc[n]<max2)
			return 0; //if a queen is in row 1, row 1 is not safe
		if (j2%max2==0 && queensLoc[n]%max2==0)
			return 0; //if a queen is in column 1, column 1 is not safe
		if (queensLoc[n]/max2+1==row)
			return 0; // if a queen is on the same row, that row is unsafe
		if (queensLoc[n]%max2==column)
			return 0; //if a queen is on the same column, that column is unsafe

		for (j=queensLoc[n]+max2+1; (j)<=MAX; j+=max2+1){
			if (j==j2 && queensLoc[n]%max2 !=max2-1)
				return 0; //
		} //if diagonal to a placed queen, that space is not safe (note this equation does not work in the last column hence the column !=last column restriction

		for (j=queensLoc[n]-max2+1; (j)>=0; j-=max2+1){
			if (j==j2 && queensLoc[n]%max2 !=0)
				return 0; //
		} //if diagonal to a placed queen, that space is not safe (note this equation does not work in the first column hence the queen%8 !=0 restriction

		for (j=queensLoc[n]+max2-1; (j)<=MAX; j+=max2-1)
		{
			if (j==j2 && queensLoc[n]%max2 !=0)
				return 0; //
		} //if diagonal to a placed queen, that space is not safe (note this equation does not work in the last column hence the column !=0 restriction

		for (j=queensLoc[n]-sqrt(MAX)-1; (j)>=0; j-=max2-1)
		{
			if (j==j2 && queensLoc[n]%max2 !=max2-1)
				return 0; //
		} //if diagonal to a placed queen, that space is not safe (note this equation does not work in the first column hence the column!=last column restriction

	}
		return 1; //else return safe
}

void push(int *s, int *top2, int location){
	if(!isFull(s, top2)){
		*top2=*top2+1;
		s[*top2]=location;
	}//if not empty push onto stack
	else
		printf("Error: The stack is reading as full for unknown reasons");
}//end push

int getRow(int *s, int top2){
	if (s[top2]<sqrt(MAX))
		return s[top2]; //if a queen is in row 1, row 1 is not safe
	else
		return s[top2]/sqrt(MAX);
}
