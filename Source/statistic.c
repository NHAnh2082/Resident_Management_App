#include "..//Include//statistic.h"

/**
 * @brief Thống kê tổng hợp dữ liệu cư dân.
 * @param filename  Tên file CSV dữ liệu cư dân.
 */
void statisticResidentsFromList(MemberNode *head)
{
    if (!head)
    {
        printf("Không có dữ liệu.\n");
        return;
    }

    // Đếm tổng số cư dân
    int totalResidents = 0;
    MemberNode *curr = head;

    while (curr)
    {
        totalResidents++;
        curr = curr->next;
    }

    // Tìm các phòng duy nhất
    char uniqueRooms[MAX_ROOMS][11];
    int roomUsed = 0;

    curr = head;
    while (curr)
    {
        int existed = 0;
        for (int i=0; i<roomUsed; ++i)
        {
            if (strcmp(uniqueRooms[i], curr->data.roomNumber) == 0)
            {
                existed = 1;
                break;
            }
        }

        if (!existed && roomUsed < MAX_ROOMS)
        {
            strcpy(uniqueRooms[roomUsed++], curr->data.roomNumber);
        }

        curr = curr->next;
    }

    // In thống kê
    printf("\n---- Statistics ----\n");
    printf("Tổng số cư dân: %d\n", totalResidents);
    printf("Số phòng sử dụng: %d\n", roomUsed);

    printf("\nSố lượng biển số xe mỗi phòng:\n");
    for (int i=0; i<roomUsed; ++i)
    {
        int count = 0;
        curr = head;

        while (curr)
        {
            if (strcmp(curr->data.roomNumber, uniqueRooms[i]) == 0) count++;
            curr = curr->next;
        }
        printf("  Room %s: %d resident(s)/car(s)\n", uniqueRooms[i], count);
    }

    // Thống kê theo tầng (ký tự đầu phòng)
    char uniqueFloors[MAX_ROOMS][11];
    int floorUsed = 0;

    for (int i=0; i<roomUsed; ++i)
    {
        char floor[11];
        strcpy(floor, uniqueRooms[i]);
        floor[1] = '\0'; // giữ ký tự đầu tiên

        int existed = 0;
        for (int j=0; j<floorUsed; ++j)
        {
            if (strcmp(uniqueFloors[j], floor) == 0)
            {
                existed = 1;
                break;
            }
        }

        if (!existed && floorUsed < MAX_ROOMS)
        {
            strcpy(uniqueFloors[floorUsed++], floor);
        }
    }

    printf("\nSố lượng biển số xe mỗi tầng:\n");
    for (int i=0; i<floorUsed; ++i)
    {
        int count = 0;
        curr = head;

        while (curr)
        {
            if (curr->data.roomNumber[0] == uniqueFloors[i][0]) count++;
            curr = curr->next;
        }
        printf("  Floor %s: %d resident(s)/car(s)\n", uniqueFloors[i], count);
    }
}