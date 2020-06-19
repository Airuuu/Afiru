#include "add.h"


using namespace std;
using std::wstring;

vector <string> title;
vector <int> noe;


string* used_title;
char* tmp_char_title;
int n;


//vector <LPSTR> path;
vector <string> filetype;

int counter = 0;
int rewrite()
{  
        int i = 0;
        used_title = new string[title.size()];
        for (i; i < counter; i++)
        {
            int length = title[i].length();
            tmp_char_title = (char*)malloc(length * sizeof(char*));
            strcpy(tmp_char_title, title[i].c_str());
            used_title[i] = tmp_char_title;
            free(tmp_char_title);
        }
    return 69;
}

string getFileName(const string& s) {

    char sep = '/';

#ifdef _WIN32
    sep = '\\';
#endif
    size_t i = s.rfind(sep, s.length());
    if (i != string::npos) {
        return(s.substr(i + 1, s.length() - i));
    }
    return("");
}

string find_extension(const string& s)
{
    string find = s;
    string extension = find.substr(find.find_last_of(".") + 1);
    filetype.push_back(extension);
   //cout << extension;
    return ("");
}

int filepicker(int nof)
{
    OPENFILENAME ofn;
    ::memset(&ofn, 0, sizeof(ofn));
    char f1[MAX_PATH];
    f1[0] = 0;
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrTitle = (LPCSTR)"Select A WAV  Files (press cancel to end)";
    ofn.lpstrFilter = (LPCSTR)"Wav files\0*.wav\0 MP3 files\0*.mp3";
    ofn.nFilterIndex = 2;
    ofn.lpstrFile = (LPSTR)f1;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST;
    ofn.nFileOffset = OFN_ALLOWMULTISELECT | OFN_EXPLORER;
    int counter_t = 0;
    while (::GetOpenFileName(&ofn) != FALSE)
    {
        title.push_back(getFileName(ofn.lpstrFile));
        noe.push_back(nof);
        find_extension(ofn.lpstrFile);
        //path.push_back(ofn.lpstrFile);
        nof++;
    }
    if (nof <= 1)
    {
        delete[] used_title;
        exit(80085);
    }
    counter += nof - 1;
    return (counter);
}
int filepick_playlist()
{
    OPENFILENAME ofn;
    ::memset(&ofn, 0, sizeof(ofn));
    char f1[MAX_PATH];
    f1[0] = 0;
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrTitle = (LPCSTR)"Wybierz playliste (txt)";
    ofn.lpstrFilter = (LPCSTR)"TXT files\0*.txt\0";
    ofn.nFilterIndex = 2;
    ofn.lpstrFile = (LPSTR)f1;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST;
    ofn.nFileOffset = OFN_EXPLORER;
    if (::GetOpenFileName(&ofn) != FALSE)
    {
        int noff = 0;
        ifstream playlist_open;
        playlist_open.open(f1);
        if (playlist_open.is_open())
        {
            string push;
            while (getline(playlist_open, push))
            {
                title.push_back(push);
                noe.push_back(noff + 1);
                find_extension(push);
                noff++;
                counter++;
            }
            playlist_open.close();
        }
        else
        {
            cout << "NIE WYBRANO PLAYLISTY \n";
            delete[] used_title;
            exit(EXIT_FAILURE);// code 1 - failure
        }
    }
    else
    {
        delete[] used_title;
        exit(80085);
    }
    return (22);
}
string transform()
{
    for (unsigned int i = 0; i < filetype.size(); i++)
    {
        string tmp = filetype[i];
        int j = 0;
        while (tmp[j])
        {
            tmp[j] = tolower(tmp[j]);
            j++;
        }
        filetype[i] = tmp;
    }
    return (".");
}

int add()
{
    filepicker(1);
    fstream playlist_file;
    playlist_file.open("./playlist.txt", std::ios::out | std::ios::trunc);
    for (int count_c = 0; count_c < counter; count_c++)
    {
        playlist_file << title[count_c] << '\n';
    }
    playlist_file.close();

    return(128);
}
int menu() {
    int nof = 1;
    int option;
    cout << " choose playstyle : \n 1) As picked \n 2) Shuffle \n 3) Just lemmie pick a txt playlist \n 4) Add to playlist \n Choose : ";
    while (!(cin >> option) && (option != 1 || option != 2 || option != 3 || option != 4 || option !=0) || option > 4 || option < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "insert correct option \n";
        cout << " choose playstyle : \n 1) As picked \n 2) Shuffle \n 3) Just lemmie pick a txt playlist \n 4) Add to playlist \n Choose : ";
    }
    switch (option)
    {
    case 1:
        filepicker(nof);
        transform();
        rewrite();
        file_print_normal();
        playya();
        yn_opt();
        EXIT_FAILURE; // failuje jezeli yn_opt nie pyknie
    case 2:
        filepicker(nof);
        transform();
        file_print_shuffle();
        playya();
        yn_opt();
        EXIT_FAILURE; // failuje jezeli yn_opt nie pyknie
    case 3:
        filepick_playlist();
        break;
    case 4:
        filepick_playlist();
        add();
        yn_opt();
        EXIT_FAILURE; // failuje jezeli yn_opt nie pyknie
    case 0:
        exit(999);
    }
    if (option == 3)
    {
        int option2;
        cout << "\n what u gonna do now? \n choose playstyle : \n 1) As picked \n 2) Shuffle \n 3) From selected song \n Choose : ";
        while (!(cin >> option2) && (option2 != 1 || option2 != 2 || option2 != 3) || option2 > 3 || option2 <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "insert correct option \n";
            cout << "\n what u gonna do now? \n choose playstyle : \n 1) As picked \n 2) Shuffle \n 3) Selected song (loop pick) \n Choose : ";
        }
        switch (option2)
        {
        case 1:
            file_print_normal_vec();
            transform();
            playya_pic();
            yn_opt();
            EXIT_FAILURE; // failuje jezeli yn_opt nie pyknie
        case 2:
            file_print_shuffle();
            transform();
            playya_pic();
            yn_opt();
            EXIT_FAILURE; // failuje jezeli yn_opt nie pyknie
        case 3:
            int stopper = 0;
            do
            {
                playya_selected();

            } while (stopper != 0);
            yn_opt();
            EXIT_FAILURE; // failuje jezeli yn_opt nie pyknie
        }

    }
    return 999;
}

int main(int argc, char* argv[])
{
    waveOutSetVolume(NULL, 0xFFFF);    
    menu();
    /*cout << "now playing (random song from picked from user's choose):" << title[random];

    string str = title[random];
    LPSTR cc = const_cast<char*>(str.c_str());;

    sndPlaySound(cc, 0);*/
    return 88;
}