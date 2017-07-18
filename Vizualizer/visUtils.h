#pragma once
#include <string>
#include <Windows.h>

//GetConsoleScreenBufferInfo	Извлекает размер окна, размер экранного буфера и атрибуты цвета.
//SetConsoleWindowInfo	Изменяет размер окна консоли.
//SetConsoleScreenBufferSize	Изменяет размер экранного буфера консоли.
//SetConsoleTextAttribute	Устанавливает атрибуты цвета.
//SetConsoleTitle	Устанавливает заголовок окна.
//GetConsoleTitle	Извлекает заголовок окна консоли.
//GetStdHandle
//CreateConsoleScreenBuffer
//SetConsoleActiveScreenBuffer
//CloseHandle
//KEY_EVENT_RECORD

static LPDWORD d = new DWORD;

struct Region
{
	short col1, row1, col2, row2;
};

enum class Color {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(HANDLE h, Color text, Color background)
{
	SetConsoleTextAttribute(h, (static_cast<WORD>(background) << 4) | static_cast<WORD>(text));
}

inline auto createBuffer() -> HANDLE
{
	return CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr );
}

inline void setActiveBuffer(HANDLE h)
{
	SetConsoleActiveScreenBuffer(h);
}

inline void putChar(HANDLE h, COORD &coord , const std::wstring& ch, Color color, Color bkcolor)
{
	//SetConsoleCursorPosition(h, coord);
	
	SetColor(h, color, bkcolor);
	WriteConsoleOutputCharacter(h, ch.c_str(), ch.length(), coord, d);
}

inline void clearRect(HANDLE h, const Region &r, wchar_t empty)
{
	std::wstring ws(r.col2 - r.col1 + 1, empty);
	for (auto irow = r.row1; irow <= r.row2; irow++)
		WriteConsoleOutputCharacter(h, ws.c_str(), ws.length(), COORD{r.col1, irow}, d);
}

inline void putTextToRegion(HANDLE h, const Region &r, const std::wstring &str)
{
	size_t delta = r.col2 - r.col1 + 1;
	size_t current =  0;
	auto len = str.length();

	for (auto irow = r.row1; irow <= r.row2 && current <= str.length(); irow++) {

		WriteConsoleOutputCharacter(h, str.c_str() + current, min(len - current, delta), COORD{ r.col1, irow }, d);
		current += delta;
	}
}


inline void prepareConsole(HANDLE h)
{
	CONSOLE_CURSOR_INFO info{ 1, false };
	SetConsoleCursorInfo(h, &info);
}

inline void printRegion(HANDLE h, const Region &r, Color col, Color bkColor)
{
	putChar(h, COORD{ r.col1, r.row1 }, std::wstring(r.col2 - r.col1, '-'), col, bkColor);
	putChar(h, COORD{ r.col1, r.row2 }, std::wstring(r.col2 - r.col1, '-'), col, bkColor);

	for (auto irow = r.row1; irow < r.row2; irow++) {
		putChar(h, COORD{ r.col1, irow }, L"|", col, bkColor);
		putChar(h, COORD{ r.col2, irow }, L"|", col, bkColor);
	}
}

inline void putChar(HANDLE h, COORD &coord, wchar_t ch, Color color, Color bkcolor)
{
	SetColor(h, color, bkcolor);
	WriteConsoleOutputCharacter(h, &ch, 1, coord, d);
}
