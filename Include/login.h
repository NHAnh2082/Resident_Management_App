/***************************************************************************************
 * @file    login.h
 * @brief   Khai báo danh sách tài khoản để đang nhập vào hệ thống
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 ***************************************************************************************/
#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <string.h>

/**
 * @brief Định nghĩa cấu trúc lưu thông tin đăng nhập.
 */
typedef struct 
{
    char username[21];
    char password[21];
} Account;

/**
 * @brief Khai báo danh sách các tài khoản có thể đăng nhập vào hệ thống
 */
const Account accounts[] = 
{
    {"admin1", "admin1_123"},
    {"admin2", "admin2_234"},
    {"admin3", "admin3_345"}
};

#define ACCOUNTS_COUNT (sizeof(accounts)/sizeof(Account))

/**
 * @brief Kiểm tra thông tin đăng nhập
 * @param username Thông tin đăng nhập.
 * @return 1 đăng nhập thành công, 0 đăng nhập thất bại
 */
int login(char *username);

#endif  // LOGIN_H