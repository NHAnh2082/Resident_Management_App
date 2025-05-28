/***********************************************************************************
 * @file    config.h
 * @brief   Định nghĩa các hằng số cấu hình chung cho hệ thống quản lý cư dân
 * @details File này chứa các macro cấu hình như số phòng tối đa, định dạng
 *          đọc/ghi file CSV, tiêu đề file CSV, tên file dữ liệu, tên file log, v.v 
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 ***********************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H


#define MAX_ROOMS 200 /**< Số lượng phòng tối đa có thể quản lý trong hệ thống */

/**
 * @brief   Định dạng ghi một dòng dữ liệu cư dân vào file CSV
 * @note    Theo thứ tự: uid, roomNumber, name, licensePlate
 */
#define CSV_WRITE_FORMAT "%s, %s, %s, %s\n"

/**
 * @brief   Định dạng đọc một dòng dữ liệu cư dân từ file CSV
 * @note    Theo thứ tự: uid, roomNumber, name, licensePlate
 */
#define CSV_READ_FORMAT " %[^,], %[^,], %[^,], %[^\n]"

/**
 * @brief   Dòng tiêu đề cho file CSV lưu trữ dữ liệu cư dân
 */
#define MEMBER_INFORMATION "uID, Room Number, Name, License Plate"

#define DATA_FILE "Resident_Database.csv"   /**< Tên file dữ liệu chính của hệ thống */

#define AUDIT_LOG_FILE "audit.log"   /**< Tên file ghi log các thao tác thay đổi dữ liệu */

#endif  // CONFIG_H
