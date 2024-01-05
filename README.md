
# C Nâng cao 

ở đây sẽ lưu hết các kiếm thức đã học, theo cách ta hiểu

# Kiến thức C
## Compiler-macro
- **Compiler** là quá trình máy tính dịch từ ngôn ngữ lập trình qua ngôn ngữ máy:\
![compiler](https://github.com/LughTA/embeded/assets/121286723/8f9462e6-7368-442e-870e-c831c5a12014)
![compiler prosess](https://github.com/LughTA/embeded/assets/121286723/6462c7d3-f450-4cae-b414-2d9bd4a79e03)
- **Macro** là từ dùng để chỉ những thông tin được xử lý ở quá trình tiền xử lý ( Preprocessor). hiểu nôm na là cái j mà ở bước tiền xử lý làm thì sẽ gọi là macro. 
Chia làm 3 nhóm chính:
+ #include: chèn nội dung từ một file khác vô chương trình
+ #define, #undef định nghĩa một đoạn code thuận tiện cho xài sau này. cái undef dùng để hủy nội dung của define đã tạo trước đó.
+ #if, #elif, #else, #ifdef, #ifndef:
#if sử dụng để bắt đầu một điều kiện tiền xử lý.\
Nếu điều kiện trong #if là đúng, các dòng mã nguồn sau #if sẽ được biên dịch. Nếu sai, các dòng mã nguồn sẽ bị bỏ qua đến khi gặp #endif\
#elif dùng để thêm một điều kiện mới khi điều kiện trước đó trong #if hoặc #elif là sai\
#else dùng khi không có điều kiện nào ở trên đúng.\
vd:
![if](https://github.com/LughTA/embeded/assets/121286723/3e3b79f8-8b4f-4f0c-8075-dd5e29f1bc48)
#ifdef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì mã nguồn sau #ifdef sẽ được biên dịch.
#ifndef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro chưa được định nghĩa thì mã nguồn sau #ifndef sẽ được biên dịch\
vd:
![ifdef](https://github.com/LughTA/embeded/assets/121286723/258f6d66-9e69-465b-ad7f-e7df0155d8ef)


## Stdarg-assert
**Thư viện Stdarg:** Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.\
Các hàm hữu ích trong thư viện: 
- va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
- va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
- va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai
- va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.
![STDARG](https://github.com/LughTA/embeded/assets/121286723/569182c2-5b49-4b2c-8483-16b4e975ae83)\
**Thư viện assert** Cung cấp macro assert.\
Macro này được sử dụng để kiểm tra một điều kiện. 
Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.\
Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.\
Dùng trong debug, dùng #define NDEBUG để tắt debug\
![assert](https://github.com/LughTA/embeded/assets/121286723/f44cde5e-5e27-452c-82ca-3dc92295481e)
## Pointer
**Pointer** là một biến lưu địa chỉ của biến khác 

## Extern - Static - Volatile

## Goto - setjmp.h

## Bitmask
Là kỹ thuật để thao tác vớicác bit\
Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic
trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của
một đối tượng\
- cú pháp: a = b (phép toán) c \
(c là số thứ 2 hoặc có thể là số lần đối với phép dịch bit)\
Các phép toán:\
- NOT bitwise: 1>0, 0>1
- AND bitwise:
![and](https://github.com/LughTA/embeded/assets/121286723/901990c8-0556-40b6-9d95-ef78aa293826)
- OR bitwise:
![or](https://github.com/LughTA/embeded/assets/121286723/1a3b44c2-a4d5-4ed2-895f-9a36096295c8)

- XOR bitwise:
![xor](https://github.com/LughTA/embeded/assets/121286723/b17fdb2d-fa59-4bfb-9232-d2acf0323559)
- Shift left và Shift right: dịch bit qua trái hoặc phải
 
## Struct - Union

## Memory layout

## JSON

## Linked List

## Stack - Queue

# Kiến thức C++



