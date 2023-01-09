#ifndef DEFINE_H
#define DEFINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#define B(piece) "\033[34m"#piece"\033[0m"
#define R(piece) "\033[31m"#piece"\033[0m"
#define NameWordsQuantity 30
#define BoardColum  11 //行

#define BoardRow 13 //列
#define PlayerQuantity 2
#define AbbreviationQuantity 3 
#define NO 's'
#define JP 5

extern int xi;
extern int yi;//要移動的棋子
extern int xj;
extern int yj;//移動的目標位置
//extern char space[4];
typedef struct shogi shogi;
struct shogi 
{
	char Name[NameWordsQuantity];
	int Player;
	char represent[NameWordsQuantity];
	//int xi, yi;//位置
};


typedef struct node Node;
struct node
{
	int yj;
	int xj;
	int yi;
	int xi;
	struct node *next;
};

shogi ShogiBoard[BoardRow][BoardColum];


#endif
