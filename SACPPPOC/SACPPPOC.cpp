// SACPPPOC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "SACPPPOC.h"
#include <iostream>
#include "map.h"
#include "AStar.h"
#include "map_matrix.h"

typedef unsigned char uchar;
Matrix* matrix;


int main()
{
    /*
    char adrnBinName[256];
    strcpy(adrnBinName, ADRNBIN_DIR);
    initRealbinFileOpen(adrnBinName);
    */
	::WritePrivateProfileString("NPC", "Count1", "aaa", "E:\\workspace\\Github\\SACPPPOC\\SACPPPOC\\\Debug\\usefile.ini");
	::WritePrivateProfileString("NPC", "Count1", "aaa", "E:\\workspace\\Github\\SACPPPOC\\SACPPPOC\\\Debug\\usefile.ini");
	//RouteRoad();
	
	test();
	std::cout << "\nHello World!\n";
	
	/*
	AStar astar;
	astar.LoadMap();
	astar.TestMap();
	std::cout << "\nHello World!\n";
	*/

	LoadMatixMap();
	PrintMatrixMap();
	
    std::cout << "\nHello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件




void RouteRoad(void)
{
	/*
	checksum += autil.util_deint(2, &mapid);	//地图编号
		checksum += autil.util_deint(3, &x1);		//当前X坐标-13
		checksum += autil.util_deint(4, &y1);		//当前Y坐标-13
		checksum += autil.util_deint(5, &x2);		//当前X坐标+14
		checksum += autil.util_deint(6, &y2);		//当前Y坐标+14
		checksum += autil.util_deint(7, &t2);
		checksum += autil.util_deint(8, &t3);
		checksum += autil.util_deint(9, &t4);
		checksum += autil.util_destring(10, message);	//地图名称
	*/

	/*

		iChecksum += util_deint(2, &fl);
		iChecksum += util_deint(3, &x1);
		iChecksum += util_deint(4, &y1);
		iChecksum += util_deint(5, &x2);
		iChecksum += util_deint(6, &y2);
		iChecksum += util_deint(7, &tilesum);
		iChecksum += util_deint(8, &objsum);
		iChecksum += util_deint(9, &eventsum);
		iChecksum += util_destring(10, data);
		util_deint(11, &iChecksumrecv);
		if (iChecksum!=iChecksumrecv) {
			SliceCount=0;
			return 1;
		}
	*/

	
	/*
	createMap(2001, 30, 30);

	initMap();

	mapCheckSum();

	drawMap();

	drawGrid();

	getRouteMap();
	
	*/
	//test();
	CString str = "5244012e640000001e000000190300009060a0019f906070019f90601f019f906036019f8b60019f8660869f906013039f609f90603e8a9f9060508a9f02609f90603601a5849f04a36060a5849f01a3866003a6a2a08b9f01a5849f04a36060a5849f01a38860019f906016019f90601401a5849f04a06060a5909f1401a3846001a5849f04a06060a5859f906028019f8b6001a38d9f01a5836001a68b9f01a2836001a3859f02a660869f01a58e60019f90601c8e9f03a260a5859f01a0836001a3849f04a36060a3849f04a66060a2879f01a5859f01a08760019f90601b8d9f04609f60a2869f0260a5869f08a66060a6a3a39f9f836001a5849f04a36060a2879f01a5869f01a690601d859f8d60839f01a1869f02a5a3869f01a1866004a79fa2a0859f04a26060a1869f01a5879f01a1906032849f08a29f9fa1a39f9fa2849f01a7836002a7a2899f04a56060a1839f08a29f9fa1a39f9fa2849f01a790603101a0849f08a09f9fa29f9fa2a2849f836001a0899f01a3836001a0849f04a09f9fa2839f01a2839f01a2906031849f01a6869f02a2a6869f01a6879f03a2a5a78460849f02a6a2859f01a2859f01a7906016019f906018859f02a6a7859f03a260a0839f02a360859f05a1a7609f9f85608b9f02a260849f01a390602f01a7849f03a660a18a9f03a06060849f09a26060a3a19fa1a1a7909f1203a06060839f906013019f906016909f2703a660a5849f03a360a7869f90601c909f1101a6849f03a66060849f04a36060a1859f0260a5909f1003a66060879f01a1839f01a190602e01a5849f04a66060a2839f04a36060a5849f09a69f9fa7a3a1a09fa0909f1104a36060a5849f01a6906043849f0160839f026060869f8f60019f906022019f906023899f0160849f906053869f026060839f8460029f60839f90604b869f8a60029f9f8360069f9f60609f9f906014019f90602e869f906017049f9f6060839f90603b859f8f60019f8f60029f9f8360029f9f8d60019f8460019f8360019f90601c869f906026019f8460839f02609f906028039f6060839f906034029f9f906023019f90601e019f906021029f9f906079";
	SS_IMAGECODE imcode;
	SS_DecryptImageCode((LPSTR)(LPCTSTR)str, &imcode);
	simple_4ByteAlignment((int)imcode.width, (int)imcode.height, imcode.buf);
	
}
void SS_DecryptImageCode(char* data, SS_IMAGECODE* imagecode)
{
	BYTE bdata[3000], * pb;
	char buf[200], * p;
	int len, i, j = 0;

	len = strlen(data);
	p = data;
	for (i = 0; i < len / 2; i++)
	{
		strncpy_s(buf, p, 2);
		buf[2] = 0;
		bdata[j++] = HexToDec(buf);
		p += 2;
	}
	pb = bdata;
	imagecode->type = (long)pb[1] << 8 | pb[0];
	pb += sizeof(WORD);
	imagecode->isencrypted = (long)pb[1] << 8 | pb[0];
	pb += sizeof(WORD);
	imagecode->width = (long)pb[3] << 24 | (long)pb[2] << 16 | (long)pb[1] << 8 | pb[0];
	pb += sizeof(DWORD);
	imagecode->height = (long)pb[3] << 24 | (long)pb[2] << 16 | (long)pb[1] << 8 | pb[0];
	pb += sizeof(DWORD);
	imagecode->datasize = (long)pb[3] << 24 | (long)pb[2] << 16 | (long)pb[1] << 8 | pb[0];
	pb += sizeof(DWORD);
	//对位图数据进行解密
	ZeroMemory(imagecode->buf, sizeof(imagecode->buf));
	len = RealToBmp(pb, imagecode->buf, len / 2 - 16);
	imagecode->buflen = len;
}

unsigned int HexToDec(char* hex)
{
	unsigned tv, th;
	unsigned i, j, len, t, s = 0;
	len = strlen(hex);
	if (len % 2 == 1)
		return -1;
	i = 0;
	j = 0;
	while (i < len)
	{
		tv = toupper(hex[i++]);
		if (isalpha(tv))
		{
			tv -= char('A');
			tv += 10;
		}
		else if (isdigit(tv))
		{
			tv -= char('0');
		}
		else
			return unsigned(-1); // invalid string
		tv *= 16;
		th = toupper(hex[i++]);
		if (isalpha(th))
		{
			th -= char('A');
			th += 10;
		}
		else if (isdigit(th))
		{
			th -= char('0');
		}
		else
			return unsigned(-1); // invalid string
		t = tv + th;
		t *= pow((float)16, (int)j);
		j += 2;
		s += t;
	}
	return s;
}

//胜思服图形验证码解密
int RealToBmp(BYTE* Target, BYTE* Source, int RDDataLen)
{
	int DecryptFillPieceLen, SourceCurrent, TargetCurrent, i;
	BYTE TempC, TempD;
	TargetCurrent = 0;
	SourceCurrent = 0;

	do {
		TempD = Target[TargetCurrent];
		TargetCurrent = TargetCurrent + 1;
		if (TargetCurrent > RDDataLen)
			break;
		if ((TempD & 0x80) == 0)
		{
			//7x、5x、3x、1x aa bb 填充xaa个bb颜色点 
			if ((TempD & 0x10) != 0)
			{
				DecryptFillPieceLen = ((TempD & 0x0F) * 256) + Target[TargetCurrent];
				TargetCurrent = TargetCurrent + 1;
			}
			//6x、4x、2x、0x aa 填充x个aa颜色点
			else
			{
				DecryptFillPieceLen = (TempD & 0x0f);
			}
			if (DecryptFillPieceLen <= 0xFFFFF && DecryptFillPieceLen > 0)
			{
				for (i = 0; i < DecryptFillPieceLen; i++)
				{
					Source[SourceCurrent] = Target[TargetCurrent];
					TargetCurrent = TargetCurrent + 1;
					SourceCurrent = SourceCurrent + 1;
				}
			}
		}
		else
		{
			if ((TempD & 0x40) == 0)
			{
				TempC = Target[TargetCurrent];
				TargetCurrent = TargetCurrent + 1;
			}
			else
			{
				TempC = 0;
			}
			if ((TempD & 0x20) != 0)
			{
				DecryptFillPieceLen = ((TempD & 0x0F) * 256) + Target[TargetCurrent];
				TargetCurrent = TargetCurrent + 1;
				DecryptFillPieceLen = (DecryptFillPieceLen * 256) + Target[TargetCurrent];
				TargetCurrent = TargetCurrent + 1;
			}
			else
			{
				if ((TempD & 0x10) != 0)
				{
					DecryptFillPieceLen = ((TempD & 0x0F) * 256) + Target[TargetCurrent];
					TargetCurrent = TargetCurrent + 1;
				}
				else
				{
					DecryptFillPieceLen = (TempD & 0x0F);
				}
			}
			for (i = 0; i <= DecryptFillPieceLen; i++)
			{
				Source[SourceCurrent + i] = TempC;
			}
			SourceCurrent = SourceCurrent + DecryptFillPieceLen;
		}
	} while (true);
	return SourceCurrent;
}

bool simple_4ByteAlignment(int width, int height, unsigned char* bitmapData)
{
	if (!bitmapData)
	{
		return false;
	}
	unsigned char* fData = 0;
	//length 数据的总长度
	//fillCount 每行需要补充的字节数
	int length = 0, fillCount = 0;

	length = width * 3;//这里乘3是因为我们图片为Rgb图片，每个像素占3个字节
	if (length % 4 != 0)//先计算补充字节后，数据的总字节数
	{
		fillCount = 4 - length % 4;
		length += fillCount;
	}
	length *= height;

	//分配相应长度的内存
	fData = (uchar*)malloc(length);

	if (!fData)
	{
		return false;
	}

	memset(fData, 0, length);

	for (size_t i = 0; i < height; i++)
	{
		//由于需要4字节对齐，所以需要对每行进行补充fillCount的字节的数据。
		memcpy(fData + (width * 3 + fillCount) * i, bitmapData + width * 3 * i, width * 3);
	}

	bool ret = WriteBitmap888ToFile("你要保存的图片的路径.bmp", width, height, (uchar*)fData, length);
	//释放内存  
	free(fData);
	return ret;

}

//根据bitmapData的（RGB）数据，保存bitmap  
//filename是要保存到物理硬盘的文件名（包括路径）  
//dateSize 表示图形数据的大小
//bitmapData 数据必须经过4字节对齐
static BOOL WriteBitmap888ToFile(const char* filename, int width, int height, unsigned char* bitmapData, int dateSize)
{

	//填充BITMAPINFOHEADER  
	BITMAPINFOHEADER bitmapInfoHeader;
	memset(&bitmapInfoHeader, 0, sizeof(BITMAPINFOHEADER));
	bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfoHeader.biWidth = width;
	bitmapInfoHeader.biHeight = height;
	bitmapInfoHeader.biPlanes = 1;
	bitmapInfoHeader.biBitCount = 24;

	bitmapInfoHeader.biCompression = BI_RGB;

	bitmapInfoHeader.biSizeImage = dateSize;


	//填充BITMAPFILEHEADER  
	BITMAPFILEHEADER bitmapFileHeader;
	memset(&bitmapFileHeader, 0, sizeof(BITMAPFILEHEADER));
	bitmapFileHeader.bfType = 0x4d42;   //BM固定为这个
	bitmapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	bitmapFileHeader.bfSize = bitmapFileHeader.bfOffBits + dateSize;
	bitmapFileHeader.bfReserved1 = 0;
	bitmapFileHeader.bfReserved2 = 0;

	FILE* filePtr = 0;

	fopen_s(&filePtr, filename, "wb");
	if (NULL == filePtr)
	{
		return FALSE;
	}

	fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

	fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	fwrite(bitmapData, bitmapInfoHeader.biSizeImage, 1, filePtr);
	fclose(filePtr);
	return TRUE;
}

//根据bitmapData的（RGB）数据，保存bitmap  
//filename是要保存到物理硬盘的文件名（包括路径）  
//dateSize 表示图形数据的大小，
//bitmapData 数据必须经过4字节对齐
static BOOL WriteBitmap565ToFile(const char* filename, int width, int height, unsigned char* bitmapData, int dateSize)
{

	BITMAPFILEHEADER bitmapFileHeader;
	//填充BITMAPINFOHEADER  
	BITMAPINFOHEADER bitmapInfoHeader;

	RGBQUAD bmiColors[3]; //定义调色板

	bitmapFileHeader.bfType = 0x4d42;   //"BM"
	bitmapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 3;
	bitmapFileHeader.bfSize = bitmapFileHeader.bfOffBits + dateSize;
	bitmapFileHeader.bfReserved1 = 0;
	bitmapFileHeader.bfReserved2 = 0;


	memset(&bitmapInfoHeader, 0, sizeof(BITMAPINFOHEADER));
	bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfoHeader.biWidth = width;
	bitmapInfoHeader.biHeight = -height;
	bitmapInfoHeader.biPlanes = 1;
	bitmapInfoHeader.biBitCount = 16;
	bitmapInfoHeader.biCompression = BI_BITFIELDS;
	bitmapInfoHeader.biSizeImage = dateSize;


	bmiColors[0].rgbBlue = 0;
	bmiColors[0].rgbGreen = 0xF8;
	bmiColors[0].rgbRed = 0;
	bmiColors[0].rgbReserved = 0;

	bmiColors[1].rgbBlue = 0xE0;
	bmiColors[1].rgbGreen = 0x07;
	bmiColors[1].rgbRed = 0;
	bmiColors[1].rgbReserved = 0;

	bmiColors[2].rgbBlue = 0x1F;
	bmiColors[2].rgbGreen = 0;
	bmiColors[2].rgbRed = 0;
	bmiColors[2].rgbReserved = 0;


	FILE* filePtr = 0;

	fopen_s(&filePtr, filename, "wb");
	if (NULL == filePtr)
	{
		return FALSE;
	}

	fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

	fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	fwrite(bmiColors, 3 * sizeof(RGBQUAD), 1, filePtr);

	fwrite(bitmapData, bitmapInfoHeader.biSizeImage, 1, filePtr);
	fclose(filePtr);
	return TRUE;
}

BOOL LoadMatixMap() {
	FILE* fp;
	int fWidth = -1;
	int fHeight = -1;
	char path[1024] = { 0 };
	memset(path, 0, sizeof(path));
	strcpy(path, "E:\\Game\\NW\\map\\2001.dat");
	if ((fp = fopen(path, "rb")) == NULL) {
		return FALSE;
	}

	//Get Width, Height
	fseek(fp, 0, SEEK_SET);
	fread(&fWidth, sizeof(int), 1, fp); //1-宽
	fread(&fHeight, sizeof(int), 1, fp);//2-高

	if (fWidth < 1 || fHeight < 1) {
		return FALSE;
	}

	matrix = new Matrix(fHeight, fWidth);

	int x = 0;
	int y = 0;
	while (1) {
		int c = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		matrix->loadMap(c, x, y);
		
		if (x == fWidth - 1) {
			x = 0;
			y++;
			printf("\n");
		}
		else {
			x++;
		}

	}
	fclose(fp);
	return TRUE;




}

BOOL PrintMatrixMap() {
	FILE* fp;
	int fWidth = -1;
	int fHeight = -1;
	char path[1024] = { 0 };
	memset(path, 0, sizeof(path));
	strcpy(path, "E:\\Game\\NW\\map\\2001.dat");
	if ((fp = fopen(path, "rb")) == NULL) {
		return FALSE;
	}

	//Get Width, Height
	fseek(fp, 0, SEEK_SET);
	fread(&fWidth, sizeof(int), 1, fp); //1-宽
	fread(&fHeight, sizeof(int), 1, fp);//2-高

	if (fWidth < 1 || fHeight < 1) {
		return FALSE;
	}

	printf("\n");

	for (int y = 0; y < fHeight; y++) {
		for (int x = 0; x < fWidth; x++) {
			MapNode* tag = matrix->get(x, y);

			if (tag->isWall) {
				printf("x");
			}
			else {
				printf("0");
			}
		}
		printf("\n");
	}
}