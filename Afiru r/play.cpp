#include "add.h"
int file_print_normal()
{
    fstream playlist_file;
    playlist_file.open("./playlist.txt", std::ios::out | std::ios::trunc);
    for (int count_c = 0; count_c < counter; count_c++)
    {
        char* y;
        int i = 0;
        int length = title[count_c].length();
        char* pl = (char*)malloc(length * sizeof(char) + 1);
        strcpy(pl, title[count_c].c_str());
        y = pl;
        playlist_file << pl;
        y[i] = '\0';
        playlist_file << y[i] << '\n';
    }
    playlist_file.close();
    return(88);
}
int file_print_shuffle()
{
    fstream playlist_file;
    playlist_file.open("./playlist.txt", std::ios::out | std::ios::trunc);
    random_shuffle(title.begin(), title.end());
    for (int count_c = 0; count_c < counter; count_c++)
    {
        char* y;
        int i = 0;
        int length = title[count_c].length();
        char* pl = (char*)malloc(length * sizeof(char) + 1);
        strcpy(pl, title[count_c].c_str());
        y = pl;
        playlist_file << pl;
        y[i] = '\0';
        playlist_file << y[i] << '\n';
    }
    playlist_file.close();
    return(88);
}

int playya()
{
    cout << counter << endl;
    for (int i = 0; i < counter; i++)
    {
        string str = title[i];
        cout << "now playing : " << title[i] << endl;
        LPSTR cc = const_cast<char*>(str.c_str());;

        sndPlaySound(cc, 0);
    }
    return (55);
}
