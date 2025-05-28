/***************************************************************************
 * @file    utils.h
 * @brief   Khai báo các hàm tiện ích dùng chung trong hệ thống
 * @details File này cung cấp các hàm tiện ích như so sánh chuỗi và 
 *          lấy thời gian hiện tại dưới dạng chuỗi.
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 ***************************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <time.h>

/**
 * So sánh hai chuỗi ký tự (giống strcmp, tự cài đặt).
 * @param str1   Chuỗi thứ nhất.
 * @param str2   Chuỗi thứ hai.
 * @return       <0 nếu str1 < str2, >0 nếu str1 > str2, 0 nếu bằng nhau.
 */
int compareString(const char *str1, const char *str2);

/**
 * Lấy thời gian hiện tại và chuyển thành chuỗi định dạng "YYYY-MM-DD HH:MM:SS".
 * @param buffer     Con trỏ vùng nhớ để ghi chuỗi thời gian.
 * @param bufsize    Kích thước vùng nhớ buffer.
 */
void getCurrentTimeStr(char *buffer, int bufsize);

#endif  // UTILS_H
