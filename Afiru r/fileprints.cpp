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
        char* file = (char*)malloc(length * sizeof(char) + 1);
        strcpy(file, title[count_c].c_str());
        y = file;
        playlist_file << file;
        y[i] = '\0';
        playlist_file << y[i] << '\n';
        free(file);
    }
    playlist_file.close();
    return(88);
}
int file_print_normal_vec()
{
    fstream playlist_file;
    playlist_file.open("./playlist.txt", std::ios::out | std::ios::trunc);
    for (int count_c = 0; count_c < counter; count_c++)
    {
        char* y;
        int i = 0;
        int length = title[count_c].length();
        char* file = (char*)malloc(length * sizeof(char));
        strcpy(file, title[count_c].c_str());
        y = file;
        playlist_file << file;
        y[i] = '\0';
        playlist_file << y[i] << '\n';
        free(file);
    }
    playlist_file.close();
    return(88);
}
int file_print_shuffle()
{
    fstream playlist_file;
    playlist_file.open("./playlist.txt", std::ios::out | std::ios::trunc);
    random_shuffle(title.begin(), title.end());
    rewrite();
    for (int count_c = 0; count_c < counter; count_c++)
    {
        char* y;
        int i = 0;
        int length = title[count_c].length();
        char* file = (char*)malloc(length * sizeof(char) + 1);
        strcpy(file, title[count_c].c_str());
        y = file;
        playlist_file << file;
        y[i] = '\0';
        playlist_file << y[i] << '\n';
        free(file);
    }
    playlist_file.close();
    return(88);
}
