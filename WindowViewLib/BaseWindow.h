#pragma once

#include <windows.h>
#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ�ļ����ų�����ʹ�õ�����


class BaseWindow
{
public:
	BaseWindow(HINSTANCE hInst, WCHAR* szTitle, WCHAR* szWindowClass);
	virtual ~BaseWindow();

public:
	virtual BOOL InitInstance();
	virtual int run();

protected:
	virtual LRESULT HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual void OnPaint(HDC hdc, PAINTSTRUCT ps) = 0;
	virtual void OnKeyDown(WPARAM key) = 0;
	virtual void OnKeyUp(WPARAM key) = 0;
	virtual void ExitInstance() = 0;

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:
	// ȫ�ֱ���:
	HINSTANCE hInst;									// ��ǰʵ��
	HWND hWnd;											// ��ǰ���ھ��
	WCHAR *szTitle;										// �������ı�
	WCHAR *szWindowClass;								// ����������
};

