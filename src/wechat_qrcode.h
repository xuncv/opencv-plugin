#pragma once

#include "include_opencv.h"

#pragma region WeChatQRCode

CVAPI(ExceptionStatus) wechat_qrcode_WeChatQRCode_new(const char* detector_prototxt_path,const char* detector_caffe_model_path,
	const char* super_resolution_prototxt_path,const char* super_resolution_caffe_model_path,cv::wechat_qrcode::WeChatQRCode **returnValue)
{
	BEGIN_WRAP
	*returnValue = new cv::wechat_qrcode::WeChatQRCode(detector_prototxt_path, detector_caffe_model_path, super_resolution_prototxt_path, super_resolution_caffe_model_path);
	END_WRAP
}

CVAPI(ExceptionStatus)wechat_qrcode_WeChatQRCode_detectAndDecode(cv::wechat_qrcode::WeChatQRCode *obj, cv::_InputArray *img, std::vector<cv::Mat>* points, std::vector<std::string> **returnValue,size_t *retLen) {
	BEGIN_WRAP
	const std::vector<std::string> lists = obj->detectAndDecode(*img, *points);
	*returnValue = new std::vector<std::string>();
	(*returnValue)->assign(lists.begin(), lists.end());
	*retLen = lists.size();
	END_WRAP
}

CVAPI(ExceptionStatus)wechat_qrcode_extractResult(std::vector<std::string>* vec, int index,char **returnValue) {
	BEGIN_WRAP
	std::string text = (vec)->at(index);
	memcpy(returnValue, (void*)text.c_str(), text.length());
	END_WRAP
}

CVAPI(ExceptionStatus)wechat_qrcode_deleteResult(std::vector<std::string>* vec) {
	BEGIN_WRAP
	delete vec;
	END_WRAP
}

CVAPI(ExceptionStatus)wechat_qrcode_WeChatQRCode_delete(cv::wechat_qrcode::WeChatQRCode* obj) 
{
	BEGIN_WRAP
	delete obj;
	END_WRAP
}

#pragma endregion WeChatQRCode