/*
 * @Author: love-yuri yuri2078170658@gmail.com
 * @Date: 2024-12-30 15:27:02
 * @LastEditTime: 2025-01-09 16:14:54
 * @Description: vector 测试
 */
#define DEBUG_LOG

#include "../vector.hpp"
#include "../yuri_log.hpp"
#include <string>
#include <algorithm>

using std::string;

class Person {

public:
	int age;
	string name;
	Person() {
		log_info << "默认构造函数";
		age = 0;

		name = "default";
	}

	Person(int age) {
		log_info << "默认构造函数 " << age;
		this->age = age;
		name = "default-age";
	}

	Person(string&& name, int age) {
		log_info << "默认构造函数";
		this->age = age;
		this->name = name;
	}

	Person(const Person& p) {
		log_info << "拷贝构造函数";
		this->age = p.age;
		this->name = p.name;
	}

	Person(Person&& p) noexcept {
		log_info << "移动构造函数";
		this->age = p.age;
		this->name = p.name;
	}

	Person& operator=(const Person& p) {
		log_info << "= 号构造函数";
		this->age = p.age;
		this->name = p.name;
		return *this;
	}

	~Person() {
		log_info << this->name << " 被析构啦 " << "age : " << this->age;
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << "\nname: " << p.name << " age: " << p.age << " --- \n";
	return os;
}

int main() {
	yuri::vector<int> v;
	yuri::vector<Person> v2;
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
	v.pop_back();
	v.pop_back();

	// 算法测试
	std::sort(v.begin(), v.end());
	log_info << v;
	v.clear();
	log_info << "v.size -> " << v.size();

	v2.push_back(Person("张三", 18));
	v2.push_back(Person("李四", 19));
	v2.clear(); // 析构测试
	log_info << "v2.size -> " << v2.size();
	log_info << "程序结束 ----------------- 程序结束";
	return 0;
}