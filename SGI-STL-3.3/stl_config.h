/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 * Copyright (c) 1997
 * Silicon Graphics
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 */

#ifndef __STL_CONFIG_H
# define __STL_CONFIG_H

//标志：
//*__STL_NO_BOOL：如果编译器没有内置 bool 则定义
//类型。
//*__STL_HAS_WCHAR_T：定义编译器是否将 wchar_t 作为内置类型。
//*__STL_NO_DRAND48：如果编译器没有drand48则定义
//功能。
//*__STL_STATIC_TEMPLATE_MEMBER_BUG：如果编译器无法处理则定义
//模板类的静态成员。
//*__STL_STATIC_CONST_INIT_BUG：如果编译器不能处理一个定义
//静态常量数据成员声明中的常量初始化器
//整数类型。 （参见 C++ 标准第 9.4.2 节第 4 段。）
//*__STL_CLASS_PARTIAL_SPECIALIZATION：如果编译器支持则定义
//模板类的部分特化。
//*__STL_PARTIAL_SPECIALIZATION_SYNTAX：如果编译器定义
//支持完全专业化的部分专业化语法
//类模板。 （即使它实际上不支持部分
//专业本身。）
//*__STL_FUNCTION_TMPL_PARTIAL_ORDER：如果编译器支持则定义
//函数模板的部分排序。 （又名部分专业化
//函数模板。）
//*__STL_MEMBER_TEMPLATES：定义编译器是否支持模板
//类的成员函数。
//*__STL_MEMBER_TEMPLATE_CLASSES：如果编译器支持则定义
//作为其他类的成员模板的嵌套类。
//*__STL_TEMPLATE_FRIENDS：定义编译器是否支持模板化
//朋友声明。
//*__STL_EXPLICIT_FUNCTION_TMPL_ARGS：如果编译器定义
//支持通过提供模板调用函数模板
//明确论证。
//*__STL_LIMITED_DEFAULT_TEMPLATES：如果编译器无法定义
//处理依赖于先前模板的默认模板参数
//参数。
//*__STL_NON_TYPE_TMPL_PARAM_BUG：定义编译器是否有问题
//非类型模板参数的函数模板参数推导。
//*__SGI_STL_NO_ARROW_OPERATOR: 如果编译器无法定义
//支持迭代器的 -> 运算符。
//*__STL_DEFAULT_CONSTRUCTOR_BUG：如果 T() 不能正常工作则定义
//当 T 是内置类型时。
//*__STL_USE_EXCEPTIONS：如果编译器定义（在当前编译中
//模式）支持异常。
//*__STL_USE_NAMESPACES：如果编译器有必要的定义
//支持命名空间。
//*__STL_NO_EXCEPTION_HEADER：定义如果编译器没有
//符合标准的标头 <exception>。
//*__STL_NO_BAD_ALLOC：如果编译器没有<new>定义
//标头，或者如果 <new> 不包含 bad_alloc 类。如果一个 bad_alloc
//类存在，假定它在命名空间 std 中。
//*__STL_SGI_THREADS：定义是否为 SGI IRIX 编译
//多线程模式下的系统，使用本地 SGI 线程而不是
//线程。
//*__STL_WIN32THREADS：定义是否在 WIN32 上编译
//多线程模式下的编译器。
//*__STL_PTHREADS：定义我们是否应该使用可移植的 pthreads
//同步。
//*__STL_UITHREADS：定义我们是否应该使用 UI /solaris /UnixWare 线程
//同步。 UIthreads 类似于 pthreads，但是基于
//在早期版本的 Posix 线程标准上。
//*__STL_LONG_LONG 如果编译器有 long long 和 unsigned long long
//类型。 （它们不在 C++ 标准中，但它们应该是
//包含在即将发布的 C9X 标准中。）
//*如果需要线程安全，则定义 __STL_THREADS。
//*__STL_VOLATILE 被定义为“volatile”，如果线程被
//使用，否则为空字符串。
//*__STL_USE_CONCEPT_CHECKS 启用一些额外的编译时错误
//检查以确保用户定义的模板参数满足
//所有适当的要求。这可能会导致更多
//可理解的错误信息。它不会产生运行时开销。这
//功能需要成员模板和部分专业化。
//*__STL_NO_USING_CLAUSE_IN_CLASS：编译器不处理“使用”
//类定义中的子句。
//*__STL_NO_FRIEND_TEMPLATE_CLASS: 编译器不处理友元
//friend 是模板类的声明。
//*__STL_NO_FUNCTION_PTR_IN_CLASS_TEMPLATE：编译器不
//支持使用函数指针类型作为参数
//为模板。
//*__STL_MEMBER_TEMPLATE_KEYWORD: 标准 C++ 需要模板
//一些新地方 (14.2.4) 中的关键字。这个标志是为
//支持（并要求）这种用法的编译器。
//控制编译的用户可设置宏：
//*__STL_USE_SGI_ALLOCATORS：如果定义了，那么STL将使用旧的
//SGI 风格的分配器，而不是符合标准的分配器，
//即使编译器支持所有需要的语言特性
//用于符合标准的分配器。
//*__STL_NO_NAMESPACES: 如果定义了，不要将库放在命名空间中
//std，即使编译器支持命名空间。
//*__STL_NO_RELOPS_NAMESPACE: 如果定义了，不要把关系
//命名空间 std::rel_ops 中的运算符模板 (>, <=. >=, !=)，甚至
//如果编译器支持命名空间和部分排序
//功能模板。
//*__STL_ASSERTIONS：如果已定义，则启用运行时检查
//__stl_assert 宏。
//*_PTHREADS：如果已定义，则使用 Posix 线程来支持多线程。
//*_UITHREADS:如果定义，使用 SCO/Solaris/UI 线程进行多线程处理
//支持
//*_NOTHREADS：如果已定义，则不使用任何多线程支持。
//*_STL_NO_CONCEPT_CHECKS：如果定义，则禁用错误检查
//我们从 __STL_USE_CONCEPT_CHECKS 得到。
//*__STL_USE_NEW_IOSTREAMS：如果定义了，那么STL将使用新的，
//符合标准的 iostream（例如 <iosfwd> 标头）。如果不
//定义后，STL 将使用旧的 cfront 风格的 iostream（例如
//<iostream.h> 标头）。
//该文件定义的其他宏：
//*bool、true 和 false，如果定义了 __STL_NO_BOOL。
//*typename，如果它还不是关键字，则作为空宏。
//*显式，如果它还不是关键字，则作为空宏。
//*命名空间相关的宏（__STD、__STL_BEGIN_NAMESPACE 等）
//*与异常相关的宏（__STL_TRY、__STL_UNWIND 等）
//*__stl_assert，作为测试或空宏，具体取决于
//__STL_ASSERTIONS 是否被定义。

# if defined(_PTHREADS) && !defined(_NOTHREADS)
#     define __STL_PTHREADS
# endif

# if defined(_UITHREADS) && !defined(_PTHREADS) && !defined(_NOTHREADS)
#     define __STL_UITHREADS
# endif

# if defined(__sgi) && !defined(__GNUC__)
#   include <standards.h>
#   if !defined(_BOOL)
#     define __STL_NO_BOOL
#   endif
#   if defined(_MIPS_SIM) && _MIPS_SIM == _ABIO32
#     define __STL_STATIC_CONST_INIT_BUG
#   endif
#   if defined(_WCHAR_T_IS_KEYWORD)
#     define __STL_HAS_WCHAR_T 
#   endif
#   if !defined(_TYPENAME_IS_KEYWORD)
#     define __STL_NEED_TYPENAME
#   endif
#   ifdef _PARTIAL_SPECIALIZATION_OF_CLASS_TEMPLATES
#     define __STL_CLASS_PARTIAL_SPECIALIZATION
#   endif
#   if (_COMPILER_VERSION >= 730) && defined(_MIPS_SIM) && _MIPS_SIM != _ABIO32
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER
#   endif
#   ifdef _MEMBER_TEMPLATES
#     define __STL_MEMBER_TEMPLATES
#     define __STL_TEMPLATE_FRIENDS
#     define __STL_MEMBER_TEMPLATE_CLASSES
#   endif
#   if defined(_MEMBER_TEMPLATE_KEYWORD)
#     define __STL_MEMBER_TEMPLATE_KEYWORD
#   endif
#   if defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_EXPLICIT_FUNCTION_TMPL_ARGS
#   endif
#   if (_COMPILER_VERSION >= 730) && defined(_MIPS_SIM) && _MIPS_SIM != _ABIO32
#     define __STL_MEMBER_TEMPLATE_KEYWORD
#   endif
#   if COMPILER_VERSION < 720 || (defined(_MIPS_SIM) && _MIPS_SIM == _ABIO32)
#     define __STL_DEFAULT_CONSTRUCTOR_BUG
#   endif
#   if !defined(_EXPLICIT_IS_KEYWORD)
#     define __STL_NEED_EXPLICIT
#   endif
#   ifdef __EXCEPTIONS
#     define __STL_USE_EXCEPTIONS
#   endif
#   if (_COMPILER_VERSION >= 721) && defined(_NAMESPACES)
#     define __STL_HAS_NAMESPACES
#   endif 
#   if (_COMPILER_VERSION < 721) || \
    !defined(__STL_HAS_NAMESPACES) || defined(__STL_NO_NAMESPACES)
#     define __STL_NO_EXCEPTION_HEADER
#   endif
#   if _COMPILER_VERSION < 730 || !defined(_STANDARD_C_PLUS_PLUS) || \
      !defined(_NAMESPACES)
#     define __STL_NO_BAD_ALLOC
#   endif
#   if !defined(_NOTHREADS) && !defined(__STL_PTHREADS)
#     define __STL_SGI_THREADS
#   endif
#   if defined(_LONGLONG) && defined(_SGIAPI) && _SGIAPI
#     define __STL_LONG_LONG
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_USE_NEW_IOSTREAMS
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_CAN_THROW_RANGE_ERRORS
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __SGI_STL_USE_AUTO_PTR_CONVERSIONS
#   endif
# endif


/*
 * Jochen Schlick '1999  - added new #defines (__STL)_UITHREADS (for 
 *                         providing SCO / Solaris / UI thread support)
 *                       - added the necessary defines for the SCO UDK 7 
 *                         compiler (and its template friend behavior)
 *                       - all UDK7 specific STL changes are based on the 
 *                         macro __USLC__ being defined
 */
// SCO UDK 7 compiler (UnixWare 7x, OSR 5, UnixWare 2x)
# if defined(__USLC__)
#     define __STL_HAS_WCHAR_T 
#     define __STL_CLASS_PARTIAL_SPECIALIZATION
#     define __STL_PARTIAL_SPECIALIZATION_SYNTAX
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER
#     define __STL_MEMBER_TEMPLATES
#     define __STL_MEMBER_TEMPLATE_CLASSES
#     define __STL_USE_EXCEPTIONS
#     define __STL_HAS_NAMESPACES
#     define __STL_USE_NAMESPACES
#     define __STL_LONG_LONG
#     if defined(_REENTRANT)
#           define _UITHREADS     /* if      UnixWare < 7.0.1 */
#           define __STL_UITHREADS
//   use the following defines instead of the UI threads defines when
//   you want to use POSIX threads
//#         define _PTHREADS      /* only if UnixWare >=7.0.1 */
//#         define __STL_PTHREADS
#     endif
# endif



# ifdef __GNUC__
#   if __GNUC__ == 2 && __GNUC_MINOR__ <= 7
#     define __STL_STATIC_TEMPLATE_MEMBER_BUG
#   endif
#   if __GNUC__ < 2 
#     define __STL_NEED_TYPENAME
#     define __STL_NEED_EXPLICIT
#   endif
#   if __GNUC__ == 2 && __GNUC_MINOR__ <= 8
#     define __STL_NO_EXCEPTION_HEADER
#     define __STL_NO_BAD_ALLOC
#   endif
#   if __GNUC__ == 2 && __GNUC_MINOR__ >= 8
#     define __STL_CLASS_PARTIAL_SPECIALIZATION
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER
#     define __STL_EXPLICIT_FUNCTION_TMPL_ARGS
#     define __STL_MEMBER_TEMPLATES
#     define __STL_CAN_THROW_RANGE_ERRORS
      //    g++ 2.8.1 supports member template functions, but not member
      //    template nested classes.
#     if __GNUC_MINOR__ >= 9
#       define __STL_MEMBER_TEMPLATE_CLASSES
#       define __STL_TEMPLATE_FRIENDS
#       define __SGI_STL_USE_AUTO_PTR_CONVERSIONS
#       define __STL_HAS_NAMESPACES
//#       define __STL_USE_NEW_IOSTREAMS
#     endif
#   endif
#   define __STL_DEFAULT_CONSTRUCTOR_BUG
#   ifdef __EXCEPTIONS
#     define __STL_USE_EXCEPTIONS
#   endif
#   ifdef _REENTRANT
#     define __STL_PTHREADS
#   endif
#   if (__GNUC__ < 2) || (__GNUC__ == 2 && __GNUC_MINOR__ < 95)
#     define __STL_NO_FUNCTION_PTR_IN_CLASS_TEMPLATE
#   endif
# endif

# if defined(__SUNPRO_CC) 
#   define __STL_NO_BOOL
#   define __STL_NEED_TYPENAME
#   define __STL_NEED_EXPLICIT
#   define __STL_USE_EXCEPTIONS
#   ifdef _REENTRANT
#     define __STL_PTHREADS
#   endif
#   define __SGI_STL_NO_ARROW_OPERATOR
#   define __STL_PARTIAL_SPECIALIZATION_SYNTAX
#   define __STL_NO_EXCEPTION_HEADER
#   define __STL_NO_BAD_ALLOC
# endif

# if defined(__COMO__)
#   define __STL_MEMBER_TEMPLATES
#   define __STL_MEMBER_TEMPLATE_CLASSES
#   define __STL_TEMPLATE_FRIENDS
#   define __STL_CLASS_PARTIAL_SPECIALIZATION
#   define __STL_USE_EXCEPTIONS
#   define __STL_HAS_NAMESPACES
# endif

// Intel compiler, which uses the EDG front end.
# if defined(__ICL)
#   define __STL_LONG_LONG 
#   define __STL_MEMBER_TEMPLATES
#   define __STL_MEMBER_TEMPLATE_CLASSES
#   define __STL_TEMPLATE_FRIENDS
#   define __STL_FUNCTION_TMPL_PARTIAL_ORDER
#   define __STL_CLASS_PARTIAL_SPECIALIZATION
#   define __STL_NO_DRAND48
#   define __STL_HAS_NAMESPACES
#   define __STL_USE_EXCEPTIONS
#   define __STL_MEMBER_TEMPLATE_KEYWORD
#   ifdef _CPPUNWIND
#     define __STL_USE_EXCEPTIONS
#   endif
#   ifdef _MT
#     define __STL_WIN32THREADS
#   endif
# endif

// Mingw32, egcs compiler using the Microsoft C runtime
# if defined(__MINGW32__)
#   define __STL_NO_DRAND48
#   ifdef _MT
#     define __STL_WIN32THREADS
#   endif
# endif

// Cygwin32, egcs compiler on MS Windows
# if defined(__CYGWIN__)
#   define __STL_NO_DRAND48
# endif



// Microsoft compiler.
# if defined(_MSC_VER) && !defined(__ICL) && !defined(__MWERKS__)
#   define __STL_NO_DRAND48
#   define __STL_STATIC_CONST_INIT_BUG
#   define __STL_NEED_TYPENAME
#   define __STL_NO_USING_CLAUSE_IN_CLASS
#   define __STL_NO_FRIEND_TEMPLATE_CLASS
#   if _MSC_VER < 1100  /* 1000 is version 4.0, 1100 is 5.0, 1200 is 6.0. */
#     define __STL_NEED_EXPLICIT
#     define __STL_NO_BOOL
#     define __STL_NO_BAD_ALLOC
#   endif
#   if _MSC_VER > 1000
#     include <yvals.h>
#     define __STL_DONT_USE_BOOL_TYPEDEF
#   endif
#   define __STL_NON_TYPE_TMPL_PARAM_BUG
#   define __SGI_STL_NO_ARROW_OPERATOR
#   define __STL_DEFAULT_CONSTRUCTOR_BUG
#   ifdef _CPPUNWIND
#     define __STL_USE_EXCEPTIONS
#   endif
#   ifdef _MT
#     define __STL_WIN32THREADS
#   endif
#   if _MSC_VER >= 1200
#     define __STL_PARTIAL_SPECIALIZATION_SYNTAX
#     define __STL_HAS_NAMESPACES
#     define __STL_CAN_THROW_RANGE_ERRORS
#     define NOMINMAX
#     undef min
#     undef max
// disable warning 'initializers put in unrecognized initialization area'
#     pragma warning ( disable : 4075 )
// disable warning 'empty controlled statement found'
#     pragma warning ( disable : 4390 )
// disable warning 'debug symbol greater than 255 chars'
#     pragma warning ( disable : 4786 )
#   endif
#   if _MSC_VER < 1100
#     define __STL_NO_EXCEPTION_HEADER
#     define __STL_NO_BAD_ALLOC
#   endif
    // Because of a Microsoft front end bug, we must not provide a
    // namespace qualifier when declaring a friend function.
#   define __STD_QUALIFIER
# endif

# if defined(__BORLANDC__)
#     define __STL_NO_BAD_ALLOC
#     define __STL_NO_DRAND48
#     define __STL_DEFAULT_CONSTRUCTOR_BUG
#   if __BORLANDC__ >= 0x540 /* C++ Builder 4.0 */
#     define __STL_CLASS_PARTIAL_SPECIALIZATION
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER
#     define __STL_EXPLICIT_FUNCTION_TMPL_ARGS
#     define __STL_MEMBER_TEMPLATES
#     define __STL_TEMPLATE_FRIENDS
#   else
#     define __STL_NEED_TYPENAME
#     define __STL_LIMITED_DEFAULT_TEMPLATES
#     define __SGI_STL_NO_ARROW_OPERATOR
#     define __STL_NON_TYPE_TMPL_PARAM_BUG
#   endif
#   ifdef _CPPUNWIND
#     define __STL_USE_EXCEPTIONS
#   endif
#   ifdef __MT__
#     define __STL_WIN32THREADS
#   endif
# endif

# if defined(__STL_NO_BOOL) && !defined(__STL_DONT_USE_BOOL_TYPEDEF)
    typedef int bool;
#   define true 1
#   define false 0
# endif

# ifdef __STL_NEED_TYPENAME
#   define typename
# endif

# ifdef __STL_LIMITED_DEFAULT_TEMPLATES
#   define __STL_DEPENDENT_DEFAULT_TMPL(_Tp)
# else
#   define __STL_DEPENDENT_DEFAULT_TMPL(_Tp) = _Tp
# endif

# ifdef __STL_MEMBER_TEMPLATE_KEYWORD
#   define __STL_TEMPLATE template
# else
#   define __STL_TEMPLATE
# endif

# ifdef __STL_NEED_EXPLICIT
#   define explicit
# endif

# ifdef __STL_EXPLICIT_FUNCTION_TMPL_ARGS
#   define __STL_NULL_TMPL_ARGS <>
# else
#   define __STL_NULL_TMPL_ARGS
# endif

# if defined(__STL_CLASS_PARTIAL_SPECIALIZATION) \
     || defined (__STL_PARTIAL_SPECIALIZATION_SYNTAX)
#   define __STL_TEMPLATE_NULL template<>
# else
#   define __STL_TEMPLATE_NULL
# endif

// Use standard-conforming allocators if we have the necessary language
// features.  __STL_USE_SGI_ALLOCATORS is a hook so that users can 
// disable new-style allocators, and continue to use the same kind of
// allocators as before, without having to edit library headers.
# if defined(__STL_CLASS_PARTIAL_SPECIALIZATION) && \
     defined(__STL_MEMBER_TEMPLATES) && \
     defined(__STL_MEMBER_TEMPLATE_CLASSES) && \
    !defined(__STL_NO_BOOL) && \
    !defined(__STL_NON_TYPE_TMPL_PARAM_BUG) && \
    !defined(__STL_LIMITED_DEFAULT_TEMPLATES) && \
    !defined(__STL_USE_SGI_ALLOCATORS) 
#   define __STL_USE_STD_ALLOCATORS
# endif

# ifndef __STL_DEFAULT_ALLOCATOR
#   ifdef __STL_USE_STD_ALLOCATORS
#     define __STL_DEFAULT_ALLOCATOR(T) allocator< T >
#   else
#     define __STL_DEFAULT_ALLOCATOR(T) alloc
#   endif
# endif

// __STL_NO_NAMESPACES is a hook so that users can disable namespaces
// without having to edit library headers.  __STL_NO_RELOPS_NAMESPACE is
// a hook so that users can disable the std::rel_ops namespace, keeping 
// the relational operator template in namespace std, without having to 
// edit library headers.
# if defined(__STL_HAS_NAMESPACES) && !defined(__STL_NO_NAMESPACES)
#   define __STL_USE_NAMESPACES
#   define __STD std
#   define __STL_BEGIN_NAMESPACE namespace std {
#   define __STL_END_NAMESPACE }
#   if defined(__STL_FUNCTION_TMPL_PARTIAL_ORDER) && \
       !defined(__STL_NO_RELOPS_NAMESPACE)
#     define __STL_USE_NAMESPACE_FOR_RELOPS
#     define __STL_BEGIN_RELOPS_NAMESPACE namespace std { namespace rel_ops {
#     define __STL_END_RELOPS_NAMESPACE } }
#     define __STD_RELOPS std::rel_ops
#   else /* Use std::rel_ops namespace */
#     define __STL_USE_NAMESPACE_FOR_RELOPS
#     define __STL_BEGIN_RELOPS_NAMESPACE namespace std {
#     define __STL_END_RELOPS_NAMESPACE }
#     define __STD_RELOPS std
#   endif /* Use std::rel_ops namespace */
# else
#   define __STD 
#   define __STL_BEGIN_NAMESPACE 
#   define __STL_END_NAMESPACE 
#   undef  __STL_USE_NAMESPACE_FOR_RELOPS
#   define __STL_BEGIN_RELOPS_NAMESPACE 
#   define __STL_END_RELOPS_NAMESPACE 
#   define __STD_RELOPS 
#   undef  __STL_USE_NAMESPACES
# endif

// Some versions of the EDG front end sometimes require an explicit
// namespace spec where they shouldn't.  This macro facilitates that.
// If the bug becomes irrelevant, then all uses of __STD_QUALIFIER
// should be removed.  The 7.3 beta SGI compiler has this bug, but the
// MR version is not expected to have it.

# if defined(__STL_USE_NAMESPACES) && !defined(__STD_QUALIFIER)
#   define __STD_QUALIFIER std::
# else
#   define __STD_QUALIFIER
# endif

# ifdef __STL_USE_EXCEPTIONS
#   define __STL_TRY try
#   define __STL_CATCH_ALL catch(...)
#   define __STL_THROW(x) throw x
#   define __STL_RETHROW throw
#   define __STL_NOTHROW throw()
#   define __STL_UNWIND(action) catch(...) { action; throw; }
# else
#   define __STL_TRY 
#   define __STL_CATCH_ALL if (false)
#   define __STL_THROW(x) 
#   define __STL_RETHROW 
#   define __STL_NOTHROW 
#   define __STL_UNWIND(action) 
# endif

#ifdef __STL_ASSERTIONS
# include <stdio.h>
# define __stl_assert(expr) \
    if (!(expr)) { fprintf(stderr, "%s:%d STL assertion failure: %s\n", \
			  __FILE__, __LINE__, # expr); abort(); }
#else
# define __stl_assert(expr)
#endif

#if defined(__STL_WIN32THREADS) || defined(__STL_SGI_THREADS) \
    || defined(__STL_PTHREADS)  || defined(__STL_UITHREADS)
#   define __STL_THREADS
#   define __STL_VOLATILE volatile
#else
#   define __STL_VOLATILE
#endif

#if defined(__STL_CLASS_PARTIAL_SPECIALIZATION) \
    && defined(__STL_MEMBER_TEMPLATES) \
    && !defined(_STL_NO_CONCEPT_CHECKS)
#  define __STL_USE_CONCEPT_CHECKS
#endif


#endif /* __STL_CONFIG_H */

// Local Variables:
// mode:C++
// End:
