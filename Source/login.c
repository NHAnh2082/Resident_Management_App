#include "..//Include//login.h"

/**
 * @brief Kiểm tra thông tin đăng nhập
 * @param username Thông tin đăng nhập.
 * @return 1 đăng nhập thành công, 0 đăng nhập thất bại
 */
int login(char *username)
{
    char inputUser[21], inputPass[21];

    // Nhập thông tin đăng nhập
    printf("Nhập tài khoản: "); scanf("%20s", inputUser);
    printf("Nhập mật khẩu: ");  scanf("%20s", inputPass);

    for (size_t i=0; i<ACCOUNTS_COUNT; ++i) 
    {
        if (strcmp(inputUser, accounts[i].username) == 0 && 
            strcmp(inputPass, accounts[i].password) == 0)
        {
            strcpy(username, inputUser);
            printf("Đăng nhập thành công!\n");
            return 1;
        }
    }

    printf("Đăng nhập thất bại!\n");
    return 0;
}