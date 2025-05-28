#include "UI.h"
#include "config.h"
#include "resident.h"
#include "statistic.h"
#include "csv_utils.h"

extern int login(char *username);

void logout()
{
    printf("Log out successful!\n");
    exit(0);
}

int main()
{
    const char *filename = DATA_FILE;

    MemberNode *head = NULL;

    // Đăng nhập
    char username[21];
    clear_screen();
    printf("Hệ thống quản lý cư dân - Login\n");
    while (!login(username)) printf("Vui lòng thử lại...\n");
    clear_screen();

    // Khởi tạo file CSV nếu chưa có
    createCSVIfNotExist(filename, MEMBER_INFORMATION);

    // Load dữ liệu vào linked list
    head = loadMembersFromCSV(filename);
    if (!head) head = NULL;

    // Cấu hình menu
    const char *main_menu[] = 
    {
        "Thêm cư dân",
        "Xóa cư dân",
        "Sửa thông tin cư dân",
        "Tìm kiếm cư dân",
        "In danh sách cư dân",
        "Sắp xếp và in danh sách",
        "Thống kê cư dân",
        "Đăng xuất"
    };
    int main_menu_len = sizeof(main_menu)/sizeof(main_menu[0]);

    while (1)
    {
        int sel = show_menu("Menu Chính", "MENU CHÍNH", main_menu, main_menu_len);

        clear_screen();

        int changed = 0;

        switch (sel) 
        {
            case 0: // Thêm cư dân
                changed = addMember(&head);
                break;

            case 1: // Xóa cư dân
                changed = deleteMember(&head);
                break;

            case 2: // Sửa thông tin cư dân
                changed = editMember(head);
                break;

            case 3: // Tìm kiếm cư dân
                searchMember(head);
                break;

            case 4: // In danh sách cư dân
                printAllMembers(head);
                break;

            case 5: // Sắp xếp và in danh sách
                sortAndPrintMemberList(&head);
                break;

            case 6: // Thống kê cư dân
                statisticResidentsFromList(head); 
                break;

            case 7: // Đăng xuất
                printf(ANSI_COLOR_GREEN "Đăng xuất thành công!\n" ANSI_COLOR_RESET);

                if (changed || head != NULL)
                {
                    saveMembersToCSV(filename, head);
                }
                
                freeMemberList(head);
                logout();
                break;
                
            default:
                printf(ANSI_COLOR_RED "Lựa chọn không hợp lệ!\n" ANSI_COLOR_RESET);
        }

        // Nếu có thay đổi thì lưu lại file CSV
        if (changed)
        {
            if (saveMembersToCSV(filename, head) != 0)
            {
                printf(ANSI_COLOR_RED "Lỗi ghi dữ liệu xuống file.\n" ANSI_COLOR_RESET);
            }
        }

        printf(ANSI_COLOR_CYAN "Nhấn phím bất kỳ để quay lại menu chính...\n" ANSI_COLOR_RESET);
        getchar(); // Xử lý buffer
        getchar(); 
        clear_screen();
    }

    freeMemberList(head);
    return 0;
}