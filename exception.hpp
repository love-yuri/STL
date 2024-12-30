/*
 * @Author: love-yuri yuri2078170658@gmail.com
 * @Date: 2024-12-30 16:29:23
 * @LastEditTime: 2024-12-30 16:35:33
 * @Description: 常用异常
 */
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>
#include <string_view>

/* 通用业务错误 */
class BizException : public std::exception {
	std::string msg;
	
public:
	explicit BizException(std::string_view msg)
	  : msg(msg) {}
	
	const char* what() const noexcept override {
		return msg.c_str();
  }
};

#endif