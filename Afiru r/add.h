#ifndef ADD_H
#define ADD_H

#include <iostream>
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "shlobj.h"
#include <string>
#include <commdlg.h>
#include <stdlib.h>
#include <time.h>
#include <mciapi.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <limits>
#include <ctype.h>
#include <math.h>
#include <tchar.h>
#include <direct.h>
#include <algorithm>
#include <filesystem>
#include <memory>

using namespace std;

extern string* used_title;
extern char* tmp_char_title;
extern int counter;
extern vector <string> title;
extern vector <int> noe;
extern vector <string> filetype;
extern int file;
extern int counter_ps;
extern int stopper;

int rewrite();
int file_print_normal_vec();
int playya_pic();
int playya_selected();
int file_print_normal();
int file_print_shuffle();
int playya();
int playya_loop_pick();
int menu();
int yn_opt();
int vector_cleanin();

#endif