#include "..//Include//UI.h"

/**
 * @brief Xóa màn hình
 */
void clear_screen() 
{
    printf("\033[2J\033[H");
    // fflush(stdout);
    system("cls");
}

/**
 * @brief Đọc trạng thái phím
 */
int get_arrow_key() 
{
    int ch = getch();

    if (ch == 224) 
    {
        ch = getch();

        switch (ch) 
        {
            case 72: return 'U'; // Up
            case 80: return 'D'; // Down
        }
    }
    else if (ch == 13)
    {
        return '\n';
    }

    return 0;
}

/**
 * @brief Hiển thị vị trí đang thao tác
 */
void print_breadcrumb(const char *text)
{
    printf(ANSI_COLOR_CYAN "Bạn đang ở: " ANSI_COLOR_BOLD "%s" ANSI_COLOR_RESET "\n\n", text);
}

/**
 * @brief Hiển thị Menu
 */
int show_menu(const char *breadcrumb, const char *title, const char *choices[], int n)
{
    int current = 0;

    while (1) 
    {
        clear_screen();

        print_breadcrumb(breadcrumb);

        printf(ANSI_COLOR_BOLD "%s\n" ANSI_COLOR_RESET, title);

        for (int i=0; i<n; ++i) 
        {
            if (i == current)
            {
                printf(ANSI_COLOR_YELLOW "> %s <" ANSI_COLOR_RESET "\n", choices[i]);
            }
            else
            {
                printf("  %s\n", choices[i]);
            }
        }

        printf("\n(↑/↓ để di chuyển, Enter để chọn)\n");

        int key = get_arrow_key();

        if (key == 'U') 
        {
            if (current > 0) current--;
        } 
        else if (key == 'D') 
        {
            if (current < n - 1) current++;
        } 
        else if (key == '\n') 
        {
            return current;
        }
    }
}