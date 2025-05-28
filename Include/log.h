/**********************************************************************************
 * @file    log.h
 * @brief   Ghi log thao tác cho quản lý cư dân trong hệ thống
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 *********************************************************************************/

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include "utils.h"
#include "config.h"
#include "resident.h"

/**
 * @brief Ghi log thao tác vào file audit log.
 * @param action   Chuỗi hành động ("ADD", "EDIT"...)
 * @param member   Con trỏ Member thực hiện thao tác.
 * @param username Tên người dùng thao tác.
 */
void writeAuditLog(const char *action, const Member *member, const char *username);

#endif  // LOG_H