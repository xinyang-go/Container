//
// Created by xinyang on 2021/8/28.
//

#include "Container.hpp"
#include <iostream>
#include <string>

using Student = Container<
        Field<"name", std::string>,
        Field<"number", int>,
        Field<"score", double>
>;

using ClassA = Container<
        Field<"stu0", Student>,
        Field<"stu1", Student>,
        Field<"stu2", Student>
>;

int main() {
    ClassA classA(
            Student("Jack", 10, 82.3),
            Student("Tony", 11, 96.0),
            Student("Lily", 12, 92.1)
    );

    std::cout << "classA.stu0.name   = " << classA.r<"stu0">().r<"name">() << std::endl;
    std::cout << "classA.stu0.number = " << classA.r<"stu0">().r<"number">() << std::endl;
    std::cout << "classA.stu0.score  = " << classA.r<"stu0">().r<"score">() << std::endl;

    std::cout << "classA.stu1.name   = " << classA.r<"stu1">().r<"name">() << std::endl;
    std::cout << "classA.stu1.number = " << classA.r<"stu1">().r<"number">() << std::endl;
    std::cout << "classA.stu1.score  = " << classA.r<"stu1">().r<"score">() << std::endl;

    std::cout << "classA.stu2.name   = " << classA.r<"stu2">().r<"name">() << std::endl;
    std::cout << "classA.stu2.number = " << classA.r<"stu2">().r<"number">() << std::endl;
    std::cout << "classA.stu2.score  = " << classA.r<"stu2">().r<"score">() << std::endl;

    return 0;
}
