#ifndef _UTILITY_H
#define _UTILITY_H
#pragma once

/////////////////////////////////////////////////////////////////////////////

class CStopwatchMS
{
public:
	CStopwatchMS();

	void Reset();
	DWORD GetElapsedTime() const;

private:
	ULONGLONG m_startMS;
};

/////////////////////////////////////////////////////////////////////////////
#endif // _URLWND_H