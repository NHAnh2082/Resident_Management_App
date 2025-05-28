/**********************************************************************************
 * @file    resident.h
 * @brief   Khai báo các hàm và cấu trúc cho quản lý cư dân trong hệ thống
 * @details File này cung cấp giao diện thao tác quản lý cư dân: thêm, xóa, sửa,
 *          tìm kiếm, in danh sách, sort, cũng như các hàm so sánh trường dữ liệu.
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 *********************************************************************************/
#ifndef RESIDENT_H
#define RESIDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI.h"
#include "config.h"

/**
 * @brief Định nghĩa cấu trúc lưu thông tin một cư dân.
 */
typedef struct
{
    char uid[21];           /**< UID (tối đa 20 ký tự) */
    char roomNumber[11];    /**< Số Phòng */
    char name[51];          /**< Tên */
    char licensePlate[21];  /**< Biển Số Xe */
} Member;

/**
 * @brief Định nghĩa cấu trúc 1 Node
 */
typedef struct MemberNode 
{
    Member data;
    struct MemberNode *next;
} MemberNode;

/**
 * @brief Thêm 1 cư dân vào danh sách liên kết (ở cuối).
 * @param head Con trỏ đến con trỏ đầu danh sách.
 * @param member Dữ liệu cư dân cần thêm.
 * @return 1 nếu thành công, 0 nếu lỗi.
 */
int addMemberNode(MemberNode **head, Member member);

/**
 * @brief Xóa cư dân theo UID khỏi danh sách liên kết.
 * @param head Con trỏ đến con trỏ đầu danh sách.
 * @param uid UID cần xóa.
 * @return 1 nếu thành công, 0 nếu không tìm thấy.
 */
int deleteMemberByUID(MemberNode **head, const char *uid);

/**
 * @brief Sửa thông tin cư dân theo UID.
 * @param head Con trỏ đầu danh sách.
 * @param uid UID cần sửa.
 * @param updated Dữ liệu mới.
 * @return 1 nếu thành công, 0 nếu không tìm thấy.
 */
int editMemberByUID(MemberNode *head, const char *uid, Member updated);

/**
 * @brief Tìm cư dân theo UID.
 * @param head Con trỏ đầu danh sách.
 * @param uid UID cần tìm.
 * @return Con trỏ tới node nếu tìm thấy, NULL nếu không.
 */
MemberNode* searchMemberByUID(MemberNode *head, const char *uid);

/**
 * @brief Tìm cư dân theo tên (trả node đầu tiên phù hợp).
 * @param head Con trỏ đầu danh sách.
 * @param name Tên cần tìm.
 * @return Con trỏ tới node nếu tìm thấy, NULL nếu không.
 */
MemberNode* searchMemberByName(MemberNode *head, const char *name);

/**
 * @brief In toàn bộ danh sách cư dân.
 * @param head Con trỏ đầu danh sách.
 */
void printMemberList(MemberNode *head);

/**
 * @brief Sắp xếp danh sách cư dân theo trường được chọn.
 * @param head Con trỏ đầu danh sách.
 * @param byUID 1: sắp xếp theo UID, 0: theo tên.
 */
void sortMemberList(MemberNode **head, int sortType);

/* ==== HÀM GIAO DIỆN NGƯỜI DÙNG ==== */

/**
 * @brief Thêm cư dân tương tác qua console.
 * @param head Địa chỉ con trỏ đầu danh sách.
 * @return 1 nếu có thay đổi dữ liệu, 0 nếu không.
 */
int addMember(MemberNode **head);

/**
 * @brief Xóa cư dân tương tác qua console.
 * @param head Địa chỉ con trỏ đầu danh sách.
 * @return 1 nếu có thay đổi dữ liệu, 0 nếu không.
 */
int deleteMember(MemberNode **head);

/**
 * @brief Sửa cư dân tương tác qua console.
 * @param head Đầu danh sách.
 * @return 1 nếu có thay đổi dữ liệu, 0 nếu không.
 */
int editMember(MemberNode *head);

/**
 * @brief In toàn bộ danh sách cư dân.
 * @param head Đầu danh sách.
 */
void printAllMembers(MemberNode *head);

/**
 * @brief Sắp xếp và in danh sách cư dân tương tác.
 * @param head Địa chỉ con trỏ đầu danh sách.
 */
void sortAndPrintMemberList(MemberNode **head);

/**
 * @brief Tìm kiếm cư dân tương tác qua console.
 * @param head Đầu danh sách.
 */
void searchMember(MemberNode *head);

#endif  // RESIDENT_H