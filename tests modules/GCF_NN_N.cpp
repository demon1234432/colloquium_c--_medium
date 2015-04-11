#include <iostream>
#include <fstream>
using namespace std;
#include "../struct.h"
natural GCF_NN_N(const natural, const natural); //user function
natural MOD_NN_N(const natural,const natural); //для user function
natural DIV_NN_N(const natural, const natural); //для MOD_NN_N
natural MUL_NN_N(const natural, const natural); //для DIV_NN_N
natural DIV_NN_Nk(const natural, const natural); //для DIV_NN_N
natural SUB_NN_N(const natural, const natural); //для DIV_NN_Nk
natural MUL_Nk_N(const natural, const unsigned short); //для DIV_NN_Nk
unsigned short COM_NN_D(const natural, const natural); //для SUB_NN_N
bool NZER_N_B(const natural); //для COM_NN_D
natural DELZ_N_N(const natural); //для NZER_N_B
natural NEW_N_N(natural); //для DELZ_N_N
void DEL_N(natural); //для DELZ_N_N
natural ADD_1N_N(const natural); //для DIV_NN_Nk
natural MUL_ND_N(const natural, const unsigned short); //для MUL_NN_N
natural ADD_NN_N(const natural, const natural); //для MUL_ND_N
natural COPY_N_N(const natural); //для ADD_NN_N
bool test(const natural, const natural); //для проверки
#include "../modules/GCF_NN_N.cpp" //user function
#include "../modules/MOD_NN_N.cpp" //для user function
#include "../modules/DIV_NN_N.cpp" //для MOD_NN_N
#include "../modules/MUL_NN_N.cpp" //для DIV_NN_N
#include "../modules/DIV_NN_Nk.cpp" //для DIV_NN_N
#include "../modules/SUB_NN_N.cpp" //для DIV_NN_Nk
#include "../modules/MUL_Nk_N.cpp" //для DIV_NN_Nk
#include "../modules/COM_NN_D.cpp" //для SUB_NN_N
#include "../modules/NZER_N_B.cpp" //для COM_NN_D
#include "../modules/DELZ_N_N.cpp" //для NZER_N_B
#include "../modules/NEW_N_N.cpp" //для DELZ_N_N
#include "../modules/DEL_N.cpp" //для DELZ_N_N
#include "../modules/ADD_1N_N.cpp" //для DIV_NN_Nk
#include "../modules/MUL_ND_N.cpp" //для MUL_NN_N
#include "../modules/ADD_NN_N.cpp" //для MUL_ND_N
#include "../modules/COPY_N_N.cpp" //для ADD_NN_N
#include "test.cpp" //для проверки

int main()
{
	unsigned short n=1;
	char comment[256];
	fstream file("../tests/GCF_NN_N",ios::in);
	if (!file) //Проверка на существование тестов
	{
		cout<<"Проверяющие тесты не найдены!\n";
		return 255;
	};
	while (!file.eof())
	{
		natural x,y,_x,_y,z,result; //Копируем x в _x, y в _y
		file>>x.count;
		if (file.eof()) return 0;
		x=NEW_N_N(x);
		for(register unsigned short j=0;j<x.count;j++)
			file>>x.digits[j];
		_x=COPY_N_N(x);
		file>>y.count;
		y=NEW_N_N(y);
		for(register unsigned short j=0;j<y.count;j++)
			file>>y.digits[j];
		_y=COPY_N_N(y);
		file>>result.count;
		result=NEW_N_N(result);
		for(register unsigned short j=0;j<result.count;j++)
			file>>result.digits[j];
		file.ignore();
		file.getline(comment,256);
		file.clear();
		z=GCF_NN_N(x,y);//user function
		if (!test(x,_x) || !test(y,_y)) //Проверка на сохранность данных
		{
			cout<<"Ошибка! Данные, переданные в модуль, были изменены!";
			return 254;
		};
		if (!test(z/*user function*/,result))
		{
			cout<<"Ошибка в тесте "<<n<<":\n";
			for(register unsigned char i=0;comment[i];i++)
				cout<<comment[i];
			return n;
		};
		DEL_N(x);
		DEL_N(_x);
		DEL_N(y);
		DEL_N(_y);
		DEL_N(z);
		DEL_N(result);
		n++;
	};
	return 0;
}