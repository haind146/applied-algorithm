# applied-algorithm

## Thuật toán nhánh cận

* Sử dụng để giải bài toán tối ưu tổ hợp

Bài toán liệt kê: Backtracking
Bài toán tối ưu: Tìm phương án tốt nhất theo một tiêu chí nào đó

Sử dụng backtrack để liệt kê các phương án, với mỗi phương án tìm hàm mục tiêu( tiêu chí cần tối ưu) và lưu lại phương án tốt nhất

* Dùng đánh giá cận để giảm bớt số trường hợp cần duyệt



## Thuật toán sắp xếp
Sắp xếp dãy số a1,a2...an theo thứ tự không giảm

### Quick sort

Các bước thực hiện:
- Chọn một phần tử trụ bất kì
- biên tập lại dãy thành 2 phần sao cho 1 bên nhỏ hơn phần tử trụ, một bên lớn hơn phần tử trụ
- lặp đệ quy quick sort từng phần vừa phân chia

## Chia để trị

Chia bài toán thành các bài toán con độc lập
(khác quy hoạch động)

Tổng hợp lời giải


## Đồ thị

Đường đi trên đồ thị:
- Đường đi cơ bản (elementary path): không có đỉnh lặp lại
- Đường đi đơn (simple path): không có cạnh lặp lại ( có thể có đỉnh lặp lại)

Đồ thị G được gọi là liên thông nếu giữa 2 đỉnh u, v bất kì đầu có đường đi từ u->v

Đồ thị liên thông sẽ được phân rã thành các thành phần liên thông (connected component)
Thành phần liên thông là đồ thị con lớn nhất liên thông

### Đồ thị có hướng
Đồ thị có hướng được gọi là liên thông mạnh nếu giữa 2 đỉnh u và v luôn có đường đi
Đồ thị được gọi là liên thông yếu nếu đồ thị vô hướng tương ứng là liên thông


## Biểu diễn đồ thị

### Ma trận kề

### Danh sách kề
- Dùng cho đồ thị thưa, có ít cạnh
- Mỗi đỉnh u: lưu trữ danh sách kề với đỉnh đó, kèm với trọng số hoặc không trọng số
- Thư viện lưu trữ trong C++ list, set, stack, queue, map

* Duyệt và tìm kiếm trên đồ thị:
 2 phương pháp cơ bản:
 - Duyệt theo chiều sâu: DFS
 - Duyệt theo chiều rộng: BFS

 Ghi nhận các thông tin cho mỗi đỉnh v
 - d[v] thời điểm đỉnh v được thăm nhưng chưa duyệt xong;
 - f[v] thời điểm đỉnh v đã duyệt xong
 - p[v] đỉnh trước khi thăm đỉnh v
 - color: màu đánh dấu đỉnh đã duyệt xong/ đã duyệt nhưng chưa xong/ chưa được thăm


DFS (v) {

}

DFS(G=(V,E)) {
    for v in V do:
        color[v] = W;
        p[v] = NULL;
    for v in V do:
        if color[v] = W then:
            DFS(v)
}