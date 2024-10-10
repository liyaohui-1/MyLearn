#include "proxy.hpp"


int main(int argc, char* argv[])
{
    std::shared_ptr <ReadInfo> proxy = std::make_shared<ReadInfoProxy> ();
    proxy->read();
    proxy->read();
    proxy->read();

    return 0;
}