#include "..//Include//resident.h"
#include "..//Include//csv_utils.h"
#include "..//Include//log.h"

/**
 * @brief Thêm 1 cư dân vào danh sách liên kết (ở cuối).
 * @param head Con trỏ đến con trỏ đầu danh sách.
 * @param member Dữ liệu cư dân cần thêm.
 * @return 1 nếu thành công, 0 nếu lỗi.
 */
int addMemberNode(MemberNode **head, Member member)
{
    MemberNode *newNode = (MemberNode*)malloc(sizeof(MemberNode));
    if (!newNode) return 0; // lỗi cấp phát

    newNode->data = member;
    newNode->next = NULL;

    if (!(*head))
    {
        *head = newNode;
    }
    else
    {
        MemberNode *curr = *head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return 1;
}

/**
 * @brief Xóa cư dân theo UID khỏi danh sách liên kết.
 * @param head Con trỏ đến con trỏ đầu danh sách.
 * @param uid UID cần xóa.
 * @return 1 nếu thành công, 0 nếu không tìm thấy.
 */
int deleteMemberByUID(MemberNode **head, const char *uid)
{
    MemberNode *curr = *head;
    MemberNode *prev = NULL;

    while (curr)
    {
        if (strcmp(curr->data.uid, uid) == 0)
        {
            if (!prev)
                *head = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return 1; // thành công
        }

        prev = curr;
        curr = curr->next;
    }
    return 0; // không tìm thấy
}

/**
 * @brief Sửa thông tin cư dân theo UID.
 * @param head Con trỏ đầu danh sách.
 * @param uid UID cần sửa.
 * @param updated Dữ liệu mới.
 * @return 1 nếu thành công, 0 nếu không tìm thấy.
 */
int editMemberByUID(MemberNode *head, const char *uid, Member updated)
{
    MemberNode *curr = head;
    while (curr)
    {
        if (strcmp(curr->data.uid, uid) == 0)
        {
            curr->data = updated;
            return 1; // thành công
        }
        curr = curr->next;
    }
    return 0; // không tìm thấy
}

/**
 * @brief Tìm cư dân theo UID.
 * @param head Con trỏ đầu danh sách.
 * @param uid UID cần tìm.
 * @return Con trỏ tới node nếu tìm thấy, NULL nếu không.
 */
MemberNode* searchMemberByUID(MemberNode *head, const char *uid)
{
    MemberNode *curr = head;
    while (curr)
    {
        if (strcmp(curr->data.uid, uid) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

/**
 * @brief Tìm cư dân theo tên (trả node đầu tiên phù hợp).
 * @param head Con trỏ đầu danh sách.
 * @param name Tên cần tìm.
 * @return Con trỏ tới node nếu tìm thấy, NULL nếu không.
 */
MemberNode* searchMemberByName(MemberNode *head, const char *name)
{
    MemberNode *curr = head;
    while (curr)
    {
        if (strcmp(curr->data.name, name) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

/**
 * @brief In toàn bộ danh sách cư dân.
 * @param head Con trỏ đầu danh sách.
 */
void printMemberList(MemberNode *head)
{
    printf("\n%-20s | %-10s | %-20s | %-15s\n", "UID", "Room", "Name", "License Plate");
    printf("-------------------------------------------------------------------------------\n");
    MemberNode *curr = head;
    while (curr)
    {
        printf("%-20s | %-10s | %-20s | %-15s\n",
                curr->data.uid,
                curr->data.roomNumber,
                curr->data.name,
                curr->data.licensePlate);

        curr = curr->next;
    }
}

/**
 * @brief Sắp xếp danh sách cư dân theo trường được chọn.
 * @param head Con trỏ đầu danh sách.
 * @param byUID 1: sắp xếp theo UID, 0: theo tên.
 */
void sortMemberList(MemberNode **head, int sortType)
{
    /*
    sortType:
      0 - sắp xếp theo tên phòng (roomNumber)
      1 - sắp xếp theo tên (name)
      2 - sắp xếp theo UID
    */
    if (!head || !(*head)) return;

    int swapped;
    MemberNode *ptr1;
    MemberNode *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr)
        {
            int cmp = 0;
            switch (sortType)
            {
                case 0: // theo phòng
                    cmp = compareString(ptr1->data.roomNumber, ptr1->next->data.roomNumber);
                    break;
                case 1: // theo tên
                    cmp = compareString(ptr1->data.name, ptr1->next->data.name);
                    break;
                case 2: // theo UID
                    cmp = compareString(ptr1->data.uid, ptr1->next->data.uid);
                    break;
                default:
                    cmp = 0; // không sắp xếp nếu không đúng loại
                    break;
            }

            if (cmp > 0)
            {
                Member tmp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tmp;
                swapped = 1;
            }

            ptr1 = ptr1->next;
        }

        lptr = ptr1;
    } while (swapped);
}

/**
 * @brief Thêm cư dân tương tác qua console.
 * @param head Địa chỉ con trỏ đầu danh sách.
 * @return 1 nếu có thay đổi, 0 nếu không.
 */
int addMember(MemberNode **head)
{
    Member member;

    // Hướng dẫn người dùng nhập thông tin
    printf("Nhập thông tin cư dân (UID RoomNumber Name LicensePlate):\n");
    scanf("%20s %10s %50s %20s", member.uid, member.roomNumber, member.name, member.licensePlate);

    // Kiểm tra UID đã tồn tại trong danh sách chưa
    if (searchMemberByUID(*head, member.uid) != NULL)
    {
        printf("UID đã tồn tại, không thể thêm!\n");
        return 0;
    }

    // Nếu không trùng UID thì mở file để ghi thêm thông tin cư dân mới
    if (addMemberNode(head, member))
    {
        // Hiển thị thông báo thêm thành công
        printf("Thêm cư dân thành công!\n");

        // Ghi log thao tác vào file log
        writeAuditLog("ADD", &member, "admin");
        return 1;
    }
    else
    {
        // Hiển thị thông báo thất bại
        printf("Lỗi cấp phát bộ nhớ, thêm thất bại!\n");
        return 0;
    }
}

/**
 * @brief Xóa cư dân tương tác qua console.
 * @param head Địa chỉ con trỏ đầu danh sách.
 * @return 1 nếu có thay đổi, 0 nếu không.
 */
int deleteMember(MemberNode **head)
{
    char uid[21]; // Biến lưu UID nhập từ người dùng

    // nhập UID của cư dân cần xóa
    printf("Nhập UID cư dân cần xóa:\n");
    scanf("%20s", uid);

    // Tìm kiếm thông tin thông qua UID
    MemberNode *toDelete = searchMemberByUID(*head, uid);
    if (!toDelete)
    {
        printf("Không tìm thấy cư dân với UID %s\n", uid);
        return 0;
    }

    // Bắt đầu xóa thông tin
    if (deleteMemberByUID(head, uid))
    {
        // Hiển thị thông báo thêm thành công
        printf("Xóa cư dân thành công!\n");

        // Ghi log thao tác xóa
        writeAuditLog("DELETE", &toDelete->data, "admin");
        return 1;
    }
    else
    {
        printf("Xóa cư dân thất bại!\n");
        return 0;
    }
}

/**
 * @brief Sửa cư dân tương tác qua console.
 * @param head Đầu danh sách.
 * @return 1 nếu có thay đổi, 0 nếu không.
 */
int editMember(MemberNode *head)
{
    // Khai báo biến lưu UID cần chỉnh sửa
    char uid[21];

    // Yêu cầu người dùng nhập UID của cư dân muốn sửa
    printf("Nhập UID cư dân cần sửa:\n");
    scanf("%20s", uid);

    // Tìm index của cư dân cần sửa trong danh sách
    MemberNode *node = searchMemberByUID(head, uid);
    if (!node)
    {
        printf("Không tìm thấy cư dân với UID %s\n", uid);
        return 0;
    }

    Member beforeEdit = node->data;
    Member updated;

    printf("Nhập thông tin mới (UID RoomNumber Name LicensePlate):\n");
    scanf("%20s %10s %50s %20s", updated.uid, updated.roomNumber, updated.name, updated.licensePlate);

    // Nếu đổi UID, kiểm tra UID mới đã tồn tại chưa
    if (strcmp(updated.uid, uid) != 0 && searchMemberByUID(head, updated.uid) != NULL)
    {
        printf("UID mới đã tồn tại, không thể cập nhật!\n");
        return 0;
    }

    // Thực hiện chỉnh sửa thông tin trong file CSV
    if (editMemberByUID(head, uid, updated))
    {
        // Nếu thành công, thông báo
        printf("Cập nhật thành công!\n");

        // Log trạng thái trước khi sửa
        writeAuditLog("EDIT_BEFORE", &beforeEdit, "admin");

        // Log trạng thái sau khi sửa
        writeAuditLog("EDIT_AFTER", &updated, "admin");
        return 1;
    }
    else
    {
        printf("Cập nhật thất bại!\n");
        return 0;
    }
}

/**
 * @brief Tìm kiếm cư dân tương tác qua console.
 * @param head Đầu danh sách.
 */
void searchMember(MemberNode *head)
{
    // Hiển thị menu lựa chọn tìm kiếm
    printf("Tìm kiếm theo:\n");
    PRINT_MENU("ID", "Tên");

    // Nhập lựa chọn tìm kiếm
    int option;
    scanf("%d", &option);

    // Chuỗi lưu khóa tìm kiếm (UID hoặc tên)
    char key[51];
    MemberNode *found = NULL;

    if (option == 1)
    {
        // --- Tìm kiếm theo UID ---
        printf("Nhập UID cần tìm: ");
        scanf("%20s", key);

        // tìm kiếm thông tin theo UID trong danh sách
        found = searchMemberByUID(head, key);
    }
    else if (option == 2)
    {
        // --- Tìm kiếm theo tên ---
        printf("Nhập tên cần tìm: ");
        scanf("%50s", key);

        // Tìm kiếm thông tin theo tên trong danh sách
        found = searchMemberByName(head, key);
    }
    else
    {
        printf("Lựa chọn không hợp lệ.\n");
        return;
    }

    if (found)
    {
        printf("Thông tin cư dân:\nUID: %s\nPhòng: %s\nTên: %s\nBiển số: %s\n",
               found->data.uid, found->data.roomNumber, found->data.name, found->data.licensePlate);
    }
    else
    {
        printf("Không tìm thấy cư dân phù hợp.\n");
    }
}

/**
 * @brief In toàn bộ danh sách cư dân.
 * @param head Đầu danh sách.
 */
void printAllMembers(MemberNode *head)
{
    if (!head)
    {
        printf("Danh sách cư dân trống.\n");
        return;
    }
    printMemberList(head);
}

/**
 * @brief Sắp xếp và in danh sách cư dân tương tác.
 * @param head Địa chỉ con trỏ đầu danh sách.
 */
void sortAndPrintMemberList(MemberNode **head)
{
    if (!head || !*head)
    {
        printf("Danh sách cư dân trống.\n");
        return;
    }

    int option;

    // Hiển thị menu lựa chọn tiêu chí để sắp xếp
input:
    printf("\nSắp xếp theo:\n");
    PRINT_MENU("Phòng", "Tên", "UID");

    // Nhập lựa chọn sắp xếp
    printf("Chọn: ");
    scanf("%d", &option);

    // Sắp xếp theo tiêu chí người dùng chọn
    switch (option)
    {
        case 1:
            // sắp xếp theo tên phòng 
            sortMemberList(head, 0);
            break;

        case 2:
            // sắp xếp theo tên 
            sortMemberList(head, 0);
            break;

        case 3:
            // sắp xếp theo UID
            sortMemberList(head, 1);
            break;

        default:
            printf("Lựa chọn không hợp lệ.\n");
            return;
    }

    // In danh sách cư dân đã sắp xếp
    printMemberList(*head);

    printf("    - Tiếp tục sắp xếp (1: tiếp tục, 0: thoát)\n");
    printf("    - Nhập lựa chọn: ");
    scanf("%d", &option);

    if (option == 1)
        goto input;
}