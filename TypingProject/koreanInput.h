#pragma once
#include <iostream>
#include <locale>
#include <conio.h> // Ű�Է¿� ���� ���
#include <map> // map
#include <vector>


/*
* �ѱ� �Է¿� �ʿ��� �ڵ峪 ������ �� ���·� ������ �����͵�
*/
class hangulTables {
	// �ѱ� ���ڿ� �����Ǵ� �ʼ� �ڵ带 ������ ��
	static std::map<wchar_t, int> choMap;
	// �ѱ� ���ڿ� �����Ǵ� �߼� �ڵ带 ������ ��
	static std::map<wchar_t, int> joongMap;
	// �ѱ� ���ڿ� �����Ǵ� ���� �ڵ带 ������ ��
	static std::map<wchar_t, int> jongMap;
	// �ƽ�Ű �ڵ忡 �����Ǵ� �ѱ� �ڵ带 ������ ��
	static std::map<char, wchar_t> hangulMap;
	// �ۼ躰 ���� ������ ��츦 ���� map, key�� ���� ����, vector���� ���ڵ��� �ش� ���ڿ� ������ ������ �����̴�. 
	// vector�󿡼��� ����+1 �� �����ϸ� ���ձۼ谡 �������
	static std::map <wchar_t, std::vector<wchar_t>> combineMap;
	// �� ���� ���� ���ڿ��� �и��� ������ ���ڵ��� ������ �� EX : �� + �� -> ����
	static std::map <wchar_t, std::vector<wchar_t>> detachMap;

public:
	// �ʿ� �ش� Ű�� �����ϴ� ��ҵ��� �����ϴ��� �˷��ִ� �Լ���
	static bool containHangul(char _code);
	static bool containCho(wchar_t _code);
	static bool containJoong(wchar_t _code);
	static bool containJong(wchar_t _code);
	static bool containCombine(wchar_t _code);
	static bool containDetach(wchar_t _code);
	// Ű�� �ָ� ��Ҹ� �������ִ� �Լ���
	static wchar_t ascii2Hangul(char _code);
	static int hangul2Cho(wchar_t _code);
	static int hangul2Jong(wchar_t _code);
	static int hangul2Joong(wchar_t _code);
	static std::vector<wchar_t> getCombine(wchar_t _code);
	static std::vector<wchar_t> getDetach(wchar_t _code);
};


class hangulChar {
	wchar_t text; // �Է� �Ϸ�� ����
	bool isComplete; // �Է��� �Ϸ�� �������� ���� (�Է��� �Ϸ�� ���ڴ� ����� �ܿ��� ������ �Ұ�������.)
	wchar_t choJoongJong[3]; // �ʼ�,�߼�,������ �����ϴ� �迭
	int cnt; // ���� �Էµ� ������ ���� (0 : ����, 1 : �ʼ�, 2: �ʼ�+�߼�, 3: �ʼ�+�߼�+����
	void combine(); // �Էµ� �ʼ�,�߼�,�������� ���ձ��ڸ� �����Ͽ� text�� �����Ѵ�.
public:
	wchar_t getText(); // ���յ� ���ڸ� �����Ѵ�.
	void setCho(wchar_t); //�ʼ��� �����Ѵ�
	void setJoong(wchar_t); //�߼��� �����Ѵ�
	void setJong(wchar_t); // ������ �����Ѵ�
	wchar_t getCho(); // �ʼ��� �����Ѵ�
	wchar_t getJoong(); // �߼��� �����Ѵ�
	wchar_t getJong(); // ������ �����Ѵ�
	bool getComplete(); // �Է��� �Ϸ�Ǿ������� ��ȯ�Ѵ�.
	void setComplete(); // �Է¿ϷḦ �����Ѵ�
	int erase(); // �ʼ�,�߼�,������ �ϳ��� �����, ������ڰ� �ϳ��� ������ eraseAll�� ȣ���Ų��.
	void eraseAll(); // ��� �����.
	int getCnt(); // ���� �Էµ� ������ ���� �����Ѵ�.
	void copyText(hangulChar); // �Ű����� hangulChar�� ������ ������ �����´�
};


class korInput {
	static bool isKor; // �ѿ�Ű(ALTŰ �����°� �ȵǼ� TabŰ�� ����) �� ���ȴ����� �����ϴ� bool
	static hangulChar* hanguls; // ������ �Ϸ�� �ѱ��� �����ϴ� �迭
	static int hangulCnt; // ������ �Ϸ�� �ѱ��� ����
	static int cursor; // ���ڿ��� ����Ű�� Ŀ��
	const static int maxCount; // �ִ� ���ڿ�
	static void cursorRight(); // Ŀ���� ���������� �ű��.
	static void cursorLeft(); // Ŀ���� �������� �ű��.
	static int combineHangul(wchar_t, int, wchar_t&); // combineMap�� ����Ͽ� �ѱ��� �����Ѵ�.
	static int detachJong(wchar_t); // ������ ������ �Է������� detachMap�� ����Ͽ� �и���Ű��
	static void setCurrCho(wchar_t); // ���� Ŀ���� ����Ű�� �ѱ۹����� �ʼ��� �����Ѵ�.
	static void setCurrJoong(wchar_t); // ���� Ŀ���� ����Ű�� �ѱ۹����� �߼��� �����Ѵ�.
	static void setCurrJong(wchar_t); // ���� Ŀ���� ����Ű�� �ѱ۹����� ������ �����Ѵ�.
	static int insertNextSlot(wchar_t _cho = NULL, wchar_t _joong = NULL, wchar_t _jong = NULL); // Ŀ���� ��ĭ �ű�� ���ο� ���ڸ� ����, �Ű������� �Ѿ�� ��,��,�������� ä���.
	static int chkCombine(int); // �Է¹��� ���ڰ� �ѱ� ������ ���������� üũ�ϰ� �����ϸ� CombineHangul�� ������ ������ �����Ѵ�.
	static int chkDetach(int); // �Է¹��� ���ڿ� �Էµ� ������ �и��� ���������� üũ�ϰ� �����ϸ� detachJong�� ������ �и��� �����Ѵ�.
	static int chkInsert(int); // �ʼ�,�߼�,������ �Է��� �������� Ȯ���Ѵ�.
	static int insertKor(int); // �ѱ��� �Է��� �����Ѵ�.
	static int insertAscii(wchar_t); // �ƽ�Ű�ڵ��� �Է��� �����Ѵ�.
	static int rightShift(); // ���ڵ��� �������� ����Ʈ�Ѵ�.
	static int leftShift(int); // ���ڵ��� �������� ����Ʈ�Ѵ�
	static void eraseCursor(); // �齺���̽� ���
	static void deleteCursor(); // Delete ���
	static bool isKorMode(); // �ѿ� �����ִ��� Ȯ��
	static void altEngKor(); // �ѿ� ��۱��
public:
	static int inputBuffer(int); // ���ۿ� Ű �Է��ϱ�, �̰��� �������·� ȣ���ϴ� ���� Ű�Է��� ���� �� �ִ�.
	static void printBuffer(); // �Էµ� ��� ���ڵ��� ����Ѵ�.
	static void printInfo(); // ����� ���� ȣ��
	static std::wstring getWString(); // �Էµ� �ؽ�Ʈ�� wstring���·� ��ȯ�Ѵ�
	static void eraseTexts();
};

void textcolor(int, int);