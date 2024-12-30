/*
 * @Author: love-yuri yuri2078170658@gmail.com
 * @Date: 2024-12-30 15:27:02
 * @LastEditTime: 2024-12-30 15:43:59
 * @Description: vector 测试
 */
#include "../yuri_log.hpp"
#include "../vector.hpp"

int main() {
	yuriSTL::vector<int> v;
	for (int i = 0; i < 20; i++) {
		v.push_back(i);
	}

	yinfo << "size: " << v.size();
	yinfo << "capacity: " << v.capacity();
	yinfo << v;
	return 0;
}