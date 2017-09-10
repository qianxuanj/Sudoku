
#include "stdafx.h"
#include"head.h"
#include <ctime>
#include<iostream>
#include<algorithm>
using namespace std;
extern int a[9][9], b[9][9], c[9][9], d[9][9];
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
int judge(int x, int y, int count) {
	int z;
	if (a[x][y])//�жϸ�λ���Ƿ���������
		return 0;
	else if (b[y][count - 1] == 1)//�ж��ڵ�y�����Ƿ��Ѿ����ڸ�����
		return 0;
	else if (d[x][count - 1] == 1)
		return 0;
	z = (x - (x % 3)) + ((y - (y % 3)) / 3);
	if (c[z][count - 1] == 1)
		return 0;
	a[x][y] = count;
	b[y][count - 1] = 1;
	c[z][count - 1] = 1;
	d[x][count - 1] = 1;
	return 1;
}
bool recursion(int x, int y) {
	int ran_num, num[9];
	for (int i = 0; i < 9; i++) {
		num[i] = i + 1;
	}
	for (int i = 0; i < 9; i++) {
		ran_num = rand() % 9;
		swap(num[i], num[ran_num]);//ʹ���������������1��9�������
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
				if (x == 8)//��һ������������Ѿ��γ�
					return true;
				else if (recursion(x + 1, 0))//�ڶ����������һ���Ѿ���������
					return true;
			}
			else {
				if (recursion(x, y + 1))
					return true;
			}
			a[x][y] = 0;
			b[y][count - 1] = 0;
			c[(x - (x % 3)) + ((y - (y % 3)) / 3)][count - 1] = 0;
			d[x][count - 1] = 0;
		}
	}
	return false;
}