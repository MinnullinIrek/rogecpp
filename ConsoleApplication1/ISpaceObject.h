#pragma once
class ISpaceObject 
{
public:
	ISpaceObject();
	~ISpaceObject();

	virtual wchar_t getChar() = 0;
	virtual operator wchar_t() = 0;

};

