/***************************************************************************************
 * @file    csv_utils.h
 * @brief   Khai báo các hàm tiện ích thao tác với file CSV cho hệ thống quản lý cư dân
 * @details File này chứa các hàm thao tác với file CSV như: đếm số cư dân, 
 *          kiểm tra ID trùng, xóa/sửa dòng, và tạo file CSV mới nếu chưa tồn tại.
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 ***************************************************************************************/
#ifndef CSV_UTILS_H
#define CSV_UTILS_H

#include "resident.h"
#include "config.h"

/**
 * @brief Đếm số node cư dân trong linked list.
 * @param head Đầu danh sách.
 * @return Số cư dân.
 */
int countMemberNodeList(MemberNode *head);

/**
 * @brief Tạo file CSV mới nếu chưa tồn tại.
 * @param filename Tên file.
 * @param header Chuỗi tiêu đề CSV.
 */
void createCSVIfNotExist(const char *filename, const char *header);

/**
 * @brief Kiểm tra UID có bị trùng trong linked list.
 * @param head Đầu danh sách.
 * @param uid UID cần kiểm tra.
 * @return 1 nếu trùng, 0 không trùng.
 */
int isDuplicateUIDInList(MemberNode *head, const char *uid);

/**
 * @brief Load danh sách cư dân từ file CSV thành linked list.
 * @param filename Tên file.
 * @return Đầu danh sách hoặc NULL nếu lỗi.
 */
MemberNode* loadMembersFromCSV(const char *filename);

/**
 * @brief Ghi linked list xuống file CSV.
 * @param filename Tên file.
 * @param head Đầu danh sách linked list.
 * @return 0 nếu thành công, -1 nếu lỗi.
 */
int saveMembersToCSV(const char *filename, MemberNode *head);

/**
 * @brief Giải phóng toàn bộ linked list.
 * @param head Đầu danh sách.
 */
void freeMemberList(MemberNode *head);

#endif  // CSV_UTILS_H