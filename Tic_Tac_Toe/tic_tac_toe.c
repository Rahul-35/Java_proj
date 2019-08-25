#include<stdio.h>
#include<stdlib.h>
char matrix[3][3];
char check();
void init_matrix();
void get_player_move();
void get_computer_move();
void disp_matrix();
int main()
{
 	char done;
       printf("This is the game of Tic tac toe.\n");
	printf("You will be playing against the computer.\n");
 	done=' ';
	init_matrix();
	do{
		disp_matrix();
		get_player_move();
		done=check();
		if(done!=' ') break;
		get_computer_move();
		done=check();
	}while(done==' ');
	if(done=='X')printf("You won!\n");
	else printf("I won!!!\n");
	disp_matrix();
	return(0);
}
void init_matrix()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			matrix[i][j]=' ';
	}	
}
void get_player_move()
{
	int x,y;
	printf("Enter X,Y coordinates for your move: ");
	scanf("%d%*c%d",&x,&y);
	x--;
	y--;
	if(matrix[x][y]!=' '){
		printf("Invalid move,try again.\n");
		get_player_move();
	}
	else
		matrix[x][y]='X';
}
void get_computer_move()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++){
			//if(matrix[i][j]==' ')
			//	break;
		//}
		//if(matrix[i][j]==' ')
		//	break;
	
	if(i*j==9){
		printf("draw\n");
		exit(0);
	}
	else
		matrix[i][j]=='O';
}
}}
void disp_matrix()
{
	int t;
	for(t=0;t<3;t++){
		printf(" %c | %c | %c ",matrix[t][0],matrix[t][1],matrix[t][2]);
		if(t!=2)
			printf("\n---|---|---\n");
	}
	printf("\n");

}
char check()
{
	int i;
	for(i=0;i<3;i++)
		if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2])
			return matrix[i][0];
	for(i=0;i<3;i++)
                if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
                        return matrix[0][i];

        if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
                        return matrix[0][0];

        if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
                        return matrix[0][2];

}
