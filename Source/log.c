#include "..//Include//log.h"

/**
 * @brief Ghi log thao tác vào file audit log.
 * @param action   Chuỗi hành động ("ADD", "EDIT"...)
 * @param member   Con trỏ Member thực hiện thao tác.
 * @param username Tên người dùng thao tác.
 */
void writeAuditLog(const char *action, const Member *member, const char *username)
{
    char timestr[32];
    getCurrentTimeStr(timestr, sizeof(timestr));

    FILE *log = fopen(AUDIT_LOG_FILE, "a");
    if (!log) return; // Không báo lỗi ra ngoài, tránh crash

    // Có thể ghi nhiều trường hơn tùy thích
    fprintf(log, "[%s] User:%s Action:%s UID:%s Name:%s Room:%s Plate:%s\n", 
            timestr, username, action, 
            member->uid, member->name, 
            member->roomNumber, member->licensePlate);
    fclose(log);
}