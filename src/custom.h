#pragma once
#include <windows.h>
#include <string>
#include "include_opencv.h"

using namespace cv;

void GetStringSize(HDC hDC, const char* str, int* w, int* h);
void putTextZH(Mat dst, const char* str, Point org, Scalar color, int fontSize,
    const char* fn = "Arial", bool italic = false, bool underline = false);

void putTextZh(
    cv::InputOutputArray     img,
    const char* text,
    Point     org,
    int     fontSize,
    Scalar     color,
    const char* font = "Arial",
    bool italic = false,
    bool underline = false);

CVAPI(ExceptionStatus) imgproc_putTextZh(cv::_InputOutputArray *img, const char* text, MyCvPoint* org,
    int fontSize, MyCvScalar* color,
    const char* font, bool italic = false, bool underline = false)
{
    BEGIN_WRAP
        putTextZh(*img, text, cpp(*org), fontSize, cpp(*color), font, italic, underline);
    END_WRAP
}