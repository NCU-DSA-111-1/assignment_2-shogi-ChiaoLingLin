#include "../inc/define.h"


int xi = 0;
int yi = 0;//要移動的棋子
int xj = 0;
int yj = 0;//移動的目標位置
char space[4] = {"口"};

shogi Space = {"s",0,"口"};
shogi FootSoldier1 = { "a",1,"步" };
shogi Guima1 = { "b",1,"桂" };
shogi IncenseCar1 = { "c",1,"香" };
shogi SilverGeneral1 = { "d",1,"銀" };
shogi Tokin1 = { "e",1,"金" };
shogi FlyCar1 = { "f",1,"車" };
shogi CornerRow1 = { "g",1,"角" };
shogi King1 = { "h",1,"王"};

shogi FootSoldier2 = { "a",2,"步" };
shogi Guima2 = { "b",2,"桂" };
shogi IncenseCar2 = { "c",2,"香" };
shogi SilverGeneral2 = { "d",2,"銀" };
shogi Tokin2 = { "e",2,"金" };
shogi FlyCar2 = { "f",2,"車" };
shogi CornerRow2 = { "g",2,"角" };
shogi King2 = { "h",2,"王"};


void Xaxis()
{
	int row;
	for(row=0;row<=10;row++)
	{
		printf("%-2d",row);
	}
}
void swap(shogi* ShogiA, shogi* ShogiB)
{
	shogi temp;
	temp = *ShogiA;
	*ShogiA = *ShogiB;
	*ShogiB = temp;
}

//Origin_Board.c
//印出初始棋盤(Origin)
void OShogiBoard()
{
	for (int row = 0; row <= BoardRow; row++)
	{
		for (int colum = 0; colum < BoardColum; colum++)
		{
			ShogiBoard[row][colum] = Space;
		}
	}
	
	ShogiBoard[1][1] = IncenseCar1;
	ShogiBoard[9][1] = IncenseCar2;
	ShogiBoard[1][2] = Guima1;
	ShogiBoard[9][2] = Guima2;
	ShogiBoard[1][3] = SilverGeneral1;
	ShogiBoard[9][3] = SilverGeneral2;
	ShogiBoard[1][4] = Tokin1;
	ShogiBoard[9][4] = Tokin2;
	ShogiBoard[1][5] = King1;
	ShogiBoard[9][5] = King2;
	ShogiBoard[1][6] = Tokin1;
	ShogiBoard[9][6] = Tokin2;
	ShogiBoard[1][7] = SilverGeneral1;
	ShogiBoard[9][7] = SilverGeneral2;
	ShogiBoard[1][8] = Guima1;
	ShogiBoard[9][8] = Guima2;
	ShogiBoard[1][9] = IncenseCar1;
	ShogiBoard[9][9] = IncenseCar2;

	ShogiBoard[2][2] = FlyCar1;
	ShogiBoard[8][8] = FlyCar2;

	ShogiBoard[2][8] = CornerRow1;
	ShogiBoard[8][2] = CornerRow2;

	ShogiBoard[3][1] = ShogiBoard[3][2] = ShogiBoard[3][3] = 
	ShogiBoard[3][4] = ShogiBoard[3][5] = ShogiBoard[3][6] = 
	ShogiBoard[3][7] = ShogiBoard[3][8] = ShogiBoard[3][9] = FootSoldier1;
	
	ShogiBoard[7][1] = ShogiBoard[7][2] = ShogiBoard[7][3] = 
	ShogiBoard[7][4] = ShogiBoard[7][5] = ShogiBoard[7][6] = 
	ShogiBoard[7][7] = ShogiBoard[7][8] = ShogiBoard[7][9] = FootSoldier2;
	

	void Xaxis();
	printf("\n");
	for (int row = 0; row <= BoardRow; row++)
	{
		for (int colum = 0; colum < BoardColum; colum++)
		{
			
			if (*ShogiBoard[row][colum].Name == NO){
				if (row == 10 || row == 11)
					printf("\033[34m%s\033[0m", space);
				else if (row == 12 || row == 13)
					printf("\033[31m%s\033[0m", space);
				else printf("口");
			}
				
			else
			{
				if (ShogiBoard[row][colum].Player == 1)
					printf("\033[34m%s\033[0m", ShogiBoard[row][colum].represent);
				else 
					printf("\033[31m%s\033[0m", ShogiBoard[row][colum].represent);
			}
		}
		printf("%2d\n",row);
	}
	
}

//New_Board.c
//印出棋盤(Middle)
void MShogiBoard()
{
	printf("\n");
	void Xaxis();
	for (int row = 0; row <= BoardRow; row++)
	{
		for (int colum = 0; colum < BoardColum; colum++)
		{
			if (*ShogiBoard[row][colum].Name == NO)
			{
				if (row == 10 || row == 11)
					printf("\033[34m%s\033[0m", space);
					//printf("%d",colum);
				else if (row == 12 || row == 13)
					//printf("%d",colum);
					printf("\033[31m%s\033[0m", space);
				else printf("口");
			}

				
			else
			{
				if (ShogiBoard[row][colum].Player == 1)
					printf("\033[34m%s\033[0m", ShogiBoard[row][colum].represent);
				else 
					printf("\033[31m%s\033[0m", ShogiBoard[row][colum].represent);
			}
		}
		printf("%2d\n",row);
	}
	printf("\n");
	
}

//stack.c
//用單向鍊結串列stack來存棋盤

Node *stack = NULL;
void Push(void)	
{
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp -> yi = yi;
	tmp -> xi = xi;
	tmp -> yj = yj;
	tmp -> xj = xj;
	tmp -> next = stack;
	stack = tmp; 
} 
void Push2(int yii,int xii,int yjj,int xjj){
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp -> yi = yii;
	tmp -> xi = xii;
	tmp -> yj = yjj;
	tmp -> xj = xjj;
	tmp -> next = stack;
	stack = tmp;
}
int Pop(void)
//Node* Pop( Node *stack)
{

	Node *tmp;
	if (stack == NULL)
	{
		printf("stack is empty\n");
		//stack is empty;
		return 0;
	}
	tmp = stack;
	stack = stack -> next;
	yi = tmp -> yi;
	xi = tmp -> xi;
	yj = tmp -> yj;
	xj = tmp -> xj;	
	free(tmp);
	return 1;
}

//玩家一pop
int BackOne()
{
	char Back1;
	printf("若要退回上一步則輸入B,繼續則輸入C：");
	scanf(" %c",&Back1);
	if ( Back1 == 'B')
	{
		if (stack == NULL)
		{
			printf("stack is empty\n");
			//stack is empty;
			return 1;
		}
		//printf("Back1 == 'B'\n");
		if( stack != NULL )
		{
			Pop ();
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			Pop ();
			if ( yj == 12 || yj == 13 ) 
			{
				
				swap( &ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
				ShogiBoard[yj][xj].Player = 2;
				ShogiBoard[yi][xi].Player = 1;
				return 1;
			}	
			else Push();
			return 1;
		}
	
	}
	return 0;
}

//玩家二pop
int BackTwo()
{
	char Back2;
	printf("若要退回上一步則輸入B,繼續則輸入C：");
	scanf(" %c",&Back2);
	if ( Back2 == 'B')
	{
		if (stack == NULL)
		{
			printf("stack is empty\n");
			//stack is empty;
			return 1;
		}	

		if( stack != NULL )
		{

			Pop ();
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			Pop ();
			if ( yj == 10 || yj == 11 )
			{
				
				swap( &ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
				ShogiBoard[yj][xj].Player = 1;
				ShogiBoard[yi][xi].Player = 2;				
				return 1;
			}
			else Push();
			return 1;
		}
	}
	return 0;
}

//Player.c
//玩家1
int Player1()
{
	printf("玩家一\n");
	if (BackOne()==1)
	{
		Xaxis();
		MShogiBoard();
		return 1;
	}
	printf("玩家一請輸入要移動的棋子的位置(yi,xi):");
	scanf("%d,%d", &yi, &xi);
	printf("玩家一請輸入將 \033[44m %s \033[0m 移動至 (yj,xj):", ShogiBoard[yi][xi].represent);
	scanf("%d,%d", &yj, &xj);
	return 0;

}



//玩家2
int Player2()
{
	printf("玩家二\n");
	if (BackTwo()==1)
	{
		Xaxis();
		MShogiBoard();
		return 1;
		
	}
	
	printf("玩家二請輸入要移動的棋子的位置(yi,xi):");
	scanf("%d,%d", &yi, &xi);
	printf("玩家二請輸入將 \033[41m %s \033[0m 移動至 (yj,xj):", ShogiBoard[yi][xi].represent);
	scanf("%d,%d", &yj, &xj);
	return 0;

}
/////////////////////////////////////////////////////?
//使用yi=10、11的棋子
int P1_Relive(void)
{
	if ( yi == 10 || yi == 11 )
	{
		swap( &ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
		return 1;
	}
	return 0;	
}

//使用yi=12、13的棋子
int P2_Relive(void)
{
	if ( yi == 12 || yi == 13 )
	{
		//ShogiBoard[yi][xi].Player = 
		swap( &ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
		return 1;
	}
	return 0;	
}

/////////////////////////////////////////////////////?


//EatFuntion.c
//被吃掉的棋子(玩家一吃玩家二)
void EatFuntionPlayerOne( int* yinput, int* xinput)
{
	
	int yi = *yinput;
	int xi = *xinput;
	//Push();
	if ( *ShogiBoard[yi][xi].Name == 'a') //步兵
	{
		for (int AnemySoldier = 0; AnemySoldier <= 8; AnemySoldier++)
		{
			if ( *ShogiBoard[10][AnemySoldier].Name == NO)
			{
				swap( &ShogiBoard[10][AnemySoldier], &ShogiBoard[yi][xi]);
				ShogiBoard[10][AnemySoldier].Player = 1;
				//Push2(yi,xi,10,AnemySoldier);
				Push2(yj,xj,10,AnemySoldier);
				break;
			}//ShogiBoard[10][0]~ShogiBoard[10][8] 存放玩家一吃的步兵
		}
	}
	if ( *ShogiBoard[yi][xi].Name == 'b') //桂馬 
	{
		if ( *ShogiBoard[11][0].Name == '0')
		{	
			swap( &ShogiBoard[11][0], &ShogiBoard[yi][xi]);
			ShogiBoard[11][0].Player = 1;
			Push2(yj,xj,11,0);
		}
		else
		{
			swap( &ShogiBoard[11][6], &ShogiBoard[yi][xi]);
			ShogiBoard[11][6].Player = 1;
			Push2(yj,xj,11,6);
		}	
	}
	if ( *ShogiBoard[yi][xi].Name == 'c') //香車
	{
		if ( *ShogiBoard[10][9].Name == '0')
		{
			swap( &ShogiBoard[10][9], &ShogiBoard[yi][xi]);
			ShogiBoard[10][9].Player = 1;	
			Push2(yj,xj,10,9);
		}
		else
		{
			swap( &ShogiBoard[11][7], &ShogiBoard[yi][xi]);
			ShogiBoard[11][7].Player = 1;	
			Push2(yj,xj,11,7);
		}
	}
	if ( *ShogiBoard[yi][xi].Name == 'd') //銀
	{
		if ( *ShogiBoard[11][1].Name == '0')
		{
			swap( &ShogiBoard[11][1], &ShogiBoard[yi][xi]);
			ShogiBoard[11][1].Player = 1;
			Push2(yj,xj,11,1);
		}
		else
		{
			swap( &ShogiBoard[11][5], &ShogiBoard[yi][xi]);
			ShogiBoard[11][5].Player = 1;	
			Push2(yj,xj,11,5);
		}
	}

	if ( *ShogiBoard[yi][xi].Name == 'e') //金
	{
		if ( *ShogiBoard[11][2].Name == NO )
		{
			swap( &ShogiBoard[11][2], &ShogiBoard[yi][xi]);
			ShogiBoard[11][2].Player = 1;	
			Push2(yj,xj,11,2);	
		}
		else
		{
			swap( &ShogiBoard[11][4], &ShogiBoard[yi][xi]);
			ShogiBoard[11][4].Player = 1;	
			Push2(yj,xj,11,4);
		}
	}
	if (*ShogiBoard[yi][xi].Name == 'f' ) //飛車
	{
		swap( &ShogiBoard[11][9], &ShogiBoard[yi][xi]);
		ShogiBoard[11][9].Player = 1;
		Push2(yj,xj,11,9);///////////////////////////////////////////////////////////////////////
	}
	if ( *ShogiBoard[yi][xi].Name == 'g' ) //角行
	{
		swap( &ShogiBoard[11][8], &ShogiBoard[yi][xi]);
		ShogiBoard[11][8].Player = 1;
		Push2(yj,xj,11,8);
	}
	if ( *ShogiBoard[yi][xi].Name == 'h' ) //王
	{
		swap( &ShogiBoard[11][3], &ShogiBoard[yi][xi]);
		ShogiBoard[11][3].Player = 1;
		Push2(yj,xj,11,3);
	}
	*yinput = yi;
	*xinput = xi; 
}
//被吃掉的棋子(玩家二吃玩家一)
void EatFuntionPlayerTwo( int* yinput, int* xinput)
{
	int yi = *yinput;
	int xi = *xinput;
	//Push();
	if (*ShogiBoard[yi][xi].Name == 'a') //步兵
	{
		for (int AnemySoldier = 0; AnemySoldier <= 8; AnemySoldier++)
		{	
			
			if (*ShogiBoard[12][AnemySoldier].Name == NO)
			{
				swap(&ShogiBoard[12][AnemySoldier], &ShogiBoard[yi][xi]);
				ShogiBoard[12][AnemySoldier].Player = 2;
				Push2(yj,xj,12,AnemySoldier);
				break;
			}//ShogiBoard[12][0]~ShogiBoard[12][8] 存放玩家一吃的步兵
		}
	}
	if (*ShogiBoard[yi][xi].Name == 'b') //桂馬 
	{
		if (*ShogiBoard[13][0].Name == '0')
		{
			swap(&ShogiBoard[13][0], &ShogiBoard[yi][xi]);
			ShogiBoard[13][0].Player = 2;
			Push2(yj,xj,13,0);
		}
		else
		{
			swap(&ShogiBoard[13][6], &ShogiBoard[yi][xi]);
			ShogiBoard[13][6].Player = 2;
			Push2(yj,xj,13,6);
		}
	}
	if (*ShogiBoard[yi][xi].Name == 'c') //香車
	{
		if (*ShogiBoard[12][9].Name == '0')
		{
			swap(&ShogiBoard[12][9], &ShogiBoard[yi][xi]);
			ShogiBoard[12][9].Player = 2;
			Push2(yj,xj,12,9);
		}
		else
		{
			swap(&ShogiBoard[13][7], &ShogiBoard[yi][xi]);
			ShogiBoard[13][7].Player = 2;
			Push2(yj,xj,13,7);
		}
	}
	if (*ShogiBoard[yi][xi].Name == 'd') //銀
	{
		if (*ShogiBoard[13][1].Name == '0')
		{
			swap(&ShogiBoard[13][1], &ShogiBoard[yi][xi]);
			ShogiBoard[13][1].Player = 2;
			Push2(yj,xj,13,1);
		}
		else
		{
			swap(&ShogiBoard[13][5], &ShogiBoard[yi][xi]);
			ShogiBoard[13][5].Player = 2;
			Push2(yj,xj,13,5);
		}
	}

	if (*ShogiBoard[yi][xi].Name == 'e') //金
	{
		if (*ShogiBoard[13][2].Name == NO)
		{
			swap(&ShogiBoard[13][2], &ShogiBoard[yi][xi]);
			ShogiBoard[13][2].Player = 2;
			Push2(yj,xj,13,2);
		}	
		else
		{
			swap(&ShogiBoard[13][4], &ShogiBoard[yi][xi]);
			ShogiBoard[13][4].Player = 2;
			Push2(yj,xj,13,4);
		}
	}
	if (*ShogiBoard[yi][xi].Name == 'f') //飛車
	{
		swap(&ShogiBoard[13][9], &ShogiBoard[yi][xi]);
		ShogiBoard[13][9].Player = 2;
		Push2(yj,xj,13,9);
	}
	if (*ShogiBoard[yi][xi].Name == 'g') //角行
	{
		swap(&ShogiBoard[13][8], &ShogiBoard[yi][xi]);
		ShogiBoard[13][8].Player = 2;
		Push2(yj,xj,13,8);
	}	
	if (*ShogiBoard[yi][xi].Name == 'h') //王
	{	
		swap(&ShogiBoard[13][3], &ShogiBoard[yi][xi]);
		ShogiBoard[13][3].Player = 2;
		Push2(yj,xj,13,3);
	}
	*yinput = yi;
	*xinput = xi;	
}


//Rules.c
//玩家一規則判斷
int RulePlayer1( int yi, int xi, int yj, int xj)
{
	//Push( );
	//printf("Push yi %d\n",*stack->yi);
	//步兵
	if ( P1_Relive() == 1 )
	{
		return 0;
	}
	if (*ShogiBoard[yi][xi].Name == 'a')
	{
		if (yj == yi + 1)
		{
			swap( &ShogiBoard[yj][xj], &ShogiBoard[yi][xi] );
			if ( *ShogiBoard[yi][xi].Name != NO )
			{ //往前一步吃掉棋子  //只能往前走，所以是 y+1 //進階版:走到底一定要升變
				EatFuntionPlayerOne( &yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");

			return 1;
		}

	}

	// 桂馬
	if (*ShogiBoard[yi][xi].Name == 'b')
	{
		if ((yj == yi + 2 && xj == xi + 1) || (yj == yi + 2 && xj == xi - 1))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerOne(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}

	//香車
	if (*ShogiBoard[yi][xi].Name == 'c') 
	{
		if (xj == xi)
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerOne(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}

	}
	//銀
	if (*ShogiBoard[yi][xi].Name == 'd') 
	{
		if (((yj == yi + 1) && (xj == xi || xj == xi + 1 || xj == xi - 1)) || ((yj == yi - 1) && (xj == xi + 1 || xj == xi - 1)))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerOne( &yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}
	//金
	if (*ShogiBoard[yi][xi].Name == 'e')
	{
		if (((yj == yi + 1) && (xj == xi || xj == xi + 1 || xj == xi - 1)) || ((yj == yi - 1) && (xj == xi)) || ((yj == yi) && (xj == xi + 1 || xj == xi - 1)))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerOne(&yi, &xi);
			}
			Push( );
			return 0;
		}
			else
			{
				printf("You can't move to this place.\n");
				return 1;
			}
	}
	

    //飛車
	if (*ShogiBoard[yi][xi].Name == 'f') 
	{
		if (yj == yi || xj == xi)
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerOne( &yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}

	//角行
	if (*ShogiBoard[yi][xi].Name == 'g') 
	{
		for (int CornerRow = 1; CornerRow <= 8; CornerRow++)
		{
			if ((yj == yi + CornerRow && xj == xi + CornerRow) || (yj == yi - CornerRow && xj == xi - CornerRow) || (yj == yi + CornerRow && xj == xi - CornerRow) || (yj == yi - CornerRow && xj == xi + CornerRow))
			{
				swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
				if (*ShogiBoard[yi][xi].Name != '0')
				{
					printf("if (*ShogiBoard[yi][xi].Name != '0')");
					EatFuntionPlayerOne( &yi, &xi);
				}
				Push( );
				return 0;
				break;
			}
		}
		printf("You can't move to this place.\n");
		return 1;
	}

	//王
	//(((yj == yi + 1) && (xj == xi || xj == xi + 1 || xj == xi - 1)) || ((yj == yi - 1) && (xj == xi || xj == xi + 1 || xj == xi - 1) || ((yj == yi) && (xj == xi + 1 || xj == xi - 1))))
	if (*ShogiBoard[yi][xi].Name == 'h') 
	{
		if ((yj == yi + 1|| yj == yi - 1|| yj == yi) && (xj == xi || xj == xi + 1 || xj == xi - 1))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerOne( &yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}
}
//玩家二規則判斷
int RulePlayer2( int yi, int xi, int yj, int xj)
{	
	//Push( );
	
	
	if ( P2_Relive() == 1 )
	{
		return 0;
	}	
	//步兵
	if (*ShogiBoard[yi][xi].Name == 'a')
	{
		if (yj == yi - 1)
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);

			if (*ShogiBoard[yi][xi].Name != NO)
			{ //往前一步吃掉棋子  //只能往前走，所以是 y+1 //進階版:走到底一定要升變
				EatFuntionPlayerTwo(&yi, &xi);
				
			}
			Push();
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}

	}
	// 桂馬
	if (*ShogiBoard[yi][xi].Name == 'b') 
	{
		if ((yj == yi - 2 && xj == xi + 1) || (yj == yi - 2 && xj == xi - 1))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerTwo(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}
	//香車
	if (*ShogiBoard[yi][xi].Name == 'c') 
	{
		if (xj == xi)
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerTwo(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}

	//銀
	if (*ShogiBoard[yi][xi].Name == 'd') 
	{
		if (((yj == yi - 1) && (xj == xi || xj == xi + 1 || xj == xi - 1)) || ((yj == yi + 1) && (xj == xi + 1 || xj == xi - 1)))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerTwo(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}

	//金
	if (*ShogiBoard[yi][xi].Name == 'e') 
	{
		if (((yj == yi - 1) && (xj == xi || xj == xi + 1 || xj == xi - 1)) || ((yj == yi + 1) && (xj == xi)) || ((yj == yi) && (xj == xi + 1 || xj == xi - 1)))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerTwo(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}

	//飛車
	if (*ShogiBoard[yi][xi].Name == 'f') 
	{
		if (yj == yi || xj == xi)
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerTwo(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}
	//角行
	if (*ShogiBoard[yi][xi].Name == 'g') 
	{
		for (int CornerRow = 1; CornerRow <= 9; CornerRow++)
		{
			if ((yj == yi + CornerRow && xj == xi + CornerRow) || (yj == yi - CornerRow && xj == xi - CornerRow) || (yj == yi + CornerRow && xj == xi - CornerRow) || (yj == yi - CornerRow && xj == xi + CornerRow))
			{
				swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
				if (*ShogiBoard[yi][xi].Name != '0')
				{
					EatFuntionPlayerTwo(&yi, &xi);
				}
				Push( );
				return 0;
				break;
			}
		}
		printf("You can't move to this place.\n");
		return 1;
	}

	//王
	if (*ShogiBoard[yi][xi].Name == 'h') 
	{
		if ((yj == yi + 1|| yj == yi - 1|| yj == yi) && (xj == xi || xj == xi + 1 || xj == xi - 1))
		{
			swap(&ShogiBoard[yj][xj], &ShogiBoard[yi][xi]);
			
			if (*ShogiBoard[yi][xi].Name != '0')
			{
				EatFuntionPlayerTwo(&yi, &xi);
			}
			Push( );
			return 0;
		}
		else
		{
			printf("You can't move to this place.\n");
			return 1;
		}
	}	
}

//Winner.c
//遊戲結束的條件//
//王被吃掉 ，如果有輸贏產生，就回傳 0 ，沒有輸贏產生，回傳 1
int Winner()
{
	if (*ShogiBoard[11][3].Name == 'h')
	{
		printf("\nPlayer 1 win!!!\n");
		return 0;
	}

	if (*ShogiBoard[13][3].Name == 'h')
	{
		printf("\nPlayer 2 win!!!\n");
		return 0;
	}

	else
		return 1;
}

//main.c
int main() 
{
	Xaxis();
	OShogiBoard();
	int faus1=1;
	int faus2=1;

	while (1)
	{
	
		if (Winner() == 0)
			return 0;
		do
		{
			
			if(Player1() == 1){
				break;
			}
			faus1 = RulePlayer1( yi, xi, yj, xj);			
			Xaxis();
			MShogiBoard();
			
			
			
			if (Winner() == 0)
				break;
		}while (faus1==1);
	
		if (Winner() == 0)
		{
			return 0;
		}	
	
		do
		{
			if(Player2() == 1){
				break;
			}
			
			faus2 = RulePlayer2( yi, xi, yj, xj);	
			Xaxis();
			MShogiBoard();
			if (Winner() == 0)
				break;
		}while (faus2==1);	
		//TEST();
		
	}
}







// 
// 
// 
//其中一方的將帥被封在一個無法移動的地方，另一方獲勝。
//int RulesOfKingCannotMove()
//{
//	if (**TempKingPlayer1 == 'h') {
//		*TempKingPlayer1;
//		(((yj == yi - 1) && (xj == xi || xj == xi + 1 || xj == xi - 1)) || ((yj == yi + 1) && (xj == xi || xj == xi + 1 || xj == xi - 1) || ((yj == yi) && (xj == xi + 1 || xj == xi - 1))));
//	}
//}
//其中一方的棋子全部被吃光，另一方獲勝。
//兩方雙方同意和棋，棋局結束。
//如果比賽時間結束，按照各方棋子的數量和棋子的位置進行評分，分數高的一方獲勝。

