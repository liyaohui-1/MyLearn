#include <memory>
#include <map>
#include <list>

class RtcPacket
{
public:
    RtcPacket(int seq, int len) : _seq(seq), _len(len) {}
    ~RtcPacket() {}

private:
    int _seq;
    int _len;
};

class RtcStreamMgr
{
public:
    std::map<std::string, std::list<std::shared_ptr<RtcPacket>>*> rtc_packet_map;
};

auto* g_stream_mgr = new RtcStreamMgr();

void test05()
{
    // 构造缓存数据包的map
    std::shared_ptr<RtcPacket> packet(new RtcPacket(1, 1024));
    auto list = new std::list<std::shared_ptr<RtcPacket>>();
    list->push_back(packet);
    g_stream_mgr->rtc_packet_map.insert(std::make_pair("666", list));
    // 删除map元素，但未删除该元素对应的动态内存
    auto it = g_stream_mgr->rtc_packet_map.find("666");
    if (it != g_stream_mgr->rtc_packet_map.end()) {
        delete it->second;
    }
    g_stream_mgr->rtc_packet_map.erase(it);
}

int main()
{
    test05();
    if (g_stream_mgr) {
        delete g_stream_mgr;
    }
    return 0;
}