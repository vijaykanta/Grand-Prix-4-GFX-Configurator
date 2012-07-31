INT_PTR CALLBACK ToolDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDC_PRESS:
					MessageBox(hwnd, "You just pressed me!", "Notice", MB_ICONEXCLAMATION | MB_OK);
					break;
				case IDC_OTHER:
					MessageBox(hwnd, "You just clicked me!", "Notice", MB_ICONEXCLAMATION | MB_OK);
					break;
			}
			break;
		default:
			return FALSE;
	}
	return TRUE;
}

INT_PTR CALLBACK AboutDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_INITDIALOG:
			return TRUE;
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
					EndDialog(hwnd, IDOK);
					break;
				case IDCANCEL:
					EndDialog(hwnd, IDCANCEL);
					break;
			}
			break;
		default:
			return FALSE;
			break;
	}
	return TRUE;
}

HWND CreateLabel(HWND parentWnd, int l, int t, int w, int h, int ID_CONTROL) {
	HWND hwnd = NULL;
	hwnd = CreateWindowEx(
			0,
			"STATIC",
			"",
			WS_CHILD | WS_VISIBLE | SS_LEFT,
			l, t, w, h,
			parentWnd, (HMENU) ID_CONTROL, GetModuleHandle(NULL), NULL);

	if(hwnd == NULL) {
		MessageBox(parentWnd, "Failed to create label!", "Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hwnd;
}

HWND CreateEditBox(HWND parentWnd, int l, int t, int w, int h, int ID_CONTROL) {
	HWND hwnd = NULL;
	hwnd = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			"EDIT",
			"",
			WS_CHILD | WS_VISIBLE,
			l, t, w, h,
			parentWnd, (HMENU) ID_CONTROL, GetModuleHandle(NULL), NULL);

	if(hwnd == NULL) {
		MessageBox(parentWnd, "Failed to create edit box!", "Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hwnd;
}

HWND CreateListBox(HWND parentWnd, int l, int t, int w, int h, int ID_CONTROL) {
	HWND hwnd = NULL;
	hwnd = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			"LISTBOX",
			"",
			WS_CHILD | WS_VISIBLE,
			l, t, w, h,
			parentWnd, (HMENU) ID_CONTROL, GetModuleHandle(NULL), NULL);

	if(hwnd == NULL) {
		MessageBox(parentWnd, "Failed to create list box!", "Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hwnd;
}

HWND CreateComboBox(HWND parentWnd, int l, int t, int w, int h, int ID_CONTROL) {
	HWND hwnd = NULL;
	hwnd = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			"COMBOBOX",
			"",
			WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
			l, t, w, h,
			parentWnd, (HMENU) ID_CONTROL, GetModuleHandle(NULL), NULL);

	if(hwnd == NULL) {
		MessageBox(parentWnd, "Failed to create combo box!", "Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hwnd;
}

HWND CreateButton(HWND parentWnd, int l, int t, int w, int h, int ID_CONTROL) {
	HWND hwnd = NULL;
	hwnd = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			"BUTTON",
			"",
			WS_CHILD | WS_VISIBLE,
			l, t, w, h,
			parentWnd, (HMENU) ID_CONTROL, GetModuleHandle(NULL), NULL);

	if(hwnd == NULL) {
		MessageBox(parentWnd, "Failed to create button!", "Error", MB_ICONEXCLAMATION | MB_OK);
	}
	return hwnd;
}

			
