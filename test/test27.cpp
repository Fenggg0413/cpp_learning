#include <tuple>
#include <iostream>

//元组的操作与解包
auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>

    if (id == 0)
        return std::make_tuple(3.8, 'A', "张三");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "李四");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "王五");
    return std::make_tuple(0.0, 'D', "null");
    // 如果只写 0 会出现推断错误, 编译失败
}

int main()
{
    auto student = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student) << ", "
              << "成绩: " << std::get<1>(student) << ", "
              << "姓名: " << std::get<2>(student) << '\n';

    double gpa;
    char grade;
    std::string name;

    // 元组进行拆包
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa << ", "
              << "成绩: " << grade << ", "
              << "姓名: " << name << '\n';

    //参数绑定
    auto [x, y, z] = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << x << ", "
              << "成绩: " << y << ", "
              << "姓名: " << z << '\n';

    std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
    std::cout << std::get<std::string>(t) << std::endl;
    //std::cout << std::get<double>(t) << std::endl; // 非法, 引发编译期错误
    std::cout << std::get<3>(t) << std::endl;

    //合并两个元组
    auto new_tuple = std::tuple_cat(get_student(1), std::move(t));
    auto [a, b, c, d, e, f, g] = new_tuple;
    std::cout << a << " " << b << " " << c << " "
         << d << " " << e << " " << f << " " << g << std::endl;
}