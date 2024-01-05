
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
- **Pointer** là một biến lưu địa chỉ của biến khác 
Kích thước con trỏ phụ thuộc hoàn toàn vào kiểu cấu trúc của máy tính (8 bit, 16bit, 32 bit, 64 bit,..)\
![khai bao con tro](https://github.com/LughTA/embeded/assets/121286723/be8d6c54-8a3a-4f74-ac24-d2e003647129)
- **Pointer to function (con trỏ hàm)**\
Là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.\
Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.\
![funtion pointer](https://github.com/LughTA/embeded/assets/121286723/d062d1de-8373-44be-a5e1-83d852cc59d8)
- **Void Pointer**  thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.\
Cú pháp: **void** *ptr_void;\
- **Pointer to Constant** Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.\
Cú pháp:\
![const pointer](https://github.com/LughTA/embeded/assets/121286723/b4d9f612-cf6d-4b14-9536-efb3aa16367b)
- **Constant Pointer** Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.\
![constan pointer](https://github.com/LughTA/embeded/assets/121286723/7a185510-2f23-40bc-b67b-b0cba1f8ba92)
- **Pointer to Pointer**
là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.\
![pointer to pointer](https://github.com/LughTA/embeded/assets/121286723/b61fde61-27de-418a-a0ab-9b31ab3ad69c)
- **Null Pointer** 
là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.\
Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.\
Tạo một con trỏ sau đó cho giá trị bằng Null là đc con trỏ Null. 
## Extern - Static - Volatile
- **Extern**
Trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.
- **Static**
Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.\
Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.\
Khi một thành viên của lớp được khai báo là static, nó thuộc về lớp chứ không thuộc về các đối tượng cụ thể của lớp đó. Các đối tượng của lớp sẽ chia sẻ cùng một bản sao của thành viên static, và nó có thể được truy cập mà không cần tạo đối tượng. Nó thường được sử dụng để lưu trữ dữ liệu chung của tất cả đối tượng.
- **Volatile**
Từ khóa volatile trong ngôn ngữ lập trình C được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.
- **Resister** 
Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập(ý là ở trong bộ nhớ của vi điều khiển sẽ có một vùng nhớ vì vậy nếu dùng từ khóa này thì biến sẽ đc lưu trong vùng nhớ đó, ttruy suất sẽ nhanh hơn nhìu)\
Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này(tại dễ làm tràn bộ nhớ gây sai lệch trong vi điều khiển)

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
- AND bitwise:\
![and](https://github.com/LughTA/embeded/assets/121286723/901990c8-0556-40b6-9d95-ef78aa293826)
- OR bitwise:\
![or](https://github.com/LughTA/embeded/assets/121286723/1a3b44c2-a4d5-4ed2-895f-9a36096295c8)

- XOR bitwise:\
![xor](https://github.com/LughTA/embeded/assets/121286723/b17fdb2d-fa59-4bfb-9232-d2acf0323559)
- Shift left và Shift right: dịch bit qua trái hoặc phải
 
## Struct - Union
- **Struct** là cấu trúc dữ liệu được định nghĩa dựa trên các kiểu dữ liệu đã có sẵn
- kích thước: tổng kích thước của các thành phần bên trong
 cách tính kich thước như sau:\
Đầu tiên sẽ quét coi kich thước của thành phần nào lớn nhất sao đó tạo ra vùng lưu trữ bằng với kich thước của thành phần đó\
![struct1](https://github.com/LughTA/embeded/assets/121286723/4d91c8f8-aad2-41ee-8df4-7402287272a9)\
Sau đó nhét các thành phần khác vô từ từ với nguyên tắc là chỗ còn trống phải đủ để nhét thì ms nhét.\
![struct2](https://github.com/LughTA/embeded/assets/121286723/6b8d8778-cef3-495d-b395-2c5047306874)\
Nếu bị thiếu chỗ thì tạo vùng nhớ mới sau đó nhét vô.\
Như ví dụ là sẽ dư 1 ô trống vì thằng thứ 3 nó cần 4 byte nhưng chỉ còn như 1 byte k nhét đc phải tạo ms để nhét vô \
![struct3](https://github.com/LughTA/embeded/assets/121286723/388b92b8-8daf-45b0-beca-40aa0c1a0643)\
- **union** 
**so sánh Struct và Union
Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
•	struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)
•	Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác

## Memory layout

## JSON

## Linked List

## Stack - Queue

# Kiến thức C++



