import os
import re

# Chỉ định thư mục chứa code (dấu '.' nghĩa là thư mục hiện tại)
folder_path = '.' 

# Lặp qua tất cả các file có trong thư mục
for filename in os.listdir(folder_path):
    # Tìm các file có định dạng: <số>_<số>.cpp (VD: 1_2.cpp, 10_1.cpp)
    match = re.match(r'^(\d+)_(\d+)\.cpp$', filename)
    
    if match:
        prefix = match.group(1) # Lấy phần số đầu tiên (VD: 1)
        number = match.group(2) # Lấy phần số thứ hai (VD: 2)
        
        # Hàm zfill(2) tự động thêm số 0 vào trước nếu độ dài chuỗi nhỏ hơn 2
        # (VD: '2' thành '02', '10' vẫn là '10')
        new_number = number.zfill(2) 
        new_filename = f"{prefix}_{new_number}.cpp"
        
        # Chỉ tiến hành đổi tên nếu tên mới khác tên cũ
        if filename != new_filename:
            os.rename(filename, new_filename)
            print(f"Đã đổi: {filename:<10} ->   {new_filename}")