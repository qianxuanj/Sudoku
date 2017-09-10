// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include <ctime>
#include<fstream>
#include"head.h"
using namespace std;
ofstream fo;
int a[9][9], b[9][9], c[9][9], d[9][9];//创建三个数组分别用于存储结果(a),判断每一列的数字是否重复(b),判断以3*3方格的方式是否符合数独规则(c);
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