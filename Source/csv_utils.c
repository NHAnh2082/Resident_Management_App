#include "..//Include//csv_utils.h"

/**
 * @brief Đếm số node trong danh sách liên kết MemberNode.
 * @param head Con trỏ đầu danh sách.
 * @return Số lượng node, 0 nếu danh sách rỗng.
 */
int countMemberNodeList(MemberNode *head)
{
    int count = 0;
    MemberNode *curr = head;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

/**
 * @brief Kiểm tra UID có bị trùng trong linked list.
 * @param head Đầu danh sách.
 * @param uid UID cần kiểm tra.
 * @return 1 nếu trùng, 0 không trùng.
 */
int isDuplicateUIDInList(MemberNode *head, const char *uid)
{
    MemberNode *curr = head;
    while (curr)
    {
        if (strcmp(curr->data.uid, uid) == 0)
            return 1;
        curr = curr->next;
    }
    return 0;
}

/**
 * @brief Load danh sách cư dân từ file CSV thành linked list.
 * @param filename Tên file.
 * @return Đầu danh sách hoặc NULL nếu lỗi.
 */
MemberNode* loadMembersFromCSV(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) return NULL;

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp); // Bỏ qua tiêu đề

    MemberNode *head = NULL, *tail = NULL;

    while (fgets(buffer, sizeof(buffer), fp))
    {
        MemberNode *node = (MemberNode*)malloc(sizeof(MemberNode));
        if (!node) break; // Lỗi cấp phát

        sscanf( buffer, CSV_READ_FORMAT,
                node->data.uid,
                node->data.roomNumber,
                node->data.name,
                node->data.licensePlate);

        node->next = NULL;

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    fclose(fp);
    return head;
}

/**
 * @brief Ghi linked list xuống file CSV.
 * @param filename Tên file.
 * @param head Đầu danh sách linked list.
 * @return 0 nếu thành công, -1 nếu lỗi.
 */
int saveMembersToCSV(const char *filename, MemberNode *head)
{
    FILE *fp = fopen(filename, "w");
    if (!fp) return -1;

    fprintf(fp, "%s\n", MEMBER_INFORMATION);
    MemberNode *curr = head;

    while (curr)
    {
        fprintf(fp, CSV_WRITE_FORMAT,
                curr->data.uid,
                curr->data.roomNumber,
                curr->data.name,
                curr->data.licensePlate);

        curr = curr->next;
    }

    fclose(fp);
    return 0;
}

/**
 * @brief Giải phóng toàn bộ linked list.
 * @param head Đầu danh sách.
 */
void freeMemberList(MemberNode *head)
{
    MemberNode *curr = head;
    while (curr)
    {
        MemberNode *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}

/**
 * Tạo file CSV mới và ghi dòng tiêu đề nếu file chưa tồn tại.
 * @param filename   Tên file CSV dữ liệu.
 * @param header     Chuỗi tiêu đề (ví dụ: MEMBER_INFORMATION).
 */
void createCSVIfNotExist(const char *filename, const char *header)
{
    // Thử mở file để kiểm tra tồn tại
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        // Nếu chưa tồn tại, tạo mới file và ghi tiêu đề
        fp = fopen(filename, "w");
        if (fp)
        {
            // Ghi dòng tiêu đề
            fprintf(fp, "%s\n", header);

            // Đóng file sau khi ghi
            fclose(fp);
        }
    }
    else
    {
        // Nếu file đã tồn tại, chỉ cần đóng lại
        fclose(fp);
    }
}