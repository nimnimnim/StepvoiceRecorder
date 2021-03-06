/*
Stepvoice Recorder
Copyright (C) 2004-2016 Andrey Firsov
*/

#pragma once
#include <sstream>

/////////////////////////////////////////////////////////////////////////////
//Helper class to simplify debugging - variable-to-string conversion, unicode
//or not strings mixing is done automatically by wstringstream.
//Example:  WriteDbg() << L"pi=" << 3.14 << ", result=" << true;

//Note: you can extend WriteDbg to support custom types
//WriteDbg& operator <<(WriteDbg& writer, const Parameter& param); //etc.


class WriteDbg
{
public:
	WriteDbg();
	~WriteDbg();

	template<typename T>
	WriteDbg& operator << (const T& t)
	{
		m_stream << t;
		return *this;
	}

private:
	std::wstringstream m_stream;
};

WriteDbg& operator <<(WriteDbg& writer, CString str);

//typedef WriteDbg DbgWrite;
