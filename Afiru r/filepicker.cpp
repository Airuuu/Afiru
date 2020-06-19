#include "add.h"
int filepicker(int nof)
{
    OPENFILENAME ofn;
    ::memset(&ofn, 0, sizeof(ofn));
    char f1[MAX_PATH];
    f1[0] = 0;
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrTitle = (LPCSTR)"Select A WAV  Files (press cancel to end)";
    ofn.lpstrFilter = (LPCSTR)"Wav files\0*.wav\0";
    ofn.nFilterIndex = 2;
    ofn.lpstrFile = (LPSTR)f1;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST;
    ofn.nFileOffset = OFN_EXPLORER;

    while (::GetOpenFileName(&ofn) != FALSE)
    {
        title.push_back(getFileName(ofn.lpstrFile));
        //noe.push_back(nof);
        //path.push_back(ofn.lpstrFile);
        nof++;
    }
    if (nof <= 1)
    {
        exit(80085);
    }
    counter += nof - 1;
    return (counter);
}