/***********************************************************************************************************
 * @file    UI.h
 * @brief   Khai báo macro hỗ trợ hiển thị menu và xử lý lựa chọn trong giao diện dòng lệnh
 * @details File này cung cấp các macro để in menu động, xử lý lựa chọn menu và gọi hàm chức năng tương ứng.
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 ***********************************************************************************************************/

#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

/**
 * @brief In một dòng mục menu với số thứ tự.
 * @param number    Số thứ tự menu.
 * @param item      Chuỗi mô tả menu.
 */
#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)

/**
 * @brief In toàn bộ danh sách menu từ danh sách chuỗi đầu vào.
 */
#define PRINT_MENU(...)                           \
	do                                            \
	{                                             \
		const char *items[] = {__VA_ARGS__};      \
		int n = sizeof(items) / sizeof(items[0]); \
		for (int i = 0; i < n; i++)               \
		{                                         \
			PRINT_MENU_ITEM(i + 1, items[i]);     \
		}                                         \
	} while (0)

// =========== ANSI COLOR ===========
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BOLD    "\x1b[1m"

/**
 * @brief Xóa màn hình
 */
void clear_screen();

/**
 * @brief Đọc trạng thái phím
 */
int get_arrow_key();

/**
 * @brief Hiển thị vị trí đang thao tác
 */
void print_breadcrumb(const char *text);

/**
 * @brief Hiển thị Menu
 */
int show_menu(const char *breadcrumb, const char *title, const char *choices[], int n);

/**
 * @brief Thoát chương trình
 */
void logout();

#endif  // UI_H