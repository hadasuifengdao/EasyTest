#include "graph.h"
#include<easyx.h>
#include<conio.h>
unsigned long int Graph::COLOR_BLUE = BLUE;
unsigned long int Graph::COLOR_BLACK = BLACK;
unsigned long int Graph::COLOR_RED = RED;
unsigned long int Graph::COLOR_GREEN = GREEN;
//初始化窗口
Graph::Graph(int windowWidth, int windowHigh) {
	this->windowHigh = windowHigh;
	this->windowWidth = windowWidth;
	windowPadding = 50;
	//直线默认属性
	lineColor = BLACK;
	textColor = BLACK;
	lineWidth = 2;
	initgraph(windowWidth, windowHigh);
	setbkcolor(WHITE);
	cleardevice();
}
//画坐标轴
void Graph::drawCoordinateAxis(int xLimit, int yLimit, int xStep, int yStep) {
	xScale = (windowWidth - 2 * windowPadding) / xLimit;
	yScale = (windowHigh - 2 * windowPadding) / yLimit;
	baseLengthX = (windowWidth - 2 * windowPadding) / (xLimit / xStep);
	baseLengthY = (windowHigh - 2 * windowPadding) / (yLimit / yStep);
	setlinecolor(lineColor);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, lineWidth);
	line(windowPadding, windowHigh - windowPadding, windowPadding + xLimit / xStep * baseLengthX, windowHigh - windowPadding);
	line(windowPadding, windowHigh - windowPadding, windowPadding, windowHigh - (windowPadding + yLimit / yStep * baseLengthY));
	settextcolor(BLACK);
	drawNum(0, 0, 0);
	int i;
	for (i = xStep; i <= xLimit; i += xStep) {
		TCHAR c[20];
		_stprintf_s(c, _T("%d"), i);
		outtextxy(windowPadding + i * xScale, windowHigh - (windowPadding - 10), c);
	}
	int w = 0, ww = yLimit;
	while (ww) {
		w++;
		ww /= 10;
	}
	for (i = yStep; i <= yLimit; i += yStep) {
		TCHAR c[20];
		_stprintf_s(c, _T("%d"), i);
		outtextxy(windowPadding - 10 * w, windowHigh - (windowPadding + i * yScale), c);
	}
}
//画线
void Graph::setLineColor(unsigned long int color) {
	setlinecolor(color);
}
void Graph::setLineWidth(int width) {
	this->lineWidth = width;
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, width);
}
void Graph::drawLine(int x1, int y1, int x2, int y2) {
	line(windowPadding + x1 * xScale, windowHigh - (windowPadding + y1 * yScale), windowPadding + x2 * xScale, windowHigh - (windowPadding + y2 * yScale));
}
void setTextColor(int color) {
	settextcolor(color);
}
//写数字
void Graph::setTextColor(COLORREF color) {
	textColor = color;
	settextcolor(color);
}
void Graph::drawNum(int x, int y, int num)
{
	TCHAR c[20];
	_stprintf_s(c, _T("%d"), num);
	settextcolor(textColor);
	outtextxy(windowPadding + x * xScale - 10, windowHigh - (windowPadding + y * yScale - 10), c);
}
//画点
void Graph::setPointColor(unsigned long int color) {
	pointColor = color;
	setfillcolor(color);
	setlinecolor(color);
}
void Graph::drawPoint(int x, int y) {
	setfillcolor(pointColor);
	fillcircle(windowPadding + x * xScale, windowHigh - (windowPadding + y * yScale), 3);
}
void Graph::show() {
	_getch();
}