#pragma once
#include<vector>
#include<graphics.h>
#include"Block.h"
using namespace std;
class Tetris
{
public:
	//构造函数
	Tetris(int rows, int cols, int left, int top, int blocksize);
	void init();//初始化
	void play();//开始游戏

private:
	void keyEvent();
	void updateWindow();
	//返回距离上一次调用该函数，间隔了多少时间（ms）
	//第一次调用该函数返回0
	int getDelay();
	void drop();
	void clearLine();
	void moveLeftRight(int offset);
	void rotate();//旋转
	void drawScore();//绘制当前的分数
	void checkOver();//检查游戏是否结束
	void saveScore();
	void displayOver();//绘制游戏画面结束

private:
	int delay;
	bool update;//是否更新

	//int map[10][20]
	//0:空白没有任何方块
	//5:是第五种俄罗斯方块
	vector<vector<int>>map;
	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg;

	IMAGE imgOver;
	IMAGE imgWin;

	Block* curBlock;
	Block* nextBlock;//预告方块
	Block bakBlock;//当前方块降落过程中，用来备份上一个合法方块的位置！

	int score;//当前的分数
	int highestScore;//最高分
	int level;//当前关卡
	int lineCount;//当前消除了多少行
	bool gameOver;//游戏是否已经结束

};

