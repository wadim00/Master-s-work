//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "groupedItems.h"
#include "Unit1.h"
#include "Unit2.h"
#include <windows.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string.h>
#include <chrono>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBetcherForm *BetcherForm;
using namespace std;
unsigned __int64 elements_amount; //кількість елементів
unsigned __int64 proc_amount; // кількість процесорів
std::size_t *array_sorted,array_size;

//---------------------------------------------------------------------------
__fastcall TBetcherForm::TBetcherForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBetcherForm::BackToMainForm(TObject *Sender)
{
  Hide();
  GridForm->AppBar->Height-=15;
  BetcherForm->Height+=10;
  GridForm->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TBetcherForm::Button1Click(TObject *Sender)
{
 bool execute=false;
 //Очистка таблиць
 for(unsigned __int64 i = 0; i < StringGrid1->ColCount; i++)
 for(unsigned __int64 j = 0; j < StringGrid1->RowCount; j++)
 StringGrid1->Cells[i][j] = "";
 StringGrid1->RowCount=1;

 for(unsigned __int64 i = 0; i < StringGrid2->ColCount; i++)
 for(unsigned __int64 j = 0; j < StringGrid2->RowCount; j++)
 StringGrid2->Cells[i][j] = "";
 StringGrid2->RowCount=1;

 for(unsigned __int64 i = 0; i < StringGrid3->ColCount; i++)
 for(unsigned __int64 j = 0; j < StringGrid3->RowCount; j++)
 StringGrid3->Cells[i][j] = "";
 StringGrid3->RowCount=2;

 Series1->Clear();
 Series2->Clear();
 Memo1->Clear();


 if (Edit1->Text.Length()>0 && CheckBox2->Checked==true)
 {
  array_size=StrToInt(Edit1->Text);
  elements_amount=StrToInt(Edit1->Text);
  execute=true;

 }
 else
 if (CheckBox2->Checked==true && Edit1->Text.Length()==0)
 {
  ShowMessage("Введіть кількість елементів масиву!");
 }
 else
 if (CheckBox2->Checked==false && Edit6->Text.Length()>0 && Edit1->Text.Length()>0)
 {
   proc_amount=StrToInt(Edit6->Text);
   array_size=StrToInt(Edit1->Text);
   elements_amount=StrToInt(Edit1->Text);
   execute=true;
 }
 else
 if (CheckBox2->Checked==false && Edit6->Text.Length()==0 && Edit1->Text.Length()>0)
 {
   ShowMessage("Введіть кількість процесорних елементів!");
 }
 else
 if (CheckBox2->Checked==false && Edit6->Text.Length()>0 && Edit1->Text.Length()==0)
 {
   ShowMessage("Введіть кількість елементів масиву!");
 }
  else
 if (CheckBox2->Checked==false && Edit6->Text.Length()==0 && Edit1->Text.Length()==0)
 {
   ShowMessage("Введіть кількість елементів масиву та кількість процесорів!");
 }

 if (execute) {
	array_sorted=new std::size_t[array_size];
	unsigned __int64 j=0,k=0;
	for (unsigned __int64 i = 0; i <array_size; i++)
	{
	array_sorted[i]=rand() % 1234567887ui64 +1;
	}
	for (unsigned __int64 i = 0; i <array_size; i++)
	{
		if(j<10)
		{
			StringGrid1->Cells[j][k]=array_sorted[i];
			Series1->AddXY(i,array_sorted[i],"",clYellow);
			j++;
		}
		else  if (j==10)
		{
			i--;
			j=0;
			k++;
			StringGrid1->RowCount++;
		}
	}
 }
}
//---------------------------------------------------------------------------
void __fastcall TBetcherForm::Button2Click(TObject *Sender)
{
 unsigned __int64 z=0,x=0,proc=proc_amount;
 float memory_size;
 if (algorithm_number==1)
 {
	auto begin = std::chrono::steady_clock::now();
	unsigned __int64 t,p,q,r,d,N;
	unsigned __int64 temp,counter=0;
	StringGrid3->ColCount=array_size+1;
	x=1;
	bool b;
	N=array_size;
	t = std::log2(N);
	if (pow(2,t)<N)
	{
		t++;
	}
		p=pow(2,t-1);
	while(p>0)
	{
		   q=pow(2,t-1);
		   r=0;
		   d=p;
		   m1: //мітка переходу від кроку 5 до кроку 3

		   for (unsigned __int64 i = 0; i < N-d; i++)
		   if ((i&p)==r)
		   {

				counter++;
				if (array_sorted[i]>array_sorted[i+d])
				{
					temp=array_sorted[i];
					array_sorted[i]=array_sorted[i+d];
					array_sorted[i+d]=temp;
				}
				  //Блок зменшення ширини СМ
				if (CheckBox2->Checked==true)
				{
					StringGrid3->Cells[i+1][x]=counter;
					StringGrid3->Cells[i+d+1][x]=counter;
				}
				else
				if (CheckBox2->Checked==false)
				{
					m2:
					if (proc>0)
					{
						StringGrid3->Cells[i+1][x]=counter;
						StringGrid3->Cells[i+d+1][x]=counter;
						proc--;
					}
					else
					{
						x++;
						StringGrid3->RowCount++;
						proc=proc_amount;
						goto m2;
					}

				}

				//Блок оптимізації структурної матриці
				if (x>=2 && CheckBox1->Checked)
				{
					unsigned __int64 count=x;
					while (StringGrid3->Cells[i+1][count-1]=="" && StringGrid3->Cells[i+d+1][count-1]=="" && (i+d+1)<=StringGrid3->ColCount && count>=2)
					{
					 StringGrid3->Cells[i+1][count-1]=counter;
					 StringGrid3->Cells[i+d+1][count-1]=counter;
					 StringGrid3->Cells[i+1][count]="";
					 StringGrid3->Cells[i+d+1][count]="";
					 count--;
					}
				}
				/////////////////////////////////////
		   }

		   x++;
		   StringGrid3->RowCount++;
		   proc=proc_amount;

		   b= q!=p;

		   if (b)
		   {
				d=q-p;
				q=q/2;
				r=p;
				goto m1;
		   }
		   p=p/2;




	}
	auto end = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	Edit5->Text=elapsed_ms.count();
	StringGrid3->RowCount--;
	Edit2->Text=counter; //Кількість операцій порівняння
	Edit3->Text=x-1;  //Кількість ярусів
	memory_size=(float(x)*float(array_size)*8.0)/1000000.0;
	Edit4->Text=memory_size;  // Об'єм пам'яті в мегабайтах
	StringGrid3->Cells[0][0]=array_size;
	StringGrid3->Cells[1][0]=x-1;
 }
 else
 if (algorithm_number==2)
 {
		auto begin = std::chrono::steady_clock::now();
		StringGrid3->ColCount=array_size+1;
		unsigned __int64 temp,counter=0;
		x=1;
		for (unsigned __int64 i = 0; i<=array_size; i++)
		{
			if (i%2==1)
			{
				for (unsigned __int64 j = 0; j < (array_size/2)-1; j++)
				{
				  counter++;
				  if (array_sorted[2*j+1]>array_sorted[2*j+2])
				  {
					temp=array_sorted[2*j+1];
					array_sorted[2*j+1]=array_sorted[2*j+2];
					array_sorted[2*j+2]=temp;
				  }
				  //Блок зменшення ширини СМ (непарна частина)
				  if (CheckBox2->Checked==true)
				  {
					StringGrid3->Cells[2*j+2][x]=counter;
					StringGrid3->Cells[2*j+3][x]=counter;
				  }
				  else
				  if (CheckBox2->Checked==false)
				  {
						m4:
						if (proc>0)
						{
							StringGrid3->Cells[2*j+2][x]=counter;
							StringGrid3->Cells[2*j+3][x]=counter;
							proc--;
						}
						else
						{
							x++;
							StringGrid3->RowCount++;
							proc=proc_amount;
							goto m4;
						}

					}
				  /////////////////////////////////////////////
				  //Блок оптимізації структурної матриці
				  if (x>=2 && CheckBox1->Checked)
				  {
					unsigned __int64 count=x;
					while (StringGrid3->Cells[2*j+2][count-1]=="" && StringGrid3->Cells[2*j+3][count-1]=="")
					{
					 StringGrid3->Cells[2*j+2][count-1]=counter;
					 StringGrid3->Cells[2*j+3][count-1]=counter;
					 StringGrid3->Cells[2*j+2][count]="";
					 StringGrid3->Cells[2*j+3][count]="";
					 count--;
					}
				  }
				  /////////////////////////////////////
				}

			}
			if (i%2==0)
			{
				for (unsigned __int64 j = 0; j <=(array_size/2)-1; j++)
				{
				  counter++;
				  if (array_sorted[2*j]>array_sorted[2*j+1])
				  {
					temp=array_sorted[2*j];
					array_sorted[2*j]=array_sorted[2*j+1];
					array_sorted[2*j+1]=temp;
				  }
				  //Блок зменшення ширини СМ (парна частина)
				  if (CheckBox2->Checked==true)
				  {
					StringGrid3->Cells[2*j+1][x]=counter;
					StringGrid3->Cells[2*j+2][x]=counter;
				  }
				  else
				  if (CheckBox2->Checked==false)
				  {
						m5:
						if (proc>0)
						{
							StringGrid3->Cells[2*j+1][x]=counter;
							StringGrid3->Cells[2*j+2][x]=counter;
							proc--;
						}
						else
						{
							x++;
							StringGrid3->RowCount++;
							proc=proc_amount;
							goto m5;
						}

					}
				  /////////////////////////////////////////////
				  //Блок оптимізації структурної матриці
				   if (x>=2 && CheckBox1->Checked)
				  {
					unsigned __int64 count=x;
					while (StringGrid3->Cells[2*j+1][count-1]=="" && StringGrid3->Cells[2*j+2][count-1]=="")
					{
					 StringGrid3->Cells[2*j+1][count-1]=counter;
					 StringGrid3->Cells[2*j+2][count-1]=counter;
					 StringGrid3->Cells[2*j+1][count]="";
					 StringGrid3->Cells[2*j+2][count]="";
					 count--;
					}
				  }
				  /////////////////////////////////////
				}

			}
			x++;
			StringGrid3->RowCount++;
			proc=proc_amount;


		}
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		Edit5->Text=elapsed_ms.count();
		StringGrid3->RowCount--;
		Edit2->Text=counter; //Кількість операцій порівняння
		Edit3->Text=x-1;     //Кількість ярусів
		memory_size=(float(x)*float(array_size)*8.0)/1000000.0;
		Edit4->Text=memory_size;  //Об'єм пам'яті в мегабайтах
		StringGrid3->Cells[0][0]=array_size;
		StringGrid3->Cells[1][0]=x-1;
 }
 else
 if (algorithm_number==3)
 {

		StringGrid3->ColCount=array_size+2;
		unsigned __int64 temp,counter=0,rowcount=0;
		x=1;
		__int64 j;
		std::size_t *help_array;
  		help_array=new std::size_t[array_size+1];
		for (unsigned __int64 i = 0; i <array_size; i++)
		{
		 help_array[i+1]=array_sorted[i];
		}


			auto begin = std::chrono::steady_clock::now();

			unsigned __int64 incr = array_size/2;
			while( incr > 0 )
			{
				for ( unsigned __int64 i=incr+1; i<=array_size; i++ )
				{
					j = i-incr;
					while ( j > 0 )
					{

                       if (CheckBox2->Checked==true)
						{
							if (StringGrid3->Cells[j][x]=="" && StringGrid3->Cells[j+incr][x]=="")
							{
								counter++;
								StringGrid3->Cells[j][x]=counter;
								StringGrid3->Cells[j+incr][x]=counter;
							}
							else
							{
								while (StringGrid3->Cells[j][x]!="" || StringGrid3->Cells[j+incr][x]!="")
								{
									x++;
									while (StringGrid3->RowCount<x)
									{
										StringGrid3->RowCount++;
									}

								}
								counter++;
								StringGrid3->Cells[j][x]=counter;
								StringGrid3->Cells[j+incr][x]=counter;
							}
						}
                        else
						//Блок зменшення ширини СМ
						if (CheckBox2->Checked==false)
						{
							m3:
							if (proc>0)
							{
								if (StringGrid3->Cells[j][x]=="" && StringGrid3->Cells[j+incr][x]=="")
								{
									counter++;
									StringGrid3->Cells[j][x]=counter;
									StringGrid3->Cells[j+incr][x]=counter;
								}
								else
								{
									while (StringGrid3->Cells[j][x]!="" || StringGrid3->Cells[j+incr][x]!="")
									{
										x++;
										while (StringGrid3->RowCount<x)
										{
										StringGrid3->RowCount++;
										}

									}
								counter++;
								StringGrid3->Cells[j][x]=counter;
								StringGrid3->Cells[j+incr][x]=counter;
								}
								proc--;
							}
							else
							{
								x++;
								StringGrid3->RowCount++;
								proc=proc_amount;
								goto m3;
							}

						}
						//////////////////////////////////////////////////////////
						//Блок оптимізації структурної матриці
						if (x>=2 && CheckBox1->Checked)
						{
							unsigned __int64 count=x;
							while (StringGrid3->Cells[j][count-1]=="" && StringGrid3->Cells[j+incr][count-1]=="" && (j+incr)<=StringGrid3->ColCount && count>=2)
							{
								StringGrid3->Cells[j][count-1]=counter;
								StringGrid3->Cells[j+incr][count-1]=counter;
								StringGrid3->Cells[j][count]="";
								StringGrid3->Cells[j+incr][count]="";
								count--;
							}
						}
						/////////////////////////////////////
						if ( help_array[j] > help_array[j+incr] )
						{
							temp=help_array[j];
							help_array[j]=help_array[j+incr];
							help_array[j+incr]=temp;
							j = j - incr;
						}
						else j =0;
					}
				}
				incr = incr/2; x=StringGrid3->RowCount; StringGrid3->RowCount+=2;  proc=proc_amount;
			}




		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		for (unsigned __int64 i = 1; i <array_size+1; i++)
		{
		 array_sorted[i-1]=help_array[i];
		}
		delete [] help_array;


		Edit5->Text=elapsed_ms.count();
		StringGrid3->RowCount--;
		Edit2->Text=counter; //Кількість операцій порівняння
		Edit3->Text=x-1;     //Кількість ярусів
		memory_size=((float(x)*float(array_size)*8.0)/1000000.0);
		Edit4->Text=memory_size;   //Об'єм пам'яті в мегабайтах
		StringGrid3->Cells[0][0]=array_size;
		StringGrid3->Cells[1][0]=x-1;
 }

//Заповнення матриці нулями
 for(unsigned __int64 i = 1; i < StringGrid3->ColCount; i++)
	for(unsigned __int64 j = 1; j < StringGrid3->RowCount; j++)
		if(StringGrid3->Cells[i][j] == "")
			{
				StringGrid3->Cells[i][j] =0;
			}

//Видалення рядків з нулями
 unsigned __int64 zero_count=0, zero_rows=0;
 for(unsigned __int64 i = 1; i <=StringGrid3->RowCount; i++)
 {
	for(unsigned __int64 j = 1; j <=StringGrid3->ColCount; j++)
	{
			if(StringGrid3->Cells[j][i] == "0")
			{
			 zero_count++;

			}
			if (zero_count==StringGrid3->ColCount-1)
			{
			  zero_rows++;
			  zero_count=0;

			}
			if(StringGrid3->Cells[j][i] != "0")
			{
			 zero_count=0;
			 break;
			}

	}
  }
 StringGrid3->RowCount=StringGrid3->RowCount-zero_rows;
 StringGrid3->Refresh();
//Оновлена кількість ярусів структурної матриці
 Edit3->Text=StringGrid3->RowCount-1;
 StringGrid3->Cells[1][0]=StringGrid3->RowCount-1;
/*if (CheckBox1->Checked)
{
 StructForm->Series3->AddXY(array_size,StringGrid3->RowCount-1,"",clRed);
}
else
{
 StructForm->Series1->AddXY(array_size,StringGrid3->RowCount-1,"",clRed);
}  */

 z=0,x=0;
	for (unsigned __int64 i = 0; i <array_size; i++)
	{
		if(z<10)
		{
				StringGrid2->Cells[z][x]=array_sorted[i];
				Series2->AddXY(i,array_sorted[i],"",clRed);
				z++;
		}
		else
		if (z==10)
		{
				i--;
				z=0;
				x++;
				StringGrid2->RowCount++;
		}
	}

   delete [] array_sorted;
   String line="";
	for(unsigned __int64 i = 0; i <=StringGrid3->RowCount; i++)
	{
		for(unsigned __int64 j = 0; j <=StringGrid3->ColCount; j++)
		{
				line+=StringGrid3->Cells[j][i];
				if (StringGrid3->Cells[j][i].Length()==1)
				{
						line+="  ";
				}
				else line+=" ";

		}
		Memo1->Lines->Add(line);
		line="";
	}

}
//---------------------------------------------------------------------------

void __fastcall TBetcherForm::Button3Click(TObject *Sender)
{
	   String filename;
	   OpenTextFileDialog1->Filter = "Text files (*.txt)|*.TXT|Any file (*.*)|*.*";
	   SaveTextFileDialog1->Filter = "Text files (*.txt)|*.TXT|Any file (*.*)|*.*";
	   if (algorithm_number==1)
	   {
			filename+="Betcher_Sort_";
			filename+=elements_amount;
			filename+=".txt";
	   }
	   else
	   if (algorithm_number==2)
	   {
			filename+="Permutation_Sort_";
			filename+=elements_amount;
			filename+=".txt";
	   }
	   else
	   if (algorithm_number==3)
	   {
			filename+="Shell_Sort_";
			filename+=elements_amount;
			filename+=".txt";
	   }

	   SaveTextFileDialog1->FileName=filename;
	  // Execute a save file dialog.
	  if (SaveTextFileDialog1->Execute())
	  // First, check if the file exists.
	  if (FileExists(OpenTextFileDialog1->FileName))
	  // If it exists, throw a message.
	  ShowMessage("Файл з таким іменем вже існує. Змініть ім'я файлу!");
	  else
	  // Otherwise, save the memo box lines into the file.

	  Memo1->Lines->SaveToFile(SaveTextFileDialog1->FileName);

}
//---------------------------------------------------------------------------






void __fastcall TBetcherForm::Chart2ClickSeries(TCustomChart *Sender, TChartSeries *Series,
          int ValueIndex, TMouseButton Button, TShiftState Shift, int X,
          int Y)
{
 Edit5->Text=ValueIndex;
}
//---------------------------------------------------------------------------

void __fastcall TBetcherForm::CheckBox2Click(TObject *Sender)
{
  if (CheckBox2->Checked)
  {
   Edit6->Enabled=false;
   CheckBox1->Enabled=true;
  }
  else
  {
   Edit6->Enabled=true;
   CheckBox1->Enabled=false;
   CheckBox1->Checked=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TBetcherForm::Image2Click(TObject *Sender)
{
  StructForm->Show() ;
  StructForm->StringGrid1->Cells[0][0]="Номер ярусу";
  StructForm->StringGrid1->Cells[1][0]="Кількість операцій";
  unsigned __int64 operation_amount=0,operation_per_row=0;
  for (unsigned __int64 i = 1; i <StringGrid3->RowCount; i++)
  {
		for (unsigned __int64 j = 1; j <StringGrid3->ColCount; j++)
		{
			if (StringGrid3->Cells[j][i]>0)
			{
			 operation_per_row++; //Кількість операцій на ярусі
			 operation_amount++;
			}
		}
		StructForm->StringGrid1->Cells[1][i]=operation_per_row/2;
		StructForm->StringGrid1->Cells[0][i]=i;
		StructForm->StringGrid1->RowCount++;
		operation_per_row=0;
  }
  StructForm->Edit1->Text=operation_amount/2; //Загальна кількість операцій
  StructForm->Edit2->Text=StringGrid3->RowCount-1; //Кількість рядків(час виконання паралельного алгоритму)

  if (CheckBox2->Checked)
  {
		StructForm->Edit3->Text=array_size/2; // Кількість процесорних елементів
  }
  else
  {
		StructForm->Edit3->Text=proc_amount;
  }
  StructForm->Edit4->Text=FloatToStr(float(operation_amount/2)/float(StringGrid3->RowCount-1));

  if (CheckBox2->Checked)
  {
   StructForm->Edit5->Text=FloatToStr((float(operation_amount/2)/float(StringGrid3->RowCount-1))/float(array_size/2));
  }
  else
  {
  StructForm->Edit5->Text=FloatToStr((float(operation_amount/2)/float(StringGrid3->RowCount-1))/float(proc_amount));
  }
  StructForm->Series2->AddXY(array_size,float(operation_amount/2)/float(StringGrid3->RowCount-1),"",clRed);
  StructForm->Series1->AddXY(array_size,(float(operation_amount/2)/float(StringGrid3->RowCount-1))/float(array_size/2),"",clRed);


}
//---------------------------------------------------------------------------

