#ifndef __WORDS_H__
#define __WORDS_H__
#include <string>

#define MAXWORDLENGTH 30;

class Words {
	std::wstring *wordArr; // �ܾ� �迭
	const int size = 50; // �ܾ����� �ִ� ������	
	int count; // ���� �߰��� �ܾ��� ����
public:
	Words();
	~Words(); // �Ҹ���
	std::wstring getWord(); // ������ �ܾ� �ϳ� ��ȯ
	int addWord(std::wstring word); // �ܾ� �߰��ϱ�
	int delWord(int num); // �ܾ� �����ϱ�
	void printWords(); // ��� �ܾ� ����ϱ�
};
#endif