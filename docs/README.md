# Resident Management App

## Tổng quan dự án

- **Resident Management App** là ứng dụng quản lý thông tin cư dân đơn giản được phát triển bằng ngôn ngữ lập trình C. Ứng dụng cho phép lưu trữ, chỉnh sửa, tìm kiếm và xóa thông tin cư dân dưới dạng tệp CSV, phù hợp cho các hệ thống quản lý cư dân quy mô nhỏ hoặc trung bình.

- Ứng dụng được thiết kế hướng tới tính đơn giản, dễ sử dụng và dễ mở rộng, thích hợp cho mục đích học tập, nghiên cứu cũng như áp dụng thực tế cho các hệ thống quản lý cư dân nhỏ.

---

## Tính năng chính

- **Thêm mới cư dân**: Cho phép nhập và lưu thông tin cư dân bao gồm họ tên, tuổi, địa chỉ, số điện thoại và các thông tin liên quan.
- **Chỉnh sửa thông tin cư dân**: Sửa đổi dữ liệu cư dân hiện có theo ID hoặc tên.
- **Xóa cư dân**: Xóa thông tin cư dân không còn sinh sống hoặc không hợp lệ.
- **Tìm kiếm cư dân**: Tìm kiếm nhanh chóng theo nhiều tiêu chí như tên, địa chỉ hoặc số điện thoại.
- **Lưu trữ dữ liệu dạng CSV**: Toàn bộ dữ liệu được lưu trong tệp CSV chuẩn, giúp dễ dàng sao lưu và chỉnh sửa bên ngoài.
- **Ghi nhật ký hoạt động (Audit Log)**: Ghi lại tất cả các thao tác thêm, sửa, xóa nhằm phục vụ mục đích kiểm tra và theo dõi lịch sử hoạt động.
- **Biên dịch và quản lý dự án dễ dàng**: Sử dụng Makefile để tự động hóa quá trình build và chạy ứng dụng.

---

## Cấu trục dự án

```cpp

Resident_Management_App/
│
├── Build/                     # Thư mục chứa file các file object và file thực thi
│
├── Include/                   # Thư mục chứa các file header (.h)
│   ├── config.h                    # File cấu hình dự án (các macro, hằng số, cấu hình chung)
│   ├── csv_utils.h                 # Khai báo các hàm xử lý tệp CSV
│   ├── log.h                       # Khai báo hàm ghi log
│   ├── login.h                     # Khai báo hàm và cấu trúc liên quan đến chức năng đăng nhập
│   ├── resident.h                  # Khai báo cấu trúc và hàm xử lý thông tin cư dân
│   ├── statistic.h                 # Khai báo hàm và kiểu dữ liệu cho thống kê
│   ├── UI.h                        # Khai báo các hàm liên quan đến giao diện người dùng (console UI)
│   ├── utils.h                     # Khai báo các hàm tiện ích chung
│
├── Source/                    # Thư mục chứa file nguồn (*.c)
│   ├── csv_utils.c                 # Định nghĩa hàm xử lý file CSV (đọc, ghi, phân tích dữ liệu)
│   ├── log.c                       # Định nghĩa hàm ghi nhật ký hoạt động
│   ├── login.c                     # Định nghĩa chức năng đăng nhập
│   ├── main.c                      # Hàm main, điểm khởi đầu chương trình và menu chính
│   ├── resident.c                  # Xử lý logic liên quan đến quản lý cư dân (thêm, sửa, xóa, tìm kiếm)
│   ├── statistic.c                 # Xử lý các chức năng thống kê dữ liệu cư dân
│   ├── UI.c                        # Định nghĩa các hàm giao diện người dùng (hiển thị menu, nhận input,...)
│   ├── utils.c                     # Các hàm tiện ích dùng chung (xử lý chuỗi, kiểm tra dữ liệu...)
│
├── .gitignore                 # File cấu hình git để bỏ qua các file/thư mục không cần thiết
├── audit.log                  # File ghi nhật ký các thao tác của người dùng
├── Makefile                   # File cấu hình build dự án
├── Resident_Database.csv      # File lưu dữ liệu cư dân (dạng CSV)
├── README.md                  # File hướng dẫn dự án


```

## Yêu cầu hệ thống

- Hệ điều hành: Linux, Windows (qua MinGW hoặc Cygwin), macOS
- Trình biên dịch C chuẩn (GCC, Clang hoặc tương đương)
- Terminal hoặc Command Prompt
- Make (để sử dụng Makefile)

---

## Hướng phát triển và mở rộng

- **Tích hợp GUI**: Có thể phát triển giao diện đồ họa để người dùng thao tác dễ dàng hơn thay vì dòng lệnh.

- **Sử dụng CSDL**: Thay thế tệp CSV bằng các hệ quản trị cơ sở dữ liệu nhẹ như SQLite để tăng hiệu năng và khả năng mở rộng.

- **Bảo mật và xác thực dữ liệu**: Thêm kiểm tra, xác thực dữ liệu nhập vào để tránh lỗi và đảm bảo tính toàn vẹn.

- **Đa ngôn ngữ**: Hỗ trợ nhiều ngôn ngữ để ứng dụng phù hợp với nhiều đối tượng sử dụng.