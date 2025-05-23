// TCotU.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "TCotU.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <direct.h>

#define MAX_LOADSTRING 100
using namespace std;

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TCOTU, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TCOTU));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDI_ICON1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
INT_PTR CALLBACK dg(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1| MB_SERVICE_NOTIFICATION), hWnd, dg);

        DestroyWindow(hWnd);

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
/*INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;*/
INT_PTR CALLBACK dg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_INITDIALOG:

    case WM_COMMAND:

        switch (int id = LOWORD(wParam)) {
        case IDC_BUTTON4:
            MessageBox(0, L"Please subscribe, like my work on the Steam Workshop and subscribe to my channel \"Nekit Forever\". I would really appreciate your support.", L"A little attention", MB_HELP| MB_ICONINFORMATION | MB_SETFOREGROUND);
            system("explorer https://clck.ru/3FEvcR");
            system("explorer https://clck.ru/3FEvdF");
            system("explorer https://clck.ru/3FEvsj");
            system("explorer https://clck.ru/3EzXDS");
            break;
        case IDC_BUTTON2:
            _mkdir("localization");
            _mkdir("resource");
            _mkdir("resource/entity");
            _mkdir("resource/entity/humanskin");
            _mkdir("resource/interface");
            _mkdir("resource/set");
            _mkdir("resource/interface/scene");
            _mkdir("resource/interface/scene/portrait");
            _mkdir("resource/set/breed");


            break;
        case IDC_BUTTON1:
            MessageBox(0, L"Unit Creator is designed for instant assembly of units. \nThe program creates files such as skin for the unit, brides, portrait of the unit and ready localization. How to work in the program?\n First of all, if you do not have a file structure for creating units, then click the appropriate button to create it, otherwise the unit will not assemble.\n The name of the breed from the set folder is entered in the \"name unit\" field. to create a \"breed\", I recommend using the \"Breed editor\" program. In the \"humanskin\" field, the humanskin you need fits in, in the \"res\" folder there is a file \"temp.dds\" this is actually the texture of the unit itself, edit it at your discretion and save it after which the humanskin will be assembled.\n The \"unit folder\" field contains the name of the folder for the units that is used in localization and \"breed\". In the \"portrait\" field, the name of the portrait is indicated, in the \"res\" folder there is a file \"temp.tga\" this is the portrait of the unit, edit it at your discretion.\n In the \"localization\" field, the name of the unit for localization is indicated, next to the field there are two checkboxes - these are \"create struct\" and \"end\". We turn on the first one when creating the localization file for the first time, the second one is turned on when working with localization files is finished so that localization works successfully.\n When everything is ready, click the \"Collect unit\" button, congratulations your unit has been successfully assembled!", L"Help", MB_OK | MB_ICONWARNING | MB_SETFOREGROUND);
            break;
        case IDC_BUTTON3:

            char k1[100];
            char k2[100];
            char k3[100];
            char k4[100];
            char k5[100];
            GetDlgItemTextA(hDlg, IDC_EDIT1, k1, 100);
            SetDlgItemTextA(hDlg, IDC_EDIT1, k1);
            GetDlgItemTextA(hDlg, IDC_EDIT2, k2, 100);
            SetDlgItemTextA(hDlg, IDC_EDIT2, k2);
            GetDlgItemTextA(hDlg, IDC_EDIT3, k3, 100);
            SetDlgItemTextA(hDlg, IDC_EDIT3, k3);
            GetDlgItemTextA(hDlg, IDC_EDIT4, k4, 100);
            SetDlgItemTextA(hDlg, IDC_EDIT4, k4);
            GetDlgItemTextA(hDlg, IDC_EDIT5, k5, 100);
            SetDlgItemTextA(hDlg, IDC_EDIT5, k5);
            ofstream j("res/backup.for");
            j << "15.12.24 debug ver \nName unit ->\n" << k1;
            j << "\nUnit folder ->\n" << k2;
            j << "\nhumanskin ->\n" << k3;
            j << "\nPortrait ->\n" << k4;
            j << "\nlocalization ->\n" << k5;
            j.close();

            string h[15];
            fstream j1("res/backup.for");
            for (int i = 0;i <= 15;i++) {
                getline(j1, h[i]);
            }
            j1.close();
            string com_s = "copy res\\temp.tga resource\\interface\\scene\\portrait\\"+h[8]+".tga";
            char com[300];
            char com1[300];
            strcpy_s(com, com_s.c_str());
            system(com);
            strcpy_s(com1, h[6].c_str());
//            char fol = "resource/entity/humanskin"+com1[0];

//            resource / entity / humanskin
            string fol_s = "resource/entity/" + h[6];
            char fol[300];
            strcpy_s(fol, fol_s.c_str());
            _mkdir(fol);
           

            string com_s1 = "copy res\\temp.dds resource\\entity\\"+h[6]+"\\"+ h[6] + ".dds";
            char fol1[300];
            strcpy_s(fol1, com_s1.c_str());
            system(fol1);

            string com_s2 = "copy res\\sn\\skin.ply resource\\entity\\" + h[6] + "\\skin.ply";
            char fol2[300];
            strcpy_s(fol2, com_s2.c_str());
            system(fol2);

            string com_s3 = "copy res\\sn\\anim.txt resource\\entity\\" + h[6] + "\\anim.txt";
            char fol3[300];
            strcpy_s(fol3, com_s3.c_str());
            system(fol3);

            string com_s4 = "copy res\\sn\\temp.mdl resource\\entity\\" + h[6] + "\\"+h[6]+".mdl";
            char fol4[300];
            strcpy_s(fol4, com_s4.c_str());
            system(fol4);

//            material#1.mtl
            string ma = "resource/entity/" + h[6] + "/material#1.mtl";
            char fol5[300];
            strcpy_s(fol5, ma.c_str());
            ofstream mat(ma);
            mat << "{material bump\n";
            mat << "	{diffuse \""+h[6]+"\"}\n";
            mat << "	{color \"229 229 229 25\"}\n";
            mat << "	{blend none}\n";
            mat << "	{tile}\n";
            mat << "}\n";
            mat.close();
            string ma1 = "resource/entity/" + h[6] + +"/"+h[6]+".def";
            char fol6[300];
            strcpy_s(fol6, ma1.c_str());
            ofstream mat1(ma1);
            mat1 << "{game_entity\n";
            mat1 << "	{Extension \""+h[6]+".mdl\"}\n";
            mat1 << "	{tag \""+h[6]+"\"}\n";
            mat1 << "	{RimLight}\n";
            mat1 << "}";
            mat1.close();






            string fol_sx = "resource/set/breed/" + h[4];
            char folx[300];
            strcpy_s(folx, fol_sx.c_str());
            _mkdir(folx);


            string com_s8 = "copy set\\" + h[2] + ".set resource\\set\\breed\\" + h[4] + "\\"+h[2]+".set";
            char fol8[300];
            strcpy_s(fol8, com_s8.c_str());
            system(fol8);

            //;power by Unit Creator
            string info = "resource/set/breed/" + h[4] + "/" + h[2] + ".set";
            ofstream xk(info, ios::app);
            //xk << ";power by Unit Creator(by NFor 2025)\n";
            xk.close();

            ofstream deb("res/debug.txt");
            deb << ma << endl;
            deb << ma1 << endl;
            deb << fol_sx << endl;
            deb << com_s8 << endl;
            deb << com_s << endl;
            deb << fol_s << endl;

            int uCheck = IsDlgButtonChecked(hDlg, IDC_CHECK1);
            int uCheck1 = IsDlgButtonChecked(hDlg, IDC_CHECK2);

            if (uCheck1 == BST_CHECKED) {
                deb << "button-\"Create scruct\" is work\n";
                ofstream loc("localization/desc.lng");
                loc << "{tags\n";
                loc << "\t{\"human\"\n";
                loc << "\t\t{\"" + h[4] + "\"\n";
                loc << "\t\t\t{\"" + h[2] + "\" \"" + h[10] + "\"}\n";
                loc.close();
            }
            if (uCheck1 == BST_UNCHECKED) {
                ofstream loc("localization/desc.lng",ios::app);
                deb << "button-\"Create scruct\" no work\n";
                loc << "\t\t\t{\"" + h[2] + "\" \"" + h[10] + "\"}\n";
                loc.close();
            }

            if (uCheck == BST_CHECKED) {
                deb << "button - \"End\" is work\n";
                ofstream loc("localization/desc.lng", ios::app);
                loc << "\t\t}\n";
                loc << "\t}\n";
                loc << "}\n";
                loc.close();
            }
            if (uCheck == BST_UNCHECKED) {
                deb << "button- \"End\" no work\n";

            }/*

             ofstream loc("localization/desc.lng");
            loc << "{tags\n";
            loc << "\t{\"human\"\n";
            loc << "\t\t{\""+ h[4]+"\"\n";
            loc << "\t\t\t{\""+h[2]+"\" \""+h[10]+"\"}\n";
            /*loc << "\t\t}\n";
            loc << "\t}\n";
            loc << "}\n";*/

            deb.close();
}

        /*l << k1;
        string k2;
    */

        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
