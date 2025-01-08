/*
 * @Author: love-yuri yuri2078170658@gmail.com
 * @Date: 2024-12-30 15:27:02
 * @LastEditTime: 2024-12-31 13:53:09
 * @Description: vector 测试
 */
#define DEBUG_LOG

#include "../vector.hpp"
#include "../yuri_log.hpp"
#include <algorithm>

int main() {
	yuriSTL::vector<int> v;
	for (int i = 0; i < 20; i++) {
		v.push_back(i);
	}

	v[8] = 888; // 修改测试
	// v.at(99); // 越界测试
	log_info << v;
	log_info << "size: " << v.size();
	log_info << "capacity: " << v.capacity();
	log_info << "empty: " << v.empty();
	log_info << "front: " << v.front();
	log_info << "back: " << v.back();

	// 弹出测试

	// 算法测试
	std::sort(v.begin(), v.end());
	log_info << v;

	return 0;
}