#include "StdAfx.h"
#include "AFCFunction.h"

////显示信息框
//UINT AFCMessage(UINT uResourceID, HINSTANCE hInstance, const TCHAR * const szTitle, UINT uType, CWnd * pParentWnd)
//{
//	CString strMessage;
//	strMessage.LoadString(hInstance,uResourceID);
//	return ::MessageBox(pParentWnd->GetSafeHwnd(),strMessage,szTitle,uType);
//}
////显示信息框
//UINT AFCMessage(const TCHAR * const szText, const TCHAR * const szTitle, UINT uType, CWnd * pParentWnd)
//{
//	return ::MessageBox(pParentWnd->GetSafeHwnd(),szText,szTitle,uType);
//}
////绘画透明图
//bool AFCStretchBlt(CDC * pDesDC, int iXDes, int iYDes, int iDesWidth, int iDesHeight, CDC * pScrDC, int iXScr, int iYScr, int iScrWidth, int iScrHeight, COLORREF crColor)
//{
//	//保存变量
//	COLORREF crTextColor=pDesDC->GetTextColor();
//
//	//建立变量
//	CDC ImageDC,MaskDC;
//	CBitmap BmpImage,BmpMaskBmp;
//	BmpImage.CreateCompatibleBitmap(pDesDC,iDesWidth,iDesHeight);
//	BmpMaskBmp.CreateBitmap(iDesWidth,iDesHeight,1,1,NULL);
//	ImageDC.CreateCompatibleDC(pDesDC);
//	MaskDC.CreateCompatibleDC(pDesDC);
//	CBitmap * pOldBmpImage=ImageDC.SelectObject(&BmpImage);
//	CBitmap * pOldMaskBmp=MaskDC.SelectObject(&BmpMaskBmp);
//
//	//绘画图像
//	if ((iDesWidth==iScrWidth)&&(iDesHeight==iScrHeight))
//		ImageDC.BitBlt(0,0,iDesWidth,iDesHeight,pScrDC,iXScr,iYScr,SRCCOPY);
//	else 
//		ImageDC.StretchBlt(0,0,iDesWidth,iDesHeight,pScrDC,iXScr,iYScr,iScrWidth,iScrHeight,SRCCOPY);
//	ImageDC.SetBkColor(crColor);
//	//ImageDC.SetTextColor(RGB(0,0,0));
//	MaskDC.BitBlt(0,0,iDesWidth,iDesHeight,&ImageDC,0,0,SRCCOPY);
//
//	//生成透明区域为黑色，其它区域保持不变的位图/改成255了
//	ImageDC.SetBkColor(RGB(0,0,0));
//	ImageDC.SetTextColor(RGB(255,255,255));
//	ImageDC.BitBlt(0,0,iDesWidth,iDesHeight,&MaskDC,0,0,SRCAND);
//
//	//其它部分变成黑色
//	//pDesDC->SetBkColor(RGB(255,255,255));
//	//pDesDC->SetTextColor(RGB(0,0,0));
//	pDesDC->BitBlt(iXDes,iYDes,iDesWidth,iDesHeight,&MaskDC,0,0,SRCAND);
//	pDesDC->BitBlt(iXDes,iYDes,iDesWidth,iDesHeight,&ImageDC,0,0,SRCPAINT);
//
//	//清理变量
//	ImageDC.SelectObject(pOldBmpImage);
//	ImageDC.DeleteDC();
//	MaskDC.SelectObject(pOldMaskBmp);
//	MaskDC.DeleteDC();
//	BmpImage.DeleteObject();
//	BmpMaskBmp.DeleteObject();
//
//	//恢复设置
//	pDesDC->SetTextColor(crTextColor);
//	return true;
//}
//
////绘画透明图
//bool AFCStretchImage(CDC * pDesDC, int iXDes, int iYDes, int iDesWidth, int iDesHeight, HBITMAP hBitBmp, int iXScr, int iYScr, int iScrWidth, int iScrHeight, COLORREF crColor)
//{
//	CDC MemDC;
//	MemDC.CreateCompatibleDC(pDesDC);
//	MemDC.SelectObject(hBitBmp);
//	//return AFCStretchBlt(pDesDC,iXDes,iYDes,iDesWidth,iDesHeight,&MemDC,iXScr,iYScr,iScrWidth,iScrHeight,crColor);
//	return ::TransparentBlt(pDesDC->GetSafeHdc(),iXDes,iYDes,iDesWidth,iDesHeight,MemDC.GetSafeHdc(),iXScr,iYScr,iScrWidth,iScrHeight,crColor);
//}
//
////播放声音
//bool AFCPlaySound(HINSTANCE hInstance, TCHAR * szResourceName)
//{
//	//HRSRC hResour=FindResource(hInstance,szResourceName,TEXT("WAVE"));
//	//if (hResour==NULL) return false;
// //   HGLOBAL hGlobal=LoadResource(hInstance,hResour);
//	//if (hGlobal==NULL) return false;
// //   LPSTR lPLock=(LPSTR)LockResource(hGlobal);
//	//::PlaySound(lPLock,hInstance,SND_ASYNC|SND_MEMORY|SND_NOSTOP|SND_NOWAIT);
//	//UnlockResource(hGlobal);
// //   FreeResource(hGlobal);
//	return true;
//}
//
////位图转换到区域 （需要重写）
//HRGN AFCBmpToRgn(HBITMAP hBmp, COLORREF cTransparentColor, COLORREF cTolerance)
//{
//	if (hBmp==NULL) return NULL;
//
//	HRGN hRgn=NULL;
//	HDC hMemDC=::CreateCompatibleDC(NULL);
//	if (hMemDC!=NULL)
//	{
//		BITMAP bm;
//		GetObject(hBmp, sizeof(bm), &bm);
//		VOID * pbits32=NULL; 
//		BITMAPINFOHEADER RGB32BITSBITMAPINFO = {sizeof(BITMAPINFOHEADER),bm.bmWidth,bm.bmHeight,1,32,BI_RGB,0,0,0,0,0};
//		HBITMAP hbm32 = CreateDIBSection(hMemDC, (BITMAPINFO *)&RGB32BITSBITMAPINFO, DIB_RGB_COLORS, &pbits32, NULL, 0);
//		if (hbm32)
//		{
//			HBITMAP holdBmp = (HBITMAP)SelectObject(hMemDC, hbm32);
//			HDC hDC = CreateCompatibleDC(hMemDC);
//			if (hDC)
//			{
//				BITMAP bm32;
//				GetObject(hbm32,sizeof(bm32),&bm32);
//				while (bm32.bmWidthBytes%4) bm32.bmWidthBytes++;
//				HBITMAP holdBmp=(HBITMAP)SelectObject(hDC,hBmp);
//				BitBlt(hMemDC,0,0,bm.bmWidth,bm.bmHeight,hDC,0,0,SRCCOPY);
//				#define ALLOC_UNIT    100
//				DWORD maxRects=ALLOC_UNIT;
//				HANDLE hData=GlobalAlloc(GMEM_MOVEABLE, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects));
//				RGNDATA *pData=(RGNDATA *)GlobalLock(hData);
//				pData->rdh.dwSize=sizeof(RGNDATAHEADER);
//				pData->rdh.iType=RDH_RECTANGLES;
//				pData->rdh.nCount=pData->rdh.nRgnSize=0;
//				SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);
//
//				// Keep on hand highest and lowest values for the "transparent" pixels
//				BYTE lr = GetRValue(cTransparentColor);
//				BYTE lg = GetGValue(cTransparentColor);
//				BYTE lb = GetBValue(cTransparentColor);
//				BYTE hr = min(0xff, lr + GetRValue(cTolerance));
//				BYTE hg = min(0xff, lg + GetGValue(cTolerance));
//				BYTE hb = min(0xff, lb + GetBValue(cTolerance));
//
//				// Scan each bitmap row from bottom to top (the bitmap is inverted vertically)
//				BYTE *p32=(BYTE *)bm32.bmBits + (bm32.bmHeight - 1) * bm32.bmWidthBytes;
//				for (int y=0;y<bm.bmHeight;y++)
//				{
//					// Scan each bitmap pixel from left to right
//					for (int x=0;x<bm.bmWidth;x++)
//					{
//						// Search for a continuous range of "non transparent pixels"
//						int x0=x;
//						LONG *p=(LONG *)p32+x;
//						while (x<bm.bmWidth)
//						{
//							BYTE b=GetRValue(*p);
//							if (b>=lr&&b<=hr)
//							{
//								b=GetGValue(*p);
//								if (b>=lg&&b<=hg)
//								{
//									b = GetBValue(*p);
//									if (b >= lb && b <= hb) break;
//								}
//							}
//							p++;
//							x++;
//						}
//
//						if (x>x0)
//						{
//							// Add the pixels (x0, y) to (x, y+1) as a new rectangle in the region
//							if (pData->rdh.nCount >= maxRects)
//							{
//								GlobalUnlock(hData);
//								maxRects += 100;
//								hData = GlobalReAlloc(hData, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), GMEM_MOVEABLE);
//								pData = (RGNDATA *)GlobalLock(hData);
//							}
//							RECT *pr = (RECT *)&pData->Buffer;
//							SetRect(&pr[pData->rdh.nCount], x0, y, x, y+1);
//							if (x0 < pData->rdh.rcBound.left)
//								pData->rdh.rcBound.left = x0;
//							if (y < pData->rdh.rcBound.top)
//								pData->rdh.rcBound.top = y;
//							if (x > pData->rdh.rcBound.right)
//								pData->rdh.rcBound.right = x;
//							if (y+1 > pData->rdh.rcBound.bottom)
//								pData->rdh.rcBound.bottom = y+1;
//							pData->rdh.nCount++;
//
//							// On Windows98, ExtCreateRegion() may fail if the number of rectangles is too
//							// large (ie: > 4000). Therefore, we have to create the region by multiple steps.
//							if (pData->rdh.nCount == 2000)
//							{
//								HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), pData);
//								if (hRgn)
//								{
//									CombineRgn(hRgn, hRgn, h, RGN_OR);
//									DeleteObject(h);
//								}
//								else
//									hRgn = h;
//								pData->rdh.nCount = 0;
//								SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);
//							}
//						}
//					}
//					p32 -= bm32.bmWidthBytes;
//				}
//				HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), pData);
//				if (hRgn)
//				{
//					CombineRgn(hRgn, hRgn, h, RGN_OR);
//					DeleteObject(h);
//				}
//				else hRgn = h;
//
//				// Clean up
//				GlobalFree(hData);
//				SelectObject(hDC, holdBmp);
//				DeleteDC(hDC);
//			}
//			DeleteObject(SelectObject(hMemDC, holdBmp));
//		}
//		DeleteDC(hMemDC);
//	}    
//
//	return hRgn;
//}
////bmp转换成区域
//HRGN CreateRegionFromBitmap(HBITMAP hBitmap, COLORREF transparentColor)
//{
//	HRGN hRgn = NULL;
//	HRGN hRgn1 = NULL;
//
//	// Check for valid bitmap handle
//	if ( hBitmap != NULL )
//	{
//		// Get bitmap object information
//		BITMAP bitmap;
//		GetObject(hBitmap, sizeof(BITMAP), &bitmap);
//		DWORD dwSize = bitmap.bmHeight * bitmap.bmWidthBytes;
//		int bitsPixel = bitmap.bmBitsPixel / 8;
//
//		// Check bitmap color depth (only 24 or 32 bits per pixel allowed)
//		if ( ( bitsPixel == 3 ) || ( bitsPixel == 4 ) )
//		{
//			// Get bitmap bits
//			unsigned char* pBits = new unsigned char[dwSize];
//			GetBitmapBits(hBitmap, dwSize, pBits);
//
//			// Create region from bitmap
//			unsigned char red, green, blue;
//			for ( int y=0; y<bitmap.bmHeight; y++ )
//			{
//				for ( int x=0; x<bitmap.bmWidth; x++ )
//				{
//					// Get pixel color
//					blue = pBits[y*bitmap.bmWidthBytes + bitsPixel*x];
//					green = pBits[y*bitmap.bmWidthBytes + bitsPixel*x+1];
//					red = pBits[y*bitmap.bmWidthBytes + bitsPixel*x+2];
//
//					// Check transparent color
//					if ( RGB(red,green,blue) != transparentColor )
//					{
//						// Combine regions
//						if ( hRgn == NULL )
//							hRgn = CreateRectRgn(x, y, x+1, y+1);
//						else
//						{
//							// Delete temporary region
//							if ( hRgn1 != NULL )
//								DeleteObject(hRgn1);
//
//							// Create temporary region
//							hRgn1 = CreateRectRgn(x, y, x+1, y+1);
//
//							// Combine regions
//							CombineRgn(hRgn, hRgn, hRgn1, RGN_OR);
//						}
//					}
//				}
//			}
//
//			// Free bitmap bits
//			delete pBits;
//		}
//	}
//
//	// Delete temporary region
//	if ( hRgn1 != NULL )
//		DeleteObject(hRgn1);
//
//	return hRgn;
//}
///*****************************************************
////实现图片不规则半透明
////destdc 目标dc
////dx 目标x坐标
////dy 目标y坐标
////cx 宽度
////cy 高度
////srcdc 源dc
////sx 源x坐标
////sy 源y坐标
////crTransparent 要被透明的颜色
////SourceConstantAlpha 其它颜色透明度 0 ~ 255
//返回true表示成功 , false 表示失败
//*****************************************************/
//bool AFCAlphaBlend(HDC destdc, int dx, int dy, int cx, int cy, HDC srcdc, int sx, int sy, COLORREF crTransparent, int SourceConstantAlpha)
//{
//	HDC dc;
//	dc = CreateCompatibleDC(destdc);
//	HBITMAP bitmap;
//	bitmap = CreateCompatibleBitmap(destdc,cx,cy);
//	SelectObject(dc,bitmap);
//	StretchBlt(dc,0,0,cx,cy,destdc,dx,dy,cx,cy,SRCCOPY);
//
//	::TransparentBlt(dc,0,0,cx,cy,srcdc,sx,sy,cx,cy,crTransparent);
//
//	BLENDFUNCTION bl;
//	bl.BlendOp = AC_SRC_OVER;
//	bl.BlendFlags = 0;
//	bl.SourceConstantAlpha = SourceConstantAlpha;
//	bl.AlphaFormat = 0; 
//	BOOL result = AlphaBlend(destdc,dx,dy,cx,cy,dc,0,0,cx,cy,bl);
//	DeleteObject(bitmap);
//	DeleteDC(dc);
//	return result;
//}
//
//
////保存截图
//void SaveScreen()
//{
//	HBITMAP hbitmap=CopyScreenToBitmap();
//	TCHAR name[MAX_PATH];
//	SYSTEMTIME st;
//	GetLocalTime(&st);
//	GetCurrentDirectory(MAX_PATH,name);
//	lstrcat(name,"\\截图");
//	::CreateDirectory(name,NULL);
//	wsprintf(name,TEXT("%s\\%d-%d-%d-%d-%d-%d.bmp"),name,st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
//	SaveBitmapToFile(hbitmap,name);
//}
//
////copy屏
//HBITMAP CopyScreenToBitmap()   
//{   
//	HDC	hScrDC,hMemDC;
//	HBITMAP	hBitmap,hOldBitmap;
//	int               nX,   nY,   nX2,   nY2; 
//	int               nWidth,   nHeight;              
//	int               xScrn,   yScrn;  
//	hScrDC   =   CreateDC(TEXT("DISPLAY"),   NULL,   NULL,   NULL);
//	hMemDC   =   CreateCompatibleDC(hScrDC);   
//
//	xScrn   =   GetDeviceCaps(hScrDC,   HORZRES);   
//	yScrn   =   GetDeviceCaps(hScrDC,   VERTRES);   
//	nX   =   0;   
//	nY   =   0; 
//	nX2   =   xScrn;   
//	nY2   =   yScrn;   
//	nWidth   =   nX2   -   nX;   
//	nHeight   =   nY2   -   nY;   
//
//	hBitmap   =   CreateCompatibleBitmap(hScrDC,   nWidth,   nHeight);
//	hOldBitmap   =   (HBITMAP)SelectObject(hMemDC,   hBitmap);
//	BitBlt(hMemDC,   0,   0,   nWidth,   nHeight,   
//		hScrDC,   nX,   nY,   SRCCOPY);   
//	hBitmap   =   (HBITMAP)SelectObject(hMemDC,   hOldBitmap);
//	DeleteDC(hScrDC);   
//	DeleteDC(hMemDC); 
//	return   hBitmap;   
//}
//
////保存截图文件
//int  SaveBitmapToFile(HBITMAP   hBitmap  ,LPTSTR   lpFileName)   
//{ 
//	if(!hBitmap)
//	{
//		DeleteObject(hBitmap);
//		return 0;
//	}
//	HDC                         hDC;                     
//	int                         iBits;
//	int						wBitCount; 
//	DWORD          dwPaletteSize=0, dwBmBitsSize, 	dwDIBSize,   dwWritten;   
//	BITMAP                     Bitmap;                   
//	//位图属性结构   
//	BITMAPFILEHEADER       bmfHdr;                   
//	//位图文件头结构   
//	BITMAPINFOHEADER       bi;                           
//	//位图信息头结构     
//	LPBITMAPINFOHEADER   lpbi;                       
//	//指向位图信息头结构   
//	HANDLE                     fh,   hDib,   hPal,hOldPal=NULL;  
//	hDC   =   CreateDC(TEXT("DISPLAY"),NULL,NULL,NULL);   
//	iBits   =   GetDeviceCaps(hDC,BITSPIXEL)*GetDeviceCaps(hDC, PLANES);   
//	DeleteDC(hDC);   
//	if   (iBits<= 1)   
//		wBitCount =  1;   
//	else   if(iBits  <=  4)   
//		wBitCount   =   4;   
//	else   if(iBits  <=  8)   
//		wBitCount   =   8;   
//	else   if(iBits <=  24)   
//		wBitCount   =   24;  
//	else if(iBits <=  32) 
//	{
//		wBitCount   =   32; 
//	}
//	else
//	{
//		DeleteObject(hBitmap);
//		::ReleaseDC(NULL,hDC);
//		return 0;
//	}
//	if(wBitCount <=8)   
//		dwPaletteSize   =   (1  <<  wBitCount) *sizeof(RGBQUAD);   
//	//设置位图信息头结构   
//	GetObject(hBitmap,   sizeof(BITMAP),   (LPSTR)&Bitmap);   
//	bi.biSize                         =   sizeof(BITMAPINFOHEADER);   
//	bi.biWidth                       =   Bitmap.bmWidth;   
//	bi.biHeight                     =   Bitmap.bmHeight; 
//	if(Bitmap.bmWidth<=0||Bitmap.bmWidth>2000||Bitmap.bmHeight<=0||Bitmap.bmHeight>2000)
//	{
//		DeleteObject(hBitmap);
//		::ReleaseDC(NULL,hDC);
//		return 0;
//	}
//	bi.biPlanes                     =   1;   
//	bi.biBitCount                   =   wBitCount;   
//	bi.biCompression             =   BI_RGB;   
//	bi.biSizeImage                 =   0;   
//	bi.biXPelsPerMeter           =   0;   
//	bi.biYPelsPerMeter           =   0;   
//	bi.biClrUsed                   =   0;   
//	bi.biClrImportant             =   0;   
//	dwBmBitsSize   =   ((Bitmap.bmWidth  * wBitCount+31)/32)* 4 *Bitmap.bmHeight ;   
//	//为位图内容分配内存   
//	hDib     =   GlobalAlloc(GHND,dwBmBitsSize+   
//		dwPaletteSize+sizeof(BITMAPINFOHEADER));   
//	if(!hDib)
//	{
//		DeleteObject(hBitmap);
//		::ReleaseDC(NULL,hDC);
//		return 0;
//	}
//	lpbi   =   (LPBITMAPINFOHEADER)GlobalLock(hDib);   
//	*lpbi   =   bi;   
//	//   处理调色板         
//	hPal   =   GetStockObject(DEFAULT_PALETTE);   
//	if   (hPal)   
//	{   
//		hDC     =   ::GetDC(NULL);   
//		hOldPal   =   SelectPalette(hDC,   (HPALETTE)hPal,   FALSE);   
//		RealizePalette(hDC);   
//	}   
//	//   获取该调色板下新的像素值   
//	GetDIBits(hDC,   hBitmap,   0,   (UINT)   Bitmap.bmHeight,   
//		(LPSTR)lpbi   +   sizeof(BITMAPINFOHEADER)   
//		+dwPaletteSize,   
//		(LPBITMAPINFO)lpbi,   DIB_RGB_COLORS);   
//	//恢复调色板         
//	if(hOldPal)   
//	{   
//		SelectPalette(hDC,   (HPALETTE)hOldPal,   TRUE);   
//		RealizePalette(hDC);   
//		::ReleaseDC(NULL,   hDC);   
//	}   
//	//创建位图文件           
//	fh   =   CreateFile(lpFileName, GENERIC_WRITE,0,  NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,   NULL);   
//	if(fh   ==   INVALID_HANDLE_VALUE)   
//	{
//		GlobalUnlock(hDib);   
//		GlobalFree(hDib);   
//		DeleteObject(hBitmap);
//		::ReleaseDC(NULL,hDC);
//		return   FALSE;   
//	}
//	//   设置位图文件头   
//	bmfHdr.bfType   =   0x4D42; 
//	dwDIBSize		=   sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+  dwPaletteSize + dwBmBitsSize;       
//	bmfHdr.bfSize   =   dwDIBSize;   
//	bmfHdr.bfReserved1   =   0;   
//	bmfHdr.bfReserved2   =   0;   
//	bmfHdr.bfOffBits   =   (DWORD)sizeof (BITMAPFILEHEADER)+(DWORD)sizeof(BITMAPINFOHEADER) +  dwPaletteSize;   
//	WriteFile(fh,   (LPSTR)&bmfHdr,   sizeof(BITMAPFILEHEADER),   &dwWritten,   NULL);   
//	WriteFile(fh,  (LPSTR)lpbi,   dwDIBSize,&dwWritten,   NULL);   
//	//清除         
//	GlobalUnlock(hDib);   
//	GlobalFree(hDib); 
//	DeleteObject(hBitmap);
//	::ReleaseDC(NULL,hDC);
//	CloseHandle(fh); 
//	return 0;
//}
////根据字符串长度来载取字符
//bool GetChar(TCHAR * src, TCHAR * dest, int count)
//{
//	int j=0;
//	byte a,b;
//	int i,cn=0,en=0;
//	for(i=0; i<count && i<lstrlen(src); )
//	{
//		a=src[i];
//		b=src[i+1];
//		//判断是否汉字
//		if((a>=176&&a<=247&&b>=160&&b<=254)||//GB2312
//			(((a>=129&&a<=255)||(a>=64&&a<=126))&&b>=161&&b<=254)||///GB5
//			(a>=129&&a<=254&&b>=64&&b<=254))//GBK
//		{
//			i += 2;
//			cn++;
//			if(en+cn>4)
//				break;
//		}
//		else
//		{
//			i++ ;
//			en++;
//			if(en+cn>count)
//				break;
//		}
//	}
//	memcpy(dest,src,i);
//	dest[i]='\0';
//	return true;
//}

////删除
//void Dellog(int iRoomID,int iSmallRoomID)
//{
//	TCHAR szFileName	[50];
//	wsprintf(szFileName,"%d-%d.txt",iRoomID,iSmallRoomID);
//	try
//	{
//		::DeleteFile(szFileName);
//	}
//	catch(...)
//	{
//		return ;
//	}
//	return ;
//}
//写正常日志
void WriteStr(CString str,int iRoomID,int iSmallRoomID)
{

	TCHAR sz[MAX_PATH];
	try
	{
		wsprintf(sz,"%s",str);
		WriteStr(sz,iRoomID,iSmallRoomID);
	}
	catch(...)
	{
		return ;
	}
}
//写正常日志
void WriteStr(TCHAR *str,int iRoomID,int iSmallRoomID)
{
	try
	{
		CFile file;
		TCHAR szFileName	[50];
		TCHAR szNewLine[]="\r\n";
		wsprintf(szFileName,"%d-%d.txt",iRoomID,iSmallRoomID);
		file.Open(szFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);//建立新文件
		file.SeekToEnd();
		file.Write(szNewLine,strlen(szNewLine));			//换行	
		file.Write(str,strlen(str));						//写入游戏信息
		file.Close();
	}
	catch(CException *e)
	{		
		//AfxMessageBox("some exception!");
		e->Delete();
		return ; 
	}
}
////写错误日志
//void  WriteError(TCHAR *pMessage ,int iRoomID,int iSmallRoomID )
//{
//	try
//	{
//		char FileName[50];
//		TCHAR path[MAX_PATH];
//		GetCurrentDirectory (MAX_PATH,path);
//		wsprintf(FileName,"%s\\Error%d-%d.txt\0",path,iRoomID,iSmallRoomID);//GetCurrentProcessId());
//		CFile syslog;
//		syslog.Open(FileName,CFile::modeNoTruncate| CFile::modeCreate |CFile::modeReadWrite);
//		syslog.SeekToEnd();
//		syslog.Write(pMessage,strlen(pMessage));
//
//		syslog.SeekToEnd();
//		TCHAR nextLine[] = "\r\n";
//		syslog.Write(nextLine,strlen(nextLine));
//
//		syslog.Close();
//	}
//	catch(CException *e)
//	{		
//		//AfxMessageBox("some exception!");
//		e->Delete();
//		return ; 
//	}
//}
