// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include <ctime>
#include<fstream>
using namespace std;
int a[9][9], b[9][9], c[9][9],d[9][9];//创建三个数组分别用于存储结果(a),判断每一列的数字是否重复(b),判断以3*3方格的方式是否符合数独规则(c);
ofstream fo;
void  initialize() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = 0;
			b[i][j] = 0;
			c[i][j] = 0;
			d[i][j] = 0;
		}
	}
}
int judge(int x,int y,int count) {
	int z;
	if (a[x][y])//判断该位置是否已有数字
		return 0;
	else if (b[y][count - 1] == 1)//判断在第y列中是否已经存在该数字
		return 0;
	else if (d[x][count - 1] == 1)
		return 0;
	z = (x - (x % 3)) + ((y - (y % 3))/3);
	if (c[z][count - 1] == 1)
		return 0;
	a[x][y] = count;
	b[y][count - 1] = 1;
	c[z][count - 1] = 1;
	d[x][count - 1] = 1;
	return 1;
}
bool recursion(int x,int y) {
	int ran_num, num[9];
	for (int i = 0; i < 9; i++) {
		num[i] = i+1;
	}
	for (int i = 0; i < 9; i++) {
		ran_num = rand() % 9;
		swap(num[i], num[ran_num]);//使用随机函数来产生1到9的随机数
	}
	for (int i = 0; i < 9; i++) {
		int count = num[i];
		if (count == 9 && (x == 0 || y == 0)) {
			if (x == 0 && y == 0) {
				recursion(x, y + 1);
				return true;
			}
		}
		if (judge(x, y, count) == 1) {
			if (y == 8) {
				if (x == 8)//第一种情况：数独已经形成
					return true;
				else if (recursion(x + 1, 0))//第二种情况：这一行已经遍历完了
					return true;
			}
			else {
				if (recursion(x, y + 1))
					return true;
			}
			a[x][y] = 0;
			b[y][count - 1] = 0;
			c[(x - (x % 3)) + ((y - (y % 3))/3)][count - 1] = 0;
			d[x][count - 1] = 0;
		}
	}
	return false;
}
int main(int argc,char* argv[])
{
	int x;
	if (sscanf_s(argv[2], "%d", &x) == 0)
	{
		cout << "输错了，重输！！！！！！" << endl;
		return 0;
	}
	fo.open(".\\sudoku.txt");
	srand((unsigned)time(0));//从网上学到的根据系统时间来生成的随机数的方法
	while (x--) {
		initialize();//初始化数组
		a[0][0] = 9;
		b[0][8] = 1;
		c[0][8] = 1;
		d[0][8] = 1;
		recursion(0,1);
		for (int i = 0; i< 9; i++) {
			for (int j = 0; j < 9; j++) 
				fo << a[i][j] << " ";
			fo << endl;
		}
		fo << endl;
	}
	fo.close();
    return 0;
}