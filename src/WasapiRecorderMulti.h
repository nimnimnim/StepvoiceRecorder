#ifndef WASAPI_RECORDER_MULTI_H
#define WASAPI_RECORDER_MULTI_H
#pragma once

#include "Filter.h"
#include "WasapiHelpers.h" //for a DevicesArray
#include "SyncObjects.h"

class CWasapiRecorderStream;

/////////////////////////////////////////////////////////////////////////////

class CWasapiRecorderMulti : public Filter
{
public:
	CWasapiRecorderMulti(WasapiHelpers::DevicesArray devices, DWORD freq, DWORD chans);
	virtual ~CWasapiRecorderMulti();

	DWORD GetActualFrequency() const;
	DWORD GetActualChannelCount() const;

	BOOL Start();
	BOOL Pause();
	BOOL Stop();

	float GetVolume() const;
	BOOL  SetVolume(float volume); //0..1

	float GetPeakLevel(int channel) const; //0 = first channel, -1 = all channels
	DWORD GetData(void* buffer, DWORD lengthBytes) const; //returns -1 if error

	//For compatibility with GraphWnd callback
	DWORD GetChannelData(int channel, float* buffer, int bufferSize);

private:
	static void CALLBACK TimerCallback(PVOID lpParameter, BOOLEAN TimerOrWaitFired);

	std::vector<CWasapiRecorderStream*> m_recorderStreams;
	//static DWORD CALLBACK OutputProc(void* buffer, DWORD lengthBytes, void* user);
	//virtual bool ProcessData(void* buffer, DWORD lengthBytes); //overridden

	DWORD m_actualFreq;
	DWORD m_actualChans;

	typedef DWORD HSTREAM; //Sample stream handle (from bass.h).
	HSTREAM m_mixerStream;

	HANDLE m_hTimer;
	CMyCriticalSection m_sync_object;
};

/////////////////////////////////////////////////////////////////////////////

#endif // WASAPI_RECORDER_MULTI_H