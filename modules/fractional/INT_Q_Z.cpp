// Copyright 2015 © Группа 4373, Другов Павел и Пынько Антон, 26.04.2015
//
#ifndef INT_Q_B_CPP
#define INT_Q_B_CPP

#include "../../structs/struct.h"
#include "./RED_Q_Q.cpp"
using namespace std;

bool INT_Q_B(fraction Q_2)
{
	fraction F = Q_2;  // сохранение значения аргумента
	RED_Q_Q(F);  // Сокращение дроби
	return (F.denominator == natural(1));  // сравнение знаменателя с единицей и возврат результата
}

#endif  // INT_Q_B_CPP
