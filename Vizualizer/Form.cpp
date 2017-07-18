#include "stdafx.h"
#include "Form.h"
#include "visUtils.h"

//Form::Form()
//{
//}
//
//Form::~Form()
//{
//}

//void Form::show()
//{
//}

void SetColor1(HANDLE h, Color text, Color background)
{
	SetConsoleTextAttribute(h, (static_cast<WORD>(background) << 4) | static_cast<WORD>(text));
}