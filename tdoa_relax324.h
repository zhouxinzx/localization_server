#include<iostream>
#include<cmath>
#define pi 3.1415926535
#define Num_Node 8
using namespace std;
void tdoa(int Node_number, long double *measure_data, double *Microphone_Cita, double Microphone_Center_Location[Num_Node][2], double Microphone_Distance, double Room_Length, double Room_Width, int scale, double *result,int *data_flag)
{
	double Microphone_1_Location[Num_Node][2];
	double Microphone_2_Location[Num_Node][2];
	int data[Num_Node]={0};
	int size=0;
	for (int i = 0; i<Node_number; i++)
	{
		Microphone_1_Location[i][0] = Microphone_Center_Location[i][0] + 0.5*Microphone_Distance*(cos(Microphone_Cita[i] * pi / 180));
		Microphone_1_Location[i][1] = Microphone_Center_Location[i][1] + 0.5*Microphone_Distance*(-sin(Microphone_Cita[i] * pi / 180));
		Microphone_2_Location[i][0] = Microphone_Center_Location[i][0] - 0.5*Microphone_Distance*(cos(Microphone_Cita[i] * pi / 180));
		Microphone_2_Location[i][1] = Microphone_Center_Location[i][1] - 0.5*Microphone_Distance*(-sin(Microphone_Cita[i] * pi / 180));
		if(measure_data[i]>0)
			data[i]=1;
		else
			data[i]=0;

		if(data_flag[i]==1)
			size=size+1;
	}
	int Length, Width;
	int sum_size=0;
	double sum_x=0;
	double sum_y=0;
	Length = (int)Room_Length;
	Width = (int)Room_Width;
	double xx = 0, yy = 0, xx1=0, yy1=0;
	double min = 1000;
	for (int k = 0; k<scale*Width; k++)
	{
		for (int j = 0; j<scale*Length; j++)
		{
			double x = k / (scale*1.0);
			double y = j / (scale*1.0);
			double data_temp[Num_Node];
			int temp[Num_Node]={0};
			int total=0;
			for (int i = 0; i<Node_number; i++)
			{
				data_temp[i] = (sqrt((x - Microphone_1_Location[i][0])*(x - Microphone_1_Location[i][0]) + (y - Microphone_1_Location[i][1])*(y - Microphone_1_Location[i][1])) - sqrt((x - Microphone_2_Location[i][0])*(x - Microphone_2_Location[i][0]) + (y - Microphone_2_Location[i][1])*(y - Microphone_2_Location[i][1]))) / 340;
				if(data_temp[i]>0)
					temp[i]=1;
				else
					temp[i]=0;

			}
			double error = 0;
			for (int i = 0; i<Node_number; i++)
			{
				double temp = abs(data_temp[i] - measure_data[i]);
				if(data_flag[i]==1)
				error = error + temp;
			}
			if (error<min)
			{
				min = error;
				xx = x;
				yy = y;
			}

			for(int i=0;i<Node_number;i++)
			{
				if(data_flag[i]==1&&data_temp[i]==data[i])
					total++;
			}
			if(total==Num_Node)
			{
				sum_x=sum_x+x;
				sum_y=sum_y+y;
				sum_size++;
			}
		}
	}
	xx1=sum_x/(sum_size*1.0);
	yy1=sum_y/(sum_size*1.0);
	result[0] = xx;
	result[1] = yy;
	//cout<<result[0]<<endl;
}
