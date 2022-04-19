#pragma once
#pragma once
class Graph
{
private:
	int windowHigh, windowWidth, windowPadding;//窗口高、宽、边界厚度
	int xScale, yScale;//比例尺
	double baseLengthX, baseLengthY;
	int lineWidth;//线宽
	unsigned long int lineColor, textColor, pointColor;//线、文本、点颜色
public:
	//颜色
	static unsigned long int COLOR_BLUE;//蓝色
	static unsigned long int COLOR_BLACK;//黑色
	static unsigned long int COLOR_RED;//红色
	static unsigned long int COLOR_GREEN;//绿色
	/******
	0 初始化类
	******/
	Graph(int windowWidth, int windowHigh); //创建一个画图窗口
	void drawCoordinateAxis(int xLimit, int yLimit, int xStep, int yStep); //画坐标轴
	void show();//显示图像
	/******
	1 画点类
	******/
	void drawPoint(int x, int y);//画点
	void setPointColor(unsigned long int pointColor);//设置点颜色
	/******
	2 画线类
	******/
	void drawLine(int x1, int y1, int x2, int y2);//画线
	void setLineWidth(int width);//设置线段宽度
	void setLineColor(unsigned long int color);//设置线段颜色
	/******
	3 写字类
	******/
	void setTextColor(unsigned long int color);//设置文本颜色
	void drawNum(int x, int y, int num);//写整数数字
};