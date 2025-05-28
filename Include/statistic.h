/******************************************************************************************
 * @file    statistic.h
 * @brief   Khai báo các hàm thống kê dữ liệu cư dân
 * @details File này cung cấp các hàm phục vụ thống kê tổng hợp thông tin cư dân,
 *          bao gồm số lượng cư dân, số phòng đang ở, số lượng xe theo phòng, theo tầng,...
 * @version 1.0
 * @date    2024-12-24
 * @author  Anh Nguyen
 ******************************************************************************************/

#ifndef STATISTIC_H
#define STATISTIC_H

#include "csv_utils.h"
#include "resident.h"
#include "config.h"
#include <string.h>

/**
 * @brief Thống kê tổng hợp dữ liệu cư dân.
 * @param filename  Tên file CSV dữ liệu cư dân.
 */
void statisticResidentsFromList(MemberNode *head);

#endif  // STATISTIC_H