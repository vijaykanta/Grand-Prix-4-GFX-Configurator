#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "resource.h"
#include "wnds.h"
#include "gplib.h"

const char g_szClassName[] = "myWindowClass";
HWND hToolWindow;
char file_name[100];
CFG cfg;

HWND hLabel, hButton;
HWND hListBoxL, hCpuL, hGpuL;
HWND hListBox, hCpu, hGpu;
HWND hTextL;

HWND hGlobalL, hGlobal;
HWND hWidthL, hWidth;
HWND hHeightL, hHeight;
HWND hHWTnlL, hHWTnl;
HWND hWndMdL, hWndMd;
HWND hVSyncL, hVSync;
HWND hTexQL, hTexQ;
HWND hBmpMpL, hBmpMp;
HWND hMrrL, hMrr;
HWND hTrkMpL, hTrkMp;
HWND hEnvMpL, hEnvMp;
HWND hTexFilQL, hTexFilQ;
HWND hAnFilQL, hAnFilQ;
HWND hShdwL, hShdw;
HWND hShdwTpL, hShdwTp;
HWND hExtStrL, hExtStr;
HWND hHtHzL, hHtHz;

HWND hCButton, hSysButton, hLoadButton, hGenButton;
HWND hBkButton, hDefButton;

HFONT hDefault;
HBRUSH g_hbrBackground;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_CREATE:
			{
				//hDefault = GetStockObject(DEFAULT_GUI_FONT);
				memset(file_name, 0, 100);
				strcpy(file_name, "C:\\Program Files (x86)\\Infogrames\\Grand Prix 4\\f1graphics.cfg");
				memset(cfg.file_name, 0, sizeof(cfg.file_name));
				strcpy(cfg.file_name, file_name);
				//read_file(&cfg);
			}
			{
				hDefault = (HFONT) GetStockObject(DEFAULT_GUI_FONT);
			}
			{
				hToolWindow = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_TOOLWINDOW), hwnd, ToolDlgProc);
				if(hToolWindow == NULL) {
					MessageBox(hwnd, "Failed to create tool window!", "Error", MB_ICONERROR | MB_OK);
					return -1;
				}
				ShowWindow(hToolWindow, SW_HIDE);
			}
			/*{
				hLabel = CreateLabel(hwnd, 10, 10, 150, 25, ID_MYLABEL);
			}*/
			
			/**
			* Windows for configuration editing
			* Create windows easily from the wnds.h library
			*
			*/
			{
				hGlobalL = CreateLabel(hwnd, 20, 10, 200, 25, ID_GLOBALL);
				SendMessage(hGlobalL, WM_SETTEXT, 0, (LPARAM) "Global setting");
				SendMessage(hGlobalL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hGlobal = CreateComboBox(hwnd, 20, 50, 200, 200, ID_GLOBAL);
				SendMessage(hGlobal, CB_ADDSTRING, 0, (LPARAM) "Global On");
				SendMessage(hGlobal, CB_SETCURSEL, 0, 0);
				SendMessage(hGlobal, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hWidthL = CreateLabel(hwnd, 260, 10, 200, 25, ID_WIDTHL);
				SendMessage(hWidthL, WM_SETTEXT, 0, (LPARAM) "Horizontal resolution");
				SendMessage(hWidthL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hWidth = CreateComboBox(hwnd, 260, 50, 200, 200, ID_WIDTH);
				SendMessage(hWidth, CB_ADDSTRING, 0, (LPARAM) "1440");
				SendMessage(hWidth, CB_SETCURSEL, 0, 0);
				SendMessage(hWidth, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hHeightL = CreateLabel(hwnd, 500, 10, 200, 25, ID_HEIGHTL);
				SendMessage(hHeightL, WM_SETTEXT, 0, (LPARAM) "Vertical resolution");
				SendMessage(hHeightL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hHeight = CreateComboBox(hwnd, 500, 50, 200, 200, ID_HEIGHT);
				SendMessage(hHeight, CB_ADDSTRING, 0, (LPARAM) "900");
				SendMessage(hHeight, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				SendMessage(hHeight, CB_SETCURSEL, 0, 0);
			}
			/* ROW 1 Ends */

			{
				hHWTnlL = CreateLabel(hwnd, 20, 100, 200, 25, ID_HWTNLL);
				SendMessage(hHWTnlL, WM_SETTEXT, 0, (LPARAM) "Hardware T&L");
				SendMessage(hHWTnlL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hHWTnl = CreateComboBox(hwnd, 20, 140, 200, 200, ID_HWTNL);
				SendMessage(hHWTnl, CB_ADDSTRING, 0, (LPARAM) "Enabled");
				SendMessage(hHWTnl, CB_SETCURSEL, 0, 0);
				SendMessage(hHWTnl, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hWndMdL = CreateLabel(hwnd, 260, 100, 200, 25, ID_WNDMDL);
				SendMessage(hWndMdL, WM_SETTEXT, 0, (LPARAM) "Window mode");
				SendMessage(hWndMdL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hWndMd = CreateComboBox(hwnd, 260, 140, 200, 200, ID_WNDMD);
				SendMessage(hWndMd, CB_ADDSTRING, 0, (LPARAM) "Full screen");
				SendMessage(hWndMd, CB_SETCURSEL, 0, 0);
				SendMessage(hWndMd, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hVSyncL = CreateLabel(hwnd, 500, 100, 200, 25, ID_VSYNCL);
				SendMessage(hVSyncL, WM_SETTEXT, 0, (LPARAM) "Vync display");
				SendMessage(hVSyncL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hVSync = CreateComboBox(hwnd, 500, 140, 200, 200, ID_VSYNC);
				SendMessage(hVSync, CB_ADDSTRING, 0, (LPARAM) "900");
				SendMessage(hVSync, CB_SETCURSEL, 0, 0);
				SendMessage(hVSync, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			/* ROW 2 Ends */

			{
				hTexQL = CreateLabel(hwnd, 20, 190, 200, 25, ID_TEXQL);
				SendMessage(hTexQL, WM_SETTEXT, 0, (LPARAM) "Texture quality");
				SendMessage(hTexQL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hTexQ = CreateComboBox(hwnd, 20, 230, 200, 200, ID_TEXQ);
				SendMessage(hTexQ, CB_ADDSTRING, 0, (LPARAM) "Ultra level");
				SendMessage(hTexQ, CB_SETCURSEL, 0, 0);
				SendMessage(hTexQ, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hBmpMpL = CreateLabel(hwnd, 260, 190, 200, 25, ID_BMPMPL);
				SendMessage(hBmpMpL, WM_SETTEXT, 0, (LPARAM) "Bump mapping");
				SendMessage(hBmpMpL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hBmpMp = CreateComboBox(hwnd, 260, 230, 200, 200, ID_BMPMP);
				SendMessage(hBmpMp, CB_ADDSTRING, 0, (LPARAM) "Lighting");
				SendMessage(hBmpMp, CB_SETCURSEL, 0, 0);
				SendMessage(hBmpMp, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hMrrL = CreateLabel(hwnd, 500, 190, 200, 25, ID_MRRL);
				SendMessage(hMrrL, WM_SETTEXT, 0, (LPARAM) "Mirrors");
				SendMessage(hMrrL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hMrr = CreateComboBox(hwnd, 500, 230, 200, 200, ID_MRR);
				SendMessage(hMrr, CB_ADDSTRING, 0, (LPARAM) "Present");
				SendMessage(hMrr, CB_SETCURSEL, 0, 0);
				SendMessage(hMrr, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			/* ROW 3 Ends */

			{
				hTrkMpL = CreateLabel(hwnd, 20, 280, 200, 25, ID_TRKMPL);
				SendMessage(hTrkMpL, WM_SETTEXT, 0, (LPARAM) "Track maps");
				SendMessage(hTrkMpL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hTrkMp = CreateComboBox(hwnd, 20, 320, 200, 200, ID_TRKMP);
				SendMessage(hTrkMp, CB_ADDSTRING, 0, (LPARAM) "High quality");
				SendMessage(hTrkMp, CB_SETCURSEL, 0, 0);
				SendMessage(hTrkMp, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hEnvMpL = CreateLabel(hwnd, 260, 280, 200, 25, ID_ENVMPL);
				SendMessage(hEnvMpL, WM_SETTEXT, 0, (LPARAM) "Environment mapping");
				SendMessage(hEnvMpL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hEnvMp = CreateComboBox(hwnd, 260, 320, 200, 200, ID_ENVMP);
				SendMessage(hEnvMp, CB_ADDSTRING, 0, (LPARAM) "Enabled");
				SendMessage(hEnvMp, CB_SETCURSEL, 0, 0);
				SendMessage(hEnvMp, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hTexFilQL = CreateLabel(hwnd, 500, 280, 200, 25, ID_TEXFILQL);
				SendMessage(hTexFilQL, WM_SETTEXT, 0, (LPARAM) "Texture Filter Quality");
				SendMessage(hTexFilQL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hTexFilQ = CreateComboBox(hwnd, 500, 320, 200, 200, ID_TEXFILQ);
				SendMessage(hTexFilQ, CB_ADDSTRING, 0, (LPARAM) "Extreme level");
				SendMessage(hTexFilQ, CB_SETCURSEL, 0, 0);
				SendMessage(hTexFilQ, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			/* ROW 4 Ends */

			{
				hAnFilQL = CreateLabel(hwnd, 20, 370, 200, 25, ID_ANFILQL);
				SendMessage(hAnFilQL, WM_SETTEXT, 0, (LPARAM) "Anisotropic filter quality");
				SendMessage(hAnFilQL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hAnFilQ = CreateComboBox(hwnd, 20, 410, 200, 200, ID_ANFILQ);
				SendMessage(hAnFilQ, CB_ADDSTRING, 0, (LPARAM) "Ultra level");
				SendMessage(hAnFilQ, CB_SETCURSEL, 0, 0);
				SendMessage(hAnFilQ, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hShdwL = CreateLabel(hwnd, 260, 370, 200, 25, ID_SHDWL);
				SendMessage(hShdwL, WM_SETTEXT, 0, (LPARAM) "Shadows");
				SendMessage(hShdwL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hShdw = CreateComboBox(hwnd, 260, 410, 200, 200, ID_SHDW);
				SendMessage(hShdw, CB_ADDSTRING, 0, (LPARAM) "Enabled");
				SendMessage(hShdw, CB_SETCURSEL, 0, 0);
				SendMessage(hShdw, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hShdwTpL = CreateLabel(hwnd, 500, 370, 200, 25, ID_SHDWTPL);
				SendMessage(hShdwTpL, WM_SETTEXT, 0, (LPARAM) "Shadow type");
				SendMessage(hShdwTpL, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
				hShdwTp = CreateComboBox(hwnd, 500, 410, 200, 200, ID_SHDWTP);
				SendMessage(hShdwTp, CB_ADDSTRING, 0, (LPARAM) "Dynamic");
				SendMessage(hShdwTp, CB_SETCURSEL, 0, 0);
				SendMessage(hShdwTp, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			/* ROW 5 Ends */

			
			/*{
				hCpuL = CreateLabel(hwnd, 10, 10, 150, 25, ID_MYCPUL);
				SendMessage(hCpuL, WM_SETTEXT, 0, (LPARAM) "CPU type");
				hCpu = CreateComboBox(hwnd, 10, 50, 150, 25, ID_MYCPU);
				SendMessage(hCpu, CB_ADDSTRING, 0, (LPARAM) "AMD");
				SendMessage(hCpu, CB_ADDSTRING, 0, (LPARAM) "Intel");
				SendMessage(hCpu, CB_SETCURSEL, 0, 0);
			}
			{
				hGpuL = CreateLabel(hwnd, 420, 10, 150, 25, ID_MYGPUL);
				SendMessage(hGpuL, WM_SETTEXT, 0, (LPARAM) "GPU type");
				hGpu = CreateComboBox(hwnd, 420, 50, 150, 25, ID_MYGPU);
				SendMessage(hGpu, CB_ADDSTRING, 0, (LPARAM) "NVIDIA");
				SendMessage(hGpu, CB_ADDSTRING, 0, (LPARAM) "ATI/AMD");
				SendMessage(hGpu, CB_SETCURSEL, 1, 0);
			}
			{
				hListBoxL = CreateLabel(hwnd, 10, 100, 300, 25, ID_MYLISTBOXL);
				SendMessage(hListBoxL, WM_SETTEXT, 0, (LPARAM) "Change settings given below:");

				hListBox = CreateListBox(hwnd, 10, 150, 300, 200, ID_MYLISTBOX);
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "Texture Filter Quality");
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "Environment Map");
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "Track Map");
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "Anisotropic Filter Quality");
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "Shadow Type");
				SendMessage(hListBox, LB_SETCURSEL, 0, 0);
			}
			{
				hTextL = CreateLabel(hwnd, 320, 150, 250, 150, ID_MYTEXTL);
				SendMessage(hTextL, WM_SETTEXT, 0, (LPARAM) "Click on each setting to select it and use the 'Change' button below to modify the current setting\n\nNote: Do not go beyond given values.");
			}*/
			

			// Buttons
			{
				hCButton = CreateButton(hwnd, 320, 470, 75, 25, ID_MYCBUTTON);
				SendMessage(hCButton, WM_SETTEXT, 0, (LPARAM) "Change");
				SendMessage(hCButton, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hSysButton = CreateButton(hwnd, 20, 470, 95, 25, ID_MYSYSBUTTON);
				SendMessage(hSysButton, WM_SETTEXT, 0, (LPARAM) "System Info");
				SendMessage(hSysButton, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hLoadButton = CreateButton(hwnd, 320, 470, 75, 25, ID_MYLOADBUTTON);
				SendMessage(hLoadButton, WM_SETTEXT, 0, (LPARAM) "Load file");
				SendMessage(hLoadButton, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hDefButton = CreateButton(hwnd, 400, 470, 75, 25, ID_MYDEFBUTTON);
				SendMessage(hDefButton, WM_SETTEXT, 0, (LPARAM) "Defaults");
				SendMessage(hDefButton, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			{
				hGenButton = CreateButton(hwnd, 480, 470, 95, 25, ID_MYGENBUTTON);
				SendMessage(hGenButton, WM_SETTEXT, 0, (LPARAM) "Generate file");
				SendMessage(hGenButton, WM_SETFONT, (WPARAM) hDefault, MAKELPARAM(0, FALSE));
			}
			/*{
				hButton = CreateButton(hwnd, 10, 50, 80, 25, ID_MYBUTTON);
				SendMessage(hButton, WM_SETTEXT, 0, (LPARAM) "Submit");
			}*/
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case ID_HELP_ABOUT:
					{
						INT_PTR ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
						if(ret == IDOK) {
							MessageBox(hwnd, "Dialog exited with IDOK!", "Notice", MB_ICONINFORMATION | MB_OK);
						} else if(ret == IDCANCEL) {
							MessageBox(hwnd, "Dialog exited with IDCANCEL!", "Notice", MB_ICONINFORMATION | MB_OK);
						} else if(ret == -1) {
							MessageBox(hwnd, "Dialog failed!", "Notice", MB_ICONERROR | MB_OK);
							return -1;
						}
					}
					break;
				case ID_FILE_EXIT:
					SendMessage(hwnd, WM_CLOSE, 0, 0);
					break;
				case ID_TOOLW_SHOW:
					ShowWindow(hToolWindow, SW_SHOW);
					break;
				case ID_TOOLW_HIDE:
					ShowWindow(hToolWindow, SW_HIDE);
					break;
			}
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
			break;
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Failed to register window class!", "Error", MB_ICONEXCLAMATION | MB_OK);
		return -1;
	}

	hwnd = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			g_szClassName,
			"Grand Prix 4 GFX Configurator",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, 750, 600,
			NULL, NULL, hInstance, NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Failed to create window!", "Error", MB_ICONEXCLAMATION | MB_OK);
		return -1;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return Msg.wParam;
}
