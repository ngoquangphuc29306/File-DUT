CREATE DATABASE THUCTAP
go
USE THUCTAP
go

CREATE TABLE Khoa (
	MaKhoa varchar(10) primary key,
	TenKhoa varchar(30),
	DienThoai varchar(10)
)

CREATE TABLE GiangVien(
	MaGV int primary key,
	HoTenGV varchar(30),
	Luong decimal(5,2),
	MaKhoa varchar(10),
	CONSTRAINT MK_MaKhoa_FK foreign key (MaKhoa) REFERENCES Khoa(MaKhoa)
)

CREATE TABLE SinhVien(
	MaSV int primary key,
	HoTenSV varchar(40),
	MaKhoa varchar(10),
	Namsinh int,
	Quequan char(30),
	CONSTRAINT MK_SinhVien_FK foreign key (MaKhoa) REFERENCES Khoa(MaKhoa)
)

CREATE TABLE DeTai(
	MaDT varchar(10) primary key,
	TenDT varchar(30),
	KinhPhi int,
	NoiThucTap char(30)
)

CREATE TABLE HuongDan(
	MaSV int primary key,
	MaDT varchar(10) foreign key references DeTai,
	MaGV int foreign key references GiangVien,
	KetQua decimal(5,2)
)

INSERT INTO Khoa VALUES
('Geo','Dia ly va QLTN','0385541312'),
('Math','Toan','0906554111'),
('Bio','Cong nghe Sinh hoc','0926385541');

INSERT INTO GiangVien VALUES
	(11,'Thanh Binh',700,'Geo'),    
	(12,'Thu Huong',500,'Math'),
	(13,'Chu Vinh',650,'Geo'),
	(14,'Le Thi Ly',500,'Bio'),
	(15,'Tran Son',900,'Math');

INSERT INTO SinhVien VALUES
	(1,'Le Van Son','Bio',1990,'Nghe An'),
	(2,'Nguyen Thi Mai','Geo',1990,'Thanh Hoa'),
	(3,'Bui Xuan Duc','Math',1992,'Ha Noi'),
	(4,'Nguyen Van Tung','Bio',null,'Ha Tinh'),
	(5,'Le Khanh Linh','Bio',1989,'Ha Nam'),
	(6,'Tran Khac Trong','Geo',1991,'Thanh Hoa'),
	(7,'Le Thi Van','Math',null,'null'),
	(8,'Hoang Van Duc','Bio',1992,'Nghe An');

INSERT INTO DeTai VALUES
	('DT01','GIS',100,'Nghe An'),
	('DT02','ARC GIS',500,'Nam Dinh'),
	('DT03','Spatial DB',100, 'Ha Tinh'),
	('Dt04','MAP',300,'Quang Binh' );

INSERT INTO HuongDan VALUES
	(1,'DT01',13,8),
	(2,'DT03',14,0),
	(3,'DT03',12,10),
	(5,'DT04',14,7),
	(6,'DT01',13,Null),
	(7,'DT04',11,10),
	(8,'DT03',15,6);

