// Copyright 2015 © Группа 4373, Другов Павел и Пынько Антон, 26.04.2015
//
#ifndef RED_Q_Q_CPP
#define RED_Q_Q_CPP

#include "../../structs/struct.h"
#include "RED_Q_Q.cpp"
using namespace std;

bool INT_Q_Z(fraction Q_2)
{
	fraction F = Q_2;//сохранение значения аргумента
	RED_Q_Q(F);//Сокращение дроби
	return (F.denominator == { _1 });//сравнение знаменателя с единицей и возврат результата
}

#endif //RED_Q_Q_CPP
