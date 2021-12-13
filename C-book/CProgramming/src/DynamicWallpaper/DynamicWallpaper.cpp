#include <windows.h>
#include <stdio.h>

BOOL CALLBACK EnumWindowsProc(_In_ HWND hwnd, _In_ LPARAM Lparam)
{
  HWND hDefView = FindWindowEx(hwnd, 0, L"SHELLDLL_DefView", 0);
  if (hDefView != 0)
  {
    // ��������һ�����n�����ΪWorkerW, �Iˇ��
    HWND hWorkerw = FindWindowEx(0, hwnd, L"WorkerW", 0);
    ShowWindow(hWorkerw, SW_HIDE);

    return FALSE;
  }
  return TRUE;
}

int main(int argc, char const *argv[])
{
  LPCWSTR lpParameter = L" F:\\chenglong-C\\C-book\\CProgramming\\src\\DynamicWallpaper\\videow.mp4 -noborder -x 1920 -y 1080 -loop 0";
  STARTUPINFO si { 0 };
  PROCESS_INFORMATION pi { 0 };
  if(CreateProcess(L"F:\\chenglong-C\\C-book\\CProgramming\\src\\DynamicWallpaper\\ffplay.exe", (LPWSTR)lpParameter,0,0,0,0,0,0, &si,&pi))
  {
    Sleep(200);

    HWND hProgman = FindWindow(L"Progman", 0);
    SendMessageTimeout(hProgman, 0x52c,0,0,0,100,0);
    HWND XmpStart = FindWindow(L"SDL_app", 0);
    SetParent(XmpStart, hProgman);
    EnumWindows(EnumWindowsProc, 0);
  }
  return 0;
}
