#include <iostream>
#include <sstream>

// 变长参数模板函数，用于日志记录
template<typename... Args>
void logMessage(const Args&... args)
{
    std::ostringstream stream;
    using expander = int[];
    (void)expander{0, (void(stream << args << " "), 0)...};
    stream << std::endl;
    std::cout << stream.str();
}

int main()
{
    // 使用变长参数模板函数记录日志
    logMessage("Error:", 404, "- Not Found");
    logMessage("Warning:", "Low battery");
    logMessage("Info:", "User logged in");

    return 0;
}