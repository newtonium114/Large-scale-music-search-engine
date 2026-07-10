#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H
#include <string>
#include <cctype>

using namespace std;


//Makes searches lowercase and removes extra spaces
//TODO: talvez lidar melhor com acentos depois se o dataset vier meio estranho
inline string normalizeText(string text) {
    string result = "";
    bool lastWasSpace = false;

    for (int i = 0; i < (int)text.size(); i++) {
        unsigned char ch = text[i];

        if (isspace(ch)) {
            if (!result.empty() && !lastWasSpace)
                result += ' ';
            lastWasSpace = true;
        } else {
            result += (char)tolower(ch);
            lastWasSpace = false;
        }
    }

    //Se sobrou espaco no final eu tiro aqui
    if (!result.empty() && result[result.size() - 1] == ' ')
        result.pop_back();

    return result;
}

#endif
