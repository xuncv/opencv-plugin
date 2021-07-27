#pragma once
#include "include_opencv.h"

CVAPI(ExceptionStatus) barcode_Barcode_new(const char* super_resolution_prototxt_path, const char* super_resolution_caffe_model_path, cv::barcode::BarcodeDetector **returnvalue)
{
	BEGIN_WRAP
	*returnvalue = new cv::barcode::BarcodeDetector(super_resolution_prototxt_path, super_resolution_caffe_model_path);
	END_WRAP
}

CVAPI(ExceptionStatus) barcode_Barcode_detectAndDecode(cv::barcode::BarcodeDetector* obj, cv::_InputArray* img,  std::vector<std::string>* lists,std::vector<cv::Point>* points )
{
	BEGIN_WRAP
	std::vector<cv::barcode::BarcodeType> decode_type;
	obj->detectAndDecode(*img, *lists, decode_type,*points);
	END_WRAP
}

CVAPI(ExceptionStatus) barcode_Barcode_delete(cv::barcode::BarcodeDetector* obj)
{
	BEGIN_WRAP
	delete obj;
	END_WRAP
}