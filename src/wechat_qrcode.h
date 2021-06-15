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

CVAPI(ExceptionStatus)wechat_qrcode_WeChatQRCode_detectAndDecode(cv::wechat_qrcode::WeChatQRCode *obj, cv::_InputArray *img, std::vector<cv::Mat>* points, std::vector<std::string> * lists) {
	BEGIN_WRAP
	const auto res = obj->detectAndDecode(*img, *points);
	lists->clear();
	lists->resize(res.size());
	lists->assign(res.begin(), res.end());
	END_WRAP
}

CVAPI(ExceptionStatus)wechat_qrcode_WeChatQRCode_delete(cv::wechat_qrcode::WeChatQRCode* obj) 
{
	BEGIN_WRAP
	delete obj;
	END_WRAP
}

#pragma endregion WeChatQRCode