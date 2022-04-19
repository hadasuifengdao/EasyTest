#pragma once
#pragma once
class Graph
{
private:
	int windowHigh, windowWidth, windowPadding;//���ڸߡ����߽���
	int xScale, yScale;//������
	double baseLengthX, baseLengthY;
	int lineWidth;//�߿�
	unsigned long int lineColor, textColor, pointColor;//�ߡ��ı�������ɫ
public:
	//��ɫ
	static unsigned long int COLOR_BLUE;//��ɫ
	static unsigned long int COLOR_BLACK;//��ɫ
	static unsigned long int COLOR_RED;//��ɫ
	static unsigned long int COLOR_GREEN;//��ɫ
	/******
	0 ��ʼ����
	******/
	Graph(int windowWidth, int windowHigh); //����һ����ͼ����
	void drawCoordinateAxis(int xLimit, int yLimit, int xStep, int yStep); //��������
	void show();//��ʾͼ��
	/******
	1 ������
	******/
	void drawPoint(int x, int y);//����
	void setPointColor(unsigned long int pointColor);//���õ���ɫ
	/******
	2 ������
	******/
	void drawLine(int x1, int y1, int x2, int y2);//����
	void setLineWidth(int width);//�����߶ο��
	void setLineColor(unsigned long int color);//�����߶���ɫ
	/******
	3 д����
	******/
	void setTextColor(unsigned long int color);//�����ı���ɫ
	void drawNum(int x, int y, int num);//д��������
};