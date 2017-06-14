//
// Created by szymon on 13.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_NCURSESWRAPPER_H
#define THREADSMANAGEMENTSYSTEM_NCURSESWRAPPER_H

#include <string>

#include <ncurses.h>


namespace SystemMonitoring {
    class NcursesWrapper {
    public:

        static void ProgressBar(const size_t row, const size_t col, double progres) {
            const size_t MAX = 40;
            const size_t progresMax = static_cast<size_t>(progres * MAX);

            mvaddch(row, col, '[');
            for (size_t i = 1; i <= MAX; ++i) {
                if (i < progresMax) {
                    mvaddch(row, col + i, '#');
                } else {
                    mvaddch(row, col + i, ' ');
                }
            }
            wchar_t ws[6];
            swprintf(ws, 6, L"%5.1lf", progres * 100.0);
            mvaddwstr(row, col + MAX + 1, ws);
            mvaddch(row, col + MAX + 6, '%');
            mvaddch(row, col + MAX + 7, ']');
            refresh();
        }

        static void TextView(const size_t row, const size_t col, const std::string strName, const std::string strField) {
            std::string name = strName + ": ";
            mvprintw(row, col, name.c_str());
            mvprintw(row, col+name.size()+1, (strField + "     ").c_str() );
            refresh();
        }

        static std::string EnterString(const size_t row, const size_t col, const std::string strName, const size_t  sizeBufoor) {

            char buf [sizeBufoor];
            std::string name = strName + ": ";
            mvprintw(row, col, name.c_str());
            refresh();
            getstr(buf);

            return std::string(buf);
        }


    };
}

#endif //THREADSMANAGEMENTSYSTEM_NCURSESWRAPPER_H
