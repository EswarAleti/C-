#include<iostream>
#include<iomanip>
#include<ctime>
#include<stdio.h>
using namespace std;

const int colms=7;

void initialize_array(int A[][colms], int rows);
void print_array(int A[][colms],int rows);
void get_result(int A[][colms], int rows);
void get_total_avg_student(int A[][colms],int rows);
void get_total_avg_subject(int A[][colms],int rows);
void get_max_avg_student(int A[][colms],int rows);
void get_max_avg_subject(int A[][colms],int rows);
void get_min_avg_subject(int A[][colms],int rows);
void get_fail_count_all_students(int A[][colms],int rows);
void get_Bgrade_count_all_students(int A[][colms],int rows);

int main()
{
	srand(time(0));
	int rows=10;
	cout<<"Enter number of rows"<<endl;
	cin>>rows;
	int score[rows][colms];
	initialize_array(score,rows);
	print_array(score,rows);
	get_result(score,rows);	
	get_total_avg_student(score,rows);
	get_total_avg_subject(score,rows);
	get_max_avg_student(score ,rows);
	get_max_avg_subject(score ,rows);
	get_min_avg_subject(score,rows);
	get_fail_count_all_students(score , rows);
	get_Bgrade_count_all_students(score ,rows);
	return 0;
}

void initialize_array(int A[][colms], int rows)
{
	cout<<"\n----------Initializing Array()----------\n";
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<colms;j++)
		{
			A[i][j] = rand()%100+1;
		}
	}
}

void print_array(int A[][colms], int rows)
{
	cout<<"\n----------Printing Array()----------\n";
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<colms;j++)
		{
			cout<<setw(4)<<A[i][j];
		}
		cout<<endl;
	}
}

void get_result(int A[][colms], int rows)
{
	cout<<"\n----------get_result()----------\n";
	int row_id, colm_id;
	do
	{
		cout<<"\nEnter rowid and colmid or enter -1 to exit"<<endl;
		cin>>row_id;
		if(row_id==-1)
		{
			break;
		}
		cin>>colm_id;
		if(row_id>=rows || colm_id>=colms)
		{
			cout<<"Invalid student ot subject id"<<endl;
		}
		else
		{
			cout<<"student id="<<row_id<<" subject id="<<colm_id<<" score="<<A[row_id][colm_id]<<endl;
		}
	}while(row_id>=0);
}

void get_total_avg_student(int A[][colms], int rows)
{
	int sid;
	cout<<"\nEnter the id of the student you want to find total"<<endl;
	cin>>sid;
	double total=0,avg=0;
	if(sid>=rows)
	{
		cout<<"Invalid student id"<<endl;
		return;
	}
	for(int j=0;j<colms;j++)
	{
		total=total+A[sid][j];
	}
	avg = total/colms;
	cout<<setw(4)<<"total="<<total<<" avg="<<avg<<endl;
}

void get_total_avg_subject(int A[][colms], int rows)
{
	int subj_id;
	cout<<"\nEnter the id of the subject you want to find total"<<endl;
	cin>>subj_id;
	double total = 0, avg=0;
	if(subj_id>=colms)
	{
		cout<<"Invalid subject id"<<endl;
		return;
	}
	for(int i=0;i<rows;i++)
	{
		total = total+A[i][subj_id];
	}
	avg=total/rows;
	cout<<setw(4)<<"total="<<total<<" avg="<<avg<<endl;
}
void get_max_avg_student(int A[][colms], int rows)
{
	cout<<"\n----get_max_avg_student()----"<<endl;
	double max_avg = -1;
	int id = -1;
	for(int sid = 0 ; sid < rows ; sid++)
	{
		double total=0,avg=0;
		for(int j=0;j<colms;j++)
		{
			total=total+A[sid][j];
		}
		avg = total/colms;
		if(avg > max_avg)
		{
			max_avg = avg;
			id = sid;
		}
	}
	cout<<"Id ="<<id<<" Average ="<<max_avg<<endl;
}
void get_max_avg_subject(int A[][colms],int rows)
{
	cout<<"\n----get_max_avg_subject----"<<endl;
	int id = -1;
	double max_avg = -1;
	for(int subj_id = 0 ; subj_id < colms ; subj_id++)
	{
		double total =0, avg=0;
		for(int i=0;i<rows;i++)
		{
			total = total+A[i][subj_id];
		}
		avg=total/rows;
		if(avg > max_avg)
		{
			max_avg = avg;
			id = subj_id;
		}
	}
	cout<<"Id ="<<id<<" maximum Average ="<<max_avg<<endl;
}
void get_min_avg_subject(int A[][colms],int rows)
{
	cout<<"\n----get_min_avg_subject----"<<endl;
	int id = -1;
	double min_avg = 101;
	for(int subj_id = 0 ; subj_id < colms ; subj_id++)
	{
		double total =0, avg=0;
		for(int i=0;i<rows;i++)
		{
			total = total+A[i][subj_id];
		}
		avg=total/rows;
		if(avg < min_avg)
		{
			min_avg = avg;
			id = subj_id;
		}
	}
	cout<<"Id ="<<id<<" minimum Average ="<<min_avg<<endl;
}
void get_fail_count_all_students(int A[][colms],int rows)
{
	cout<<"\n----get_fail_count_all_students()----"<<endl;
	for(int sid = 0 ; sid < rows ; sid++)
	{
		int fail_count = 0;
		for(int subj_id = 0 ; subj_id < colms ; subj_id++)
		{
			if(A[sid][subj_id] < 60)
			{
				fail_count++;
			}
		}
		cout<<"id ="<<sid<<" number of subjects failed ="<<fail_count<<endl;
	}
}
void get_Bgrade_count_all_students(int A[][colms],int rows)
{
	cout<<"\nget_Bgrade_count_all_students()----"<<endl;
	int count = 0;
	for(int i = 0 ; i < rows ; i++)
	{
		for(int j = 0 ; j < colms ; j++)
		{
			if(A[i][j] > 80 && A[i][j] < 90)
			{
				count++;
			}
		}
	}
	cout<<"number of Bgrade students ="<<count<<endl;
}