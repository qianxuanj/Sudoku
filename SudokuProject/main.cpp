// 2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include <ctime>
#include<fstream>
#include"head.h"
using namespace std;
ofstream fo;
int a[9][9], b[9][9], c[9][9], d[9][9];//������������ֱ����ڴ洢���(a),�ж�ÿһ�е������Ƿ��ظ�(b),�ж���3*3����ķ�ʽ�Ƿ������������(c);
int main(int argc,char* argv[])
{
	int x;
	if (sscanf_s(argv[2], "%d", &x) == 0)
	{
		cout << "����ˣ����䣡����������" << endl;
		return 0;
	}
	fo.open(".\\sudoku.txt");
	srand((unsigned)time(0));//������ѧ���ĸ���ϵͳʱ�������ɵ�������ķ���
	while (x--) {
		initialize();//��ʼ������
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