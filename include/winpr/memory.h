/**
 * WinPR: Windows Portable Runtime
 * Memory Allocation
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WINPR_CRT_MEMORY_H
#define WINPR_CRT_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winpr/winpr.h>
#include <winpr/wtypes.h>

#ifndef _WIN32

#define CopyMemory					RtlCopyMemory
#define MoveMemory					RtlMoveMemory
#define FillMemory					RtlFillMemory
#define ZeroMemory					RtlZeroMemory

#define RtlCopyMemory(Destination, Source, Length)	memcpy((Destination), (Source), (Length))
#define RtlMoveMemory(Destination, Source, Length)	memmove((Destination), (Source), (Length))
#define RtlFillMemory(Destination, Length, Fill)	memset((Destination), (Fill), (Length))
#define RtlZeroMemory(Destination, Length)		memset((Destination), 0, (Length))

#define HEAP_GENERATE_EXCEPTIONS			0x00000004
#define HEAP_NO_SERIALIZE				0x00000001
#define HEAP_ZERO_MEMORY				0x00000008
#define HEAP_REALLOC_IN_PLACE_ONLY			0x00000010

WINPR_API HANDLE GetProcessHeap(void);
WINPR_API LPVOID HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
WINPR_API LPVOID HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
WINPR_API BOOL HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);

#endif

#endif /* WINPR_CRT_MEMORY_H */
