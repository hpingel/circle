//
// miniorgan.h
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2017  R. Stange <rsta2@o2online.de>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#ifndef _miniorgan_h
#define _miniorgan_h

#include <circle/pwmsounddevice2.h>
#include <circle/interrupt.h>
#include <circle/types.h>

struct TNoteInfo
{
	char	Key;
	float	Frequency;
};

class CMiniOrgan : public CPWMSoundDevice2
{
public:
	CMiniOrgan (CInterruptSystem *pInterrupt);
	~CMiniOrgan (void);

	boolean Initialize (void);

	unsigned GetChunk (u32 *pBuffer, unsigned nChunkSize);

private:
	static void KeyStatusHandlerRaw (unsigned char ucModifiers, const unsigned char RawKeys[6]);

private:
	unsigned m_nHighLevel;
	unsigned m_nCurrentLevel;
	unsigned m_nSampleCount;
	unsigned m_nFrequency;		// 0 if no key pressed
	unsigned m_nPrevFrequency;

	static TNoteInfo s_Keys[];

	static CMiniOrgan *s_pThis;
};

#endif
