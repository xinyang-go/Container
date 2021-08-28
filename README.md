# C++命名元组(NamedTuple)简易实现

基于C++20

---

使用方法
```c++
using Foo = Container<
    Field<"x", int>,
    Field<"y", std::string>
>;

const Foo f0(1, "2");
f0.c<"x">();   // 访问常量成员变量x
f0.c<"y">();   // 访问常量成员变量y

Foo f1;
f1.r<"x">() = 1;    // 引用(可赋值)成员变量x
f1.r<"y">() = "2";  // 引用(可赋值)成员变量y

// 嵌套Container
using Foo2 = Container<
    Field<"a", Foo>,
    Field<"b", Foo>,
    Field<"c", Foo>
>;

Foo2 f2;
f2.r<"a">.r<"x"> = 1;  // 嵌套访问
```

实现方法见`Container.hpp`
