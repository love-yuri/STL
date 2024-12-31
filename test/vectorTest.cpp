/*
 * @Author: love-yuri yuri2078170658@gmail.com
 * @Date: 2024-12-30 15:27:02
 * @LastEditTime: 2024-12-31 09:37:14
 * @Description: vector 测试
 */
#include "../yuri_log.hpp"
#include "../vector.hpp"
#include <algorithm>

int main() {
	yuriSTL::vector<int> v;
	for (int i = 0; i < 20; i++) {
		v.push_back(i);
	}

	v[8] = 888; // 修改测试
	// v.at(99); // 越界测试
	yinfo << v;
	yinfo << "size: " << v.size();
	yinfo << "capacity: " << v.capacity();
	yinfo << "empty: "  << v.empty();
	yinfo << "front: " << v.front();
	yinfo << "back: " << v.back();

	// 弹出测试

	// 算法测试
	std::sort(v.begin(), v.end());
	yinfo << v;

	return 0;
}