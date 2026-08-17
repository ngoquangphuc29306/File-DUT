-- 1. Tạo bảng KHACHHANG
CREATE TABLE KHACHHANG (
    MAKH CHAR(4) PRIMARY KEY,
    HOTEN NVARCHAR(40) NOT NULL,
    DCHI NVARCHAR(50),
    SODT CHAR(10),
    NGSINH SMALLDATETIME,
    NGDK SMALLDATETIME,
    DOANHSO MONEY DEFAULT 0
);

-- 2. Tạo bảng NHANVIEN
CREATE TABLE NHANVIEN (
    MANV CHAR(4) PRIMARY KEY,
    HOTEN NVARCHAR(40) NOT NULL,
    SODT CHAR(10),
    NGVL SMALLDATETIME
);

-- 3. Tạo bảng SANPHAM
CREATE TABLE SANPHAM (
    MASP CHAR(4) PRIMARY KEY,
    TENSP NVARCHAR(40) NOT NULL,
    DVT NVARCHAR(20),
    NUOCSX NVARCHAR(40),
    GIA MONEY
);

-- 4. Tạo bảng HOADON
CREATE TABLE HOADON (
    SOHD INT PRIMARY KEY,
    NGHD SMALLDATETIME DEFAULT GETDATE(),
    MAKH CHAR(4),
    MANV CHAR(4),
    TRIGIA MONEY DEFAULT 0,
    -- Thiết lập khóa ngoại
    CONSTRAINT FK_HOADON_KHACHHANG FOREIGN KEY (MAKH) REFERENCES KHACHHANG(MAKH),
    CONSTRAINT FK_HOADON_NHANVIEN FOREIGN KEY (MANV) REFERENCES NHANVIEN(MANV)
);

-- 5. Tạo bảng CTHD (Chi tiết hóa đơn)
CREATE TABLE CTHD (
    SOHD INT,
    MASP CHAR(4),
    SL INT,
    -- Khóa chính phức hợp (kết hợp từ 2 cột)
    PRIMARY KEY (SOHD, MASP),
    -- Thiết lập khóa ngoại
    CONSTRAINT FK_CTHD_HOADON FOREIGN KEY (SOHD) REFERENCES HOADON(SOHD),
    CONSTRAINT FK_CTHD_SANPHAM FOREIGN KEY (MASP) REFERENCES SANPHAM(MASP)
);

INSERT INTO NHANVIEN (MANV, HOTEN, SODT, NGVL) VALUES
('NV01', N'Nguyen Nhu Nhut', '0927345678', '2006-04-13'),
('NV02', N'Le Thi Phi Yen', '0987567390', '2006-04-21'),
('NV03', N'Nguyen Van B', '0997047382', '2006-04-27'),
('NV04', N'Ngo Thanh Tuan', '0913758498', '2006-06-24'),
('NV05', N'Nguyen Thi Truc Thanh', '0918590387', '2006-07-20');

INSERT INTO KHACHHANG (MAKH, HOTEN, DCHI, SODT, NGSINH, DOANHSO, NGDK) VALUES
('KH01', N'Nguyen Van A', N'731 Tran Hung Dao, Q5, TpHCM', '08823451', '1960-10-22', 13060000, '2006-07-22'),
('KH02', N'Tran Ngoc Han', N'23/5 Nguyen Trai, Q5, TpHCM', '0908256478', '1974-04-03', 280000, '2006-07-30'),
('KH03', N'Tran Ngoc Linh', N'45 Nguyen Canh Chan, Q1, TpHCM', '0938776266', '1980-06-12', 3860000, '2006-08-05'),
('KH04', N'Tran Minh Long', N'50/34 Le Dai Hanh, Q10, TpHCM', '0917325476', '1965-03-09', 250000, '2006-10-02'),
('KH05', N'Le Nhat Minh', N'34 Truong Dinh, Q3, TpHCM', '08246108', '1950-03-10', 21000, '2006-10-28'),
('KH06', N'Le Hoai Thuong', N'227 Nguyen Van Cu, Q5, TpHCM', '08631738', '1981-12-31', 915000, '2006-11-24'),
('KH07', N'Nguyen Van Tam', N'32/3 Tran Binh Trong, Q5, TpHCM', '0916783565', '1971-04-06', 12500, '2006-12-01'),
('KH08', N'Phan Thi Thanh', N'45/2 An Duong Vuong, Q5, TpHCM', '0938435756', '1971-01-10', 365000, '2006-12-13'),
('KH09', N'Le Ha Vinh', N'873 Le Hong Phong, Q5, TpHCM', '08654763', '1979-09-03', 70000, '2007-01-14'),
('KH10', N'Ha Duy Lap', N'34/34B Nguyen Trai, Q1, TpHCM', '08768904', '1983-05-02', 67500, '2007-01-16');

INSERT INTO SANPHAM (MASP, TENSP, DVT, NUOCSX, GIA) VALUES
('BC01', N'But chi', N'cay', N'Trung Quoc', 3000),
('BC02', N'But chi', N'cay', N'Thai Lan', 5000),
('BC03', N'But chi', N'cay', N'Viet Nam', 3500),
('BC04', N'But chi', N'hop', N'Viet Nam', 30000),
('BB01', N'But bi', N'cay', N'Viet Nam', 5000),
('BB02', N'But bi', N'cay', N'Trung Quoc', 7000),
('BB03', N'But bi', N'hop', N'Thai Lan', 100000),
('TV01', N'Tap 100 giay mong', N'quyen', N'Trung Quoc', 2500),
('TV02', N'Tap 200 giay mong', N'quyen', N'Trung Quoc', 4500),
('TV03', N'Tap 100 giay tot', N'quyen', N'Viet Nam', 3000),
('TV04', N'Tap 200 giay tot', N'quyen', N'Viet Nam', 5500),
('TV05', N'Tap 100 trang', N'chuc', N'Viet Nam', 23000),
('TV06', N'Tap 200 trang', N'chuc', N'Viet Nam', 53000),
('TV07', N'Tap 100 trang', N'chuc', N'Trung Quoc', 34000),
('ST01', N'So tay 500 trang', N'quyen', N'Trung Quoc', 40000),
('ST02', N'So tay loai 1', N'quyen', N'Viet Nam', 55000),
('ST03', N'So tay loai 2', N'quyen', N'Viet Nam', 51000),
('ST04', N'So tay', N'quyen', N'Thai Lan', 55000),
('ST05', N'So tay mong', N'quyen', N'Thai Lan', 20000),
('ST06', N'Phan viet bang', N'hop', N'Viet Nam', 5000),
('ST07', N'Phan khong bui', N'hop', N'Viet Nam', 7000),
('ST08', N'Bong bang', N'cai', N'Viet Nam', 1000),
('ST09', N'But long', N'cay', N'Viet Nam', 5000),
('ST10', N'But long', N'cay', N'Trung Quoc', 7000);

SET DATEFORMAT dmy;

INSERT INTO HOADON (SOHD, NGHD, MAKH, MANV, TRIGIA) VALUES
(1001, '23/07/2006', 'KH01', 'NV01', 320000),
(1002, '12/08/2006', 'KH01', 'NV02', 840000),
(1003, '23/08/2006', 'KH02', 'NV01', 100000),
(1004, '01/09/2006', 'KH02', 'NV01', 180000),
(1005, '20/10/2006', 'KH01', 'NV02', 3800000),
(1006, '16/10/2006', 'KH01', 'NV03', 2430000),
(1007, '28/10/2006', 'KH03', 'NV03', 510000),
(1008, '28/10/2006', 'KH01', 'NV03', 440000),
(1009, '28/10/2006', 'KH03', 'NV04', 200000),
(1010, '01/11/2006', 'KH01', 'NV01', 5200000),
(1011, '04/11/2006', 'KH04', 'NV03', 250000),
(1012, '30/11/2006', 'KH05', 'NV03', 21000),
(1013, '12/12/2006', 'KH06', 'NV01', 5000),
(1014, '31/12/2006', 'KH03', 'NV02', 3150000),
(1015, '01/01/2007', 'KH06', 'NV01', 910000),
(1016, '01/01/2007', 'KH07', 'NV02', 12500),
(1017, '02/01/2007', 'KH08', 'NV03', 35000),
(1018, '13/01/2007', 'KH08', 'NV03', 330000),
(1019, '13/01/2007', 'KH01', 'NV03', 30000),
(1020, '14/01/2007', 'KH09', 'NV04', 70000),
(1021, '16/01/2007', 'KH10', 'NV03', 67500),
(1022, '16/01/2007', NULL, 'NV03', 7000),
(1023, '17/01/2007', NULL, 'NV01', 330000);

INSERT INTO CTHD (SOHD, MASP, SL) VALUES
(1001, 'TV02', 10),
(1001, 'ST01', 5),
(1001, 'BC01', 5),
(1001, 'BC02', 10),
(1001, 'ST08', 10),
(1002, 'BC04', 20),
(1002, 'BB01', 20),
(1002, 'BB02', 20),
(1003, 'BB03', 10),
(1004, 'TV01', 20),
(1004, 'TV02', 10),
(1004, 'TV03', 10),
(1004, 'TV04', 10),
(1005, 'TV05', 50),
(1005, 'TV06', 50),
(1006, 'TV07', 20),
(1006, 'ST01', 30),
(1006, 'ST02', 10),
(1007, 'ST03', 10),
(1008, 'ST04', 8),
(1009, 'ST05', 10),
(1010, 'TV07', 50),
(1010, 'ST07', 50),
(1010, 'ST08', 100),
(1010, 'ST04', 50),
(1010, 'TV03', 100),
(1011, 'ST06', 50),
(1012, 'ST07', 3),
(1013, 'ST08', 5),
(1014, 'BC02', 80),
(1014, 'BB02', 100),
(1014, 'BC04', 60),
(1014, 'BB01', 50),
(1015, 'BB02', 30),
(1015, 'BB03', 7),
(1016, 'TV01', 5),
(1017, 'TV02', 1),
(1017, 'TV03', 1),
(1017, 'TV04', 5),
(1018, 'ST04', 6),
(1019, 'ST05', 1),
(1019, 'ST06', 2),
(1020, 'ST07', 10),
(1021, 'ST08', 5),
(1021, 'TV01', 7),
(1021, 'TV02', 10),
(1022, 'ST07', 1),
(1023, 'ST04', 6);

Select * from KHACHHANG
Select * from NHANVIEN
Select * from SANPHAM
Select * from HOADON
Select * from CTHD
