#include "..//Include//utils.h"

/**
 * So sánh hai chuỗi ký tự (giống strcmp, tự cài đặt).
 * @param str1   Chuỗi thứ nhất.
 * @param str2   Chuỗi thứ hai.
 * @return       <0 nếu str1 < str2, >0 nếu str1 > str2, 0 nếu bằng nhau.
 */
int compareString(const char *str1, const char *str2)
{
    // Biến đếm ký tự đang so sánh
    int i = 0;

    // Duyệt từng ký tự cho đến khi hết một chuỗi, hoặc khác ký tự tại cùng vị trí
    while (str1[i] && str1[i] == str2[i]) i++;

    // Trả về hiệu của ký tự đầu tiên khác nhau (ép kiểu unsigned để so sánh nhị phân)
    return (const unsigned char)str1[i] - (const unsigned char)str2[i];
}

/**
 * Lấy thời gian hiện tại và chuyển thành chuỗi định dạng "YYYY-MM-DD HH:MM:SS".
 * @param buffer     Con trỏ vùng nhớ để ghi chuỗi thời gian.
 * @param bufsize    Kích thước vùng nhớ buffer.
 */
void getCurrentTimeStr(char *buffer, int bufsize)
{
    // Lấy thời gian hiện tại dạng số nguyên (epoch time)
    time_t now = time(NULL);

    // Chuyển đổi thành struct tm dạng cục bộ (localtime)
    struct tm *t = localtime(&now);

    // Chuyển đổi thành struct tm dạng cục bộ (localtime)
    strftime(buffer, bufsize, "%Y-%m-%d %H:%M:%S", t);
}