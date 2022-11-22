#pragma once
#include <map>
#include "koreanInput.h"

bool hangulTables::containHangul(char _code)
{
	if (hangulMap.count(_code) > 0)
		return true;
	else
		return false;
}
bool hangulTables::containCho(wchar_t _code)
{
	if (choMap.count(_code) > 0)
		return true;
	else
		return false;
}
bool hangulTables::containJoong(wchar_t _code)
{
	if (joongMap.count(_code) > 0)
		return true;
	else
		return false;
}
bool hangulTables::containJong(wchar_t _code)
{
	if (jongMap.count(_code) > 0)
		return true;
	else
		return false;
}

bool hangulTables::containCombine(wchar_t _code)
{
	if (combineMap.count(_code) > 0)
		return true;
	else
		return false;
}

bool hangulTables::containDetach(wchar_t _code)
{
	if (detachMap.count(_code) > 0)
		return true;
	else
		return false;
}


wchar_t hangulTables::ascii2Hangul(char _code)
{
	if (containHangul(_code) == true)
		return hangulMap.at(_code);
	else
		return NULL;
}
int hangulTables::hangul2Cho(wchar_t _code)
{
	if (containCho(_code) == true)
		return choMap.at(_code);
	else
		return NULL;
}
int hangulTables::hangul2Jong(wchar_t _code)
{
	if (containJong(_code) == true)
		return jongMap.at(_code);
	else
		return NULL;
}
int hangulTables::hangul2Joong(wchar_t _code)
{
	if (containJoong(_code) == true)
		return joongMap.at(_code);
	else
		return NULL;
}
std::vector<wchar_t> hangulTables::getCombine(wchar_t _code)
{
	return combineMap.at(_code);
}
std::vector<wchar_t> hangulTables::getDetach(wchar_t _code)
{
	return detachMap.at(_code);
}

std::map<wchar_t, int> hangulTables::choMap = {
	{L'��', 0},
	{L'��', 1},
	{L'��', 2},
	{L'��', 3},
	{L'��', 4},
	{L'��', 5},
	{L'��', 6},
	{L'��', 7},
	{L'��', 8},
	{L'��', 9},
	{L'��', 10},
	{L'��', 11},
	{L'��', 12},
	{L'��', 13},
	{L'��', 14},
	{L'��', 15},
	{L'��', 16},
	{L'��', 17},
	{L'��', 18}
};

std::map<wchar_t, int> hangulTables::joongMap = {
	{L'��', 0},
	{L'��', 1},
	{L'��', 2},
	{L'��', 3},
	{L'��', 4},
	{L'��', 5},
	{L'��', 6},
	{L'��', 7},
	{L'��', 8},
	{L'��', 9},
	{L'��', 10},
	{L'��', 11},
	{L'��', 12},
	{L'��', 13},
	{L'��', 14},
	{L'��', 15},
	{L'��', 16},
	{L'��', 17},
	{L'��', 18},
	{L'��', 19},
	{L'��', 20}
};

std::map<wchar_t, int> hangulTables::jongMap = {
	{NULL, 0}, // �������� 0�� �����ϴ� ���� ����.
	{L'��', 1},
	{L'��', 2},
	{L'��', 3},
	{L'��', 4},
	{L'��', 5},
	{L'��', 6},
	{L'��', 7},
	{L'��', 8},
	{L'��', 9},
	{L'��', 10},
	{L'��', 11},
	{L'��', 12},
	{L'��', 13},
	{L'��', 14},
	{L'��', 15},
	{L'��', 16},
	{L'��', 17},
	{L'��', 18},
	{L'��', 19},
	{L'��', 20},
	{L'��', 21},
	{L'��', 22},
	{L'��', 23},
	{L'��', 24},
	{L'��', 25},
	{L'��', 26},
	{L'��', 27}
};

std::map<char, wchar_t> hangulTables::hangulMap = {
	{'a', L'��'},
	{'b', L'��'},
	{'c', L'��'},
	{'d', L'��'},
	{'e', L'��'},
	{'f', L'��'},
	{'g', L'��'},
	{'h', L'��'},
	{'i', L'��'},
	{'j', L'��'},
	{'k', L'��'},
	{'l', L'��'},
	{'m', L'��'},
	{'n', L'��'},
	{'o', L'��'},
	{'p', L'��'},
	{'q', L'��'},
	{'r', L'��'},
	{'s', L'��'},
	{'t', L'��'},
	{'u', L'��'},
	{'v', L'��'},
	{'w', L'��'},
	{'x', L'��'},
	{'y', L'��'},
	{'z', L'��'},
	{'A', L'��'},
	{'B', L'��'},
	{'C', L'��'},
	{'D', L'��'},
	{'E', L'��'},
	{'F', L'��'},
	{'G', L'��'},
	{'H', L'��'},
	{'I', L'��'},
	{'J', L'��'},
	{'K', L'��'},
	{'L', L'��'},
	{'M', L'��'},
	{'N', L'��'},
	{'O', L'��'},
	{'P', L'��'},
	{'Q', L'��'},
	{'R', L'��'},
	{'S', L'��'},
	{'T', L'��'},
	{'U', L'��'},
	{'V', L'��'},
	{'W', L'��'},
	{'X', L'��'},
	{'Y', L'��'},
	{'Z', L'��'},
};

std::map <wchar_t, std::vector<wchar_t>> hangulTables::combineMap = {
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {L'��',L'��',L'��',L'��',L'��',L'��',L'��'}},
			{L'��', {NULL}},
			{L'��', {L'��',L'��',L'��'}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {L'��'}},
			{L'��', {L'��',L'��',L'��'}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL,L'��'}},
			{L'��', {NULL,L'��'}},
			{L'��', {L'��',L'��'}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}},
			{L'��', {NULL}}
};

std::map <wchar_t, std::vector<wchar_t>> hangulTables::detachMap = {
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {NULL, L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}},
			{L'��', {L'��', L'��'}}
};