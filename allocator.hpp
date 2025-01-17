/*
 * @Author: love-yuri yuri2078170658@gmail.com
 * @Date: 2024-12-30 13:41:33
 * @LastEditTime: 2024-12-30 14:16:34
 * @Description: 内存分配器
 */
#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "base.hpp" // 包含一下常用的函数 如 move forward
namespace yuri {

/*
    该类实现了 容器内存的创建 分配 初始化操作
*/
template <typename T>
class Allocator {
public:
	typedef T value_type; // 基础数据类型
	typedef T* pointer;   // 基础数据指针

public:
	Allocator() = default;
	~Allocator() = default;

	// 分配size个空间
	static pointer allocate(size_type size) noexcept {
		if (size == 0) {
			return nullptr;
		}
		return static_cast<pointer>(::operator new(size * sizeof(value_type)));
	}

	static pointer allocate() noexcept {
		return static_cast<pointer>(::operator new(sizeof(value_type)));
	}

	// 销毁空间函数
	static void deallocate(pointer ptr) noexcept {
		// 如果他是nullptr 就不同调用delete
		if (ptr == nullptr) {
			return;
		}
		// 前面申请的空间都必须用 operator delete删除
		::operator delete(ptr);
	}

	static void deallocate(pointer ptr, [[maybe_unused]] size_type size) noexcept {
		if (ptr == nullptr) {
			return;
		}
		::operator delete(ptr);
	}

	// 构造初始化空间的函数
	template <typename... Args>
	static void construct(pointer ptr, Args&&... args) noexcept {
		// 构造类的时候可能有多个参数，这些参数可能是左值，可能是右值，所以我们需要完美转发
		// 完美转发需要配合万能引用使用，所以Args 必须是 &&
		::new (ptr) value_type(yuri::forward<Args>(args)...);
	}

	// 调用类的析构函数
	static void destroy(pointer ptr) noexcept { yuri::destroy(ptr); }

	// 通过迭代器析构对象
	static void destroy(pointer start, pointer end) noexcept {
		yuri::destroy(start, end);
	}
};

} // namespace yuri

#endif // ALLOCATOR_H