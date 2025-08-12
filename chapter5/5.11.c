#include <stdio.h>
#include <stdlib.h>

#define MAX_TABS 100
#define DEFAULT_TAB_WIDTH 8

int tab_stops[MAX_TABS];
int num_tabs = 0;

int is_tab_stop(int pos) {
    if (num_tabs == 0) {
        return (pos % DEFAULT_TAB_WIDTH == 0);
    }
    for (int i = 0; i < num_tabs; i++) {
        if (tab_stops[i] == pos) return 1;
    }
    return 0;
}

void parse_tab_stops(int argc, char *argv[]) {
    for (int i = 1; i < argc && num_tabs < MAX_TABS; i++) {
        int stop = atoi(argv[i]);
        if (stop > 0) {
            tab_stops[num_tabs++] = stop;
        }
    }
}

int main(int argc, char *argv[]) {
    parse_tab_stops(argc, argv);

    int c, pos = 0, space_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            if (is_tab_stop(pos + space_count)) {
                putchar('\t');
                pos += space_count;
                space_count = 0;
            }
        } else {
            for (int i = 0; i < space_count; i++) {
                putchar(' ');
                pos++;
            }
            space_count = 0;

            putchar(c);
            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                do {
                    pos++;
                } while (!is_tab_stop(pos));
            } else {
                pos++;
            }
        }
    }
    return 0;
}
