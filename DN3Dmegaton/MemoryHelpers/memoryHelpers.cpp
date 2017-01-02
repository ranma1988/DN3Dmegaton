#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>
#include <string>
#include <Psapi.h>

//sources
// http://www.cheatengine.org/forum/viewtopic.php?t=526508&sid=973568657e876839ea70dea3e545df9b
// http://www.cheatengine.org/forum/viewtopic.php?t=415186&sid=913dbca3654d4d2cf44a
namespace memory {

	SIZE_T stBytes = 0;

	void read1Byte(const HANDLE & hProcess, const UINT_PTR &addr, byte &ret) {
		ReadProcessMemory(hProcess, (LPVOID)addr, &ret, 1, &stBytes); 
	}

	void read2Byte(const HANDLE &hProcess, const UINT_PTR &addr, uint16_t &ret) {
		ReadProcessMemory(hProcess, (LPVOID)addr, &ret, 2, &stBytes);
	}

	void read2Byte(const HANDLE &hProcess, const UINT_PTR &addr, int &ret) {
		ReadProcessMemory(hProcess, (LPVOID)addr, &ret, 2, &stBytes);
	}

	void writeByte(const HANDLE &hProcess, const UINT_PTR &addr, byte ret) {
		WriteProcessMemory(hProcess, (LPVOID)addr, &ret, 1, &stBytes);
	}

	void writeBit0(const HANDLE &hProcess, const UINT_PTR &addr, bool onOff) {
		byte ret;
		read1Byte(hProcess, addr, ret);
		if (onOff)	ret = ret | 0b00000001;
		else        ret = ret & 0b11111110;
		writeByte(hProcess, addr, ret);
	}
}