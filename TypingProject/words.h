#pragma once
#ifndef __WORDS_H__
#define __WORDS_H__
#include <string>

class Words {
	std::string *wordArr; // �ܾ� �迭
	const int size = 50; // �ܾ����� �ִ� ������	
	int count; // ���� �߰��� �ܾ��� ����
public:
	Words();
	~Words(); // �Ҹ���
	std::string getWord(); // ������ �ܾ� �ϳ� ��ȯ
	int addWord(std::string word); // �ܾ� �߰��ϱ�
	int delWord(int num); // �ܾ� �����ϱ�
	void printWords(); // ��� �ܾ� ����ϱ�
};
#endif