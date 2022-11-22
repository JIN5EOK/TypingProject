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
	{L'ぁ', 0},
	{L'あ', 1},
	{L'い', 2},
	{L'ぇ', 3},
	{L'え', 4},
	{L'ぉ', 5},
	{L'け', 6},
	{L'げ', 7},
	{L'こ', 8},
	{L'さ', 9},
	{L'ざ', 10},
	{L'し', 11},
	{L'じ', 12},
	{L'す', 13},
	{L'ず', 14},
	{L'せ', 15},
	{L'ぜ', 16},
	{L'そ', 17},
	{L'ぞ', 18}
};

std::map<wchar_t, int> hangulTables::joongMap = {
	{L'た', 0},
	{L'だ', 1},
	{L'ち', 2},
	{L'ぢ', 3},
	{L'っ', 4},
	{L'つ', 5},
	{L'づ', 6},
	{L'て', 7},
	{L'で', 8},
	{L'と', 9},
	{L'ど', 10},
	{L'な', 11},
	{L'に', 12},
	{L'ぬ', 13},
	{L'ね', 14},
	{L'の', 15},
	{L'は', 16},
	{L'ば', 17},
	{L'ぱ', 18},
	{L'ひ', 19},
	{L'び', 20}
};

std::map<wchar_t, int> hangulTables::jongMap = {
	{NULL, 0}, // 曽失拭澗 0拭 企誓馬澗 葵戚 蒸陥.
	{L'ぁ', 1},
	{L'あ', 2},
	{L'ぃ', 3},
	{L'い', 4},
	{L'ぅ', 5},
	{L'う', 6},
	{L'ぇ', 7},
	{L'ぉ', 8},
	{L'お', 9},
	{L'か', 10},
	{L'が', 11},
	{L'き', 12},
	{L'ぎ', 13},
	{L'く', 14},
	{L'ぐ', 15},
	{L'け', 16},
	{L'げ', 17},
	{L'ご', 18},
	{L'さ', 19},
	{L'ざ', 20},
	{L'し', 21},
	{L'じ', 22},
	{L'ず', 23},
	{L'せ', 24},
	{L'ぜ', 25},
	{L'そ', 26},
	{L'ぞ', 27}
};

std::map<char, wchar_t> hangulTables::hangulMap = {
	{'a', L'け'},
	{'b', L'ば'},
	{'c', L'ず'},
	{'d', L'し'},
	{'e', L'ぇ'},
	{'f', L'ぉ'},
	{'g', L'ぞ'},
	{'h', L'で'},
	{'i', L'ち'},
	{'j', L'っ'},
	{'k', L'た'},
	{'l', L'び'},
	{'m', L'ぱ'},
	{'n', L'ぬ'},
	{'o', L'だ'},
	{'p', L'つ'},
	{'q', L'げ'},
	{'r', L'ぁ'},
	{'s', L'い'},
	{'t', L'さ'},
	{'u', L'づ'},
	{'v', L'そ'},
	{'w', L'じ'},
	{'x', L'ぜ'},
	{'y', L'に'},
	{'z', L'せ'},
	{'A', L'け'},
	{'B', L'ば'},
	{'C', L'ず'},
	{'D', L'し'},
	{'E', L'え'},
	{'F', L'ぉ'},
	{'G', L'ぞ'},
	{'H', L'で'},
	{'I', L'ち'},
	{'J', L'っ'},
	{'K', L'た'},
	{'L', L'び'},
	{'M', L'ぱ'},
	{'N', L'ぬ'},
	{'O', L'ぢ'},
	{'P', L'て'},
	{'Q', L'こ'},
	{'R', L'あ'},
	{'S', L'い'},
	{'T', L'ざ'},
	{'U', L'づ'},
	{'V', L'そ'},
	{'W', L'す'},
	{'X', L'ぜ'},
	{'Y', L'に'},
	{'Z', L'せ'},
};

std::map <wchar_t, std::vector<wchar_t>> hangulTables::combineMap = {
			{L'け', {NULL}},
			{L'ば', {NULL}},
			{L'ず', {NULL}},
			{L'し', {NULL}},
			{L'ぇ', {NULL}},
			{L'ぉ', {L'ぁ',L'け',L'げ',L'さ',L'ぜ',L'そ',L'ぞ'}},
			{L'ぞ', {NULL}},
			{L'で', {L'た',L'だ',L'び'}},
			{L'ち', {NULL}},
			{L'っ', {NULL}},
			{L'た', {NULL}},
			{L'び', {NULL}},
			{L'ぱ', {L'び'}},
			{L'ぬ', {L'っ',L'つ',L'び'}},
			{L'だ', {NULL}},
			{L'つ', {NULL}},
			{L'げ', {NULL,L'さ'}},
			{L'ぁ', {NULL,L'さ'}},
			{L'い', {L'じ',L'ぞ'}},
			{L'さ', {NULL}},
			{L'づ', {NULL}},
			{L'そ', {NULL}},
			{L'じ', {NULL}},
			{L'い', {NULL}},
			{L'に', {NULL}},
			{L'せ', {NULL}}
};

std::map <wchar_t, std::vector<wchar_t>> hangulTables::detachMap = {
			{L'ぁ', {NULL, L'ぁ'}},
			{L'あ', {NULL, L'あ'}},
			{L'い', {NULL, L'い'}},
			{L'ぇ', {NULL, L'ぇ'}},
			{L'ぉ', {NULL, L'ぉ'}},
			{L'け', {NULL, L'け'}},
			{L'げ', {NULL, L'げ'}},
			{L'さ', {NULL, L'さ'}},
			{L'ざ', {NULL, L'ざ'}},
			{L'し', {NULL, L'し'}},
			{L'じ', {NULL, L'じ'}},
			{L'ず', {NULL, L'ず'}},
			{L'せ', {NULL, L'せ'}},
			{L'ぜ', {NULL, L'ぜ'}},
			{L'そ', {NULL, L'そ'}},
			{L'ぞ', {NULL, L'ぞ'}},
			{L'ぃ', {L'ぁ', L'さ'}},
			{L'ぅ', {L'い', L'じ'}},
			{L'う', {L'い', L'ぞ'}},
			{L'お', {L'ぉ', L'ぁ'}},
			{L'か', {L'ぉ', L'け'}},
			{L'が', {L'ぉ', L'げ'}},
			{L'き', {L'ぉ', L'さ'}},
			{L'く', {L'ぉ', L'そ'}},
			{L'ぐ', {L'ぉ', L'ぞ'}},
			{L'ぎ', {L'ぉ', L'ぜ'}},
			{L'ご', {L'げ', L'さ'}}
};