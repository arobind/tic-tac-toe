/*I coded this game in the 3rd year of my undergraduate course.*/
//TIC TAC TOE
#include <stdio.h>


char space[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int ch = 0;

void place(char c, int co, int ro);
int check(char c, int co, int ro);
void show();

main()
{
	int col, row, k = 0, val;
	printf("*****************\n");
	printf("***TIC TAC TOE***\n");
	printf("*****************\n");
	printf("\n\n##Player 1 enters x while Player 2 enters o##\n\n");
			
	while(1){
		printf("PLAYER 1:Enter the position to place your x(column and row position):\n");
		scanf("%d%d",&col,&row);
		place('x', col, row);
		show();
		val = check('x', col,row);
		if(val == -1)
		   break;
		printf("PLAYER 2:Enter the position to place your o(column and row position):\n");
		scanf("%d%d",&col,&row);
		place('o', col, row);
		show();
	    val = check('o', col, row);
		if(val == -1)
		   break;
	}
}
void show()
{
	int i,j;
	printf("\n\n");
	
	for(i = 0; i<3 ;i++)
	{
		for(j = 0;j<3;j++)
		{
			if(j== 1)
			printf("| %c |", space[i][j]);
			
			else
			printf(" %c ", space[i][j]);
		}
		if( i == 0 || i == 1)
		{
			
			printf("\n-----------\n");
		}		
	}
	printf("\n\n");
}

void place(char c, int co, int ro)
{
	int row, col;
	if(space[co-1][ro-1] == 'x'||space[co-1][ro-1] == 'o')
	{
		printf("The cell is already filled.\n");
		printf("Please enter your location again:\n");
		scanf("%d%d", &col,&row);
		place(c,col,row);
		
	}
	else if( co > 3||ro > 3)
	{
		printf("The given location is not present.\n");
		printf("Please enter your location again:\n");
		scanf("%d%d", &col,&row);
		place(c,col,row);
	}
	else
	{
		space[co-1][ro-1] = c;
		ch = ch + 1;
	}
}

int check(char c, int co, int ro)
{
	int i, j;
	for(i = 0; i<3; i++)
	{
		if(space[0][i] == 'x' && space[1][i] == 'x' && space[2][i] == 'x')
		{
			printf("Player 1 Wins\n");
			 
			return -1;
		}
		else if(space[0][i] == 'o' && space[1][i] == 'o' && space[2][i] == 'o')
		{
			printf("Player 2 Wins\n");
			 
			return -1;
		}
		else if(space[i][0] == 'o' && space[i][1] == 'o' && space[i][2] == 'o')
		{
			printf("Player 2 Wins\n");
			 
			return -1;
		}
		else if(space[i][0] == 'x' && space[i][1] == 'x' && space[i][2] == 'x')
		{
			printf("Player 1 Wins\n");
			 
			return -1;
		}
		
	}
	if(space[0][0] == 'x' && space[1][1] == 'x' && space[2][2] == 'x')
		{
			printf("Player 1 Wins\n");
			 
			return -1;
		}
	else if(space[0][2] == 'x' && space[1][1] == 'x' && space[2][0] == 'x')
		{
			printf("Player 1 Wins\n");
			 
			return -1;
		}
	else if(space[0][0] == 'o' && space[1][1] == 'o' && space[2][2] == 'o')
		{
			printf("Player 2 Wins\n");
			 
			return -1;
		}
	else if(space[0][2] == 'o' && space[1][1] == 'o' && space[2][1] == 'o')
		{
			printf("Player 2 Wins\n");
			 
			return -1;
		}
	if(ch == 9){
		printf("It's a draw.\n");
		 
		return -1;
	}
}