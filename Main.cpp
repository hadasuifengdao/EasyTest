#include<stdio.h>
#include"graph.h"
#include "Math.h"
static const float Pi = 3.1415;
int point[4][2] = { {1,9},{9,9},{5,5},{5,1} };
int main() {
	Graph graph = Graph(800, 640);
	graph.drawCoordinateAxis(10, 10, 1, 1);//结合窗口合理设置(´-﹏-`；)
	graph.setPointColor(Graph::COLOR_RED);//设置点颜色
	//graph.setTextColor(Graph::COLOR_BLUE);//设置文本颜色
	//for (int i = 0; i < 4; i++) {
	//	graph.drawPoint(point[i][0], point[i][1]);//画点
	//	graph.drawNum(point[i][0], point[i][1], i + 1);//写数字
	//}
	////设置线格式
	//graph.setLineWidth(1);
	//graph.setLineColor(Graph::COLOR_GREEN);
	////画线
	//graph.drawLine(point[0][0], point[0][1], point[2][0], point[2][1]);
	//graph.drawLine(point[1][0], point[1][1], point[2][0], point[2][1]);
	//graph.drawLine(point[3][0], point[3][1], point[2][0], point[2][1]);

	const float XLength = 2 * Pi;
	const int SubdivisionNumber = 500;
	const float XStepValue = XLength / SubdivisionNumber;
	//float RetPoints[500][500];
	for (float i = 0; i < XLength; i += XStepValue)
	{
		graph.drawPoint(i, 10*sin(i));//画点
		printf("i Value:%f", i);
	}

	
	
	graph.show();
}