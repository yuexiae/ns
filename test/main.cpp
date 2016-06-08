#include <stdlib.h>
#include "redis/redis.h"
#include <winsock2.h>
#include "third-party/rtree/rtree.h"
#include "base/util.h"
#include <boost/geometry/index/rtree.hpp>

void RTreeTest() {
}

int main(int argc, char **argv) {
    base::Logging::DefualtLogging()->ConfigStderr();

    RTreeTest();
    
   

    printf("end\n");
    getchar();
    return 0;
}

void TestRedis() {
     WSADATA wsa={0};
    WSAStartup(MAKEWORD(2,2),&wsa);




    try {
        redis::Connector conn;
        conn.Connect("localhost", 6379);

		for (int i = 0; i < 100000; i++) {
        conn.auth("REDISTESTPWD");
        conn.select(0);

        char temp[]={'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'};
        conn.set("temp", redis::Ref(temp, sizeof(temp)));
        conn.exists("temp");

        redis::Reply r = conn.get("temp");
        //printf("r size:%u\n", r.GetLength());

        conn.hset("temp2", "field", "test");
        conn.hset("temp2", "field2", "test");
        r = conn.hmget("temp2", "field field2 field3");


        conn.PushCommand("HMSET");
        conn.Push("test number");
        conn.Push("std::numeric_limits<char>::min()", std::numeric_limits<char>::min());
        conn.Push("std::numeric_limits<char>::max()", std::numeric_limits<char>::max());
        conn.Push("std::numeric_limits<unsigned char>::min()", std::numeric_limits<unsigned char>::min());
        conn.Push("std::numeric_limits<unsigned char>::max()", std::numeric_limits<unsigned char>::max());
        conn.Push("std::numeric_limits<short>::min()", std::numeric_limits<short>::min());
        conn.Push("std::numeric_limits<short>::max()", std::numeric_limits<short>::max());
        conn.Push("std::numeric_limits<unsigned short>::min()", std::numeric_limits<unsigned short>::min());
        conn.Push("std::numeric_limits<unsigned short>::max()", std::numeric_limits<unsigned short>::max());
        conn.Push("std::numeric_limits<long>::min()", std::numeric_limits<long>::min());
        conn.Push("std::numeric_limits<long>::max()", std::numeric_limits<long>::max());
        conn.Push("std::numeric_limits<unsigned long>::min()", std::numeric_limits<unsigned long>::min());
        conn.Push("std::numeric_limits<unsigned long>::max()", std::numeric_limits<unsigned long>::max());
        conn.Push("std::numeric_limits<long long>::min()", std::numeric_limits<long long>::min());
        conn.Push("std::numeric_limits<long long>::max()", std::numeric_limits<long long>::max());
        conn.Push("std::numeric_limits<unsigned long long>::min()", std::numeric_limits<unsigned long long>::min());
        conn.Push("std::numeric_limits<unsigned long long>::max()", std::numeric_limits<unsigned long long>::max());
        conn.GetReply().CheckStatusOk();

       
        conn.PushCommand("HMGET");
        conn.Push("test number");
        conn.Push("std::numeric_limits<char>::min()");
        conn.Push("std::numeric_limits<char>::max()");
        conn.Push("std::numeric_limits<unsigned char>::min()");
        conn.Push("std::numeric_limits<unsigned char>::max()");
        conn.Push("std::numeric_limits<short>::min()");
        conn.Push("std::numeric_limits<short>::max()");
        conn.Push("std::numeric_limits<unsigned short>::min()");
        conn.Push("std::numeric_limits<unsigned short>::max()");
        conn.Push("std::numeric_limits<long>::min()");
        conn.Push("std::numeric_limits<long>::max()");
        conn.Push("std::numeric_limits<unsigned long>::min()");
        conn.Push("std::numeric_limits<unsigned long>::max()");
        conn.Push("std::numeric_limits<long long>::min()");
        conn.Push("std::numeric_limits<long long>::max()");
        conn.Push("std::numeric_limits<unsigned long long>::min()");
        conn.Push("std::numeric_limits<unsigned long long>::max()");
        conn.PushCommand("HMGET");
        conn.Push("test number");
        conn.Push("std::numeric_limits<char>::min()");
        conn.Push("std::numeric_limits<char>::max()");
        conn.Push("std::numeric_limits<unsigned char>::min()");
        conn.Push("std::numeric_limits<unsigned char>::max()");
        conn.Push("std::numeric_limits<short>::min()");
        conn.Push("std::numeric_limits<short>::max()");
        conn.Push("std::numeric_limits<unsigned short>::min()");
        conn.Push("std::numeric_limits<unsigned short>::max()");
        conn.Push("std::numeric_limits<long>::min()");
        conn.Push("std::numeric_limits<long>::max()");
        conn.Push("std::numeric_limits<unsigned long>::min()");
        conn.Push("std::numeric_limits<unsigned long>::max()");
        conn.Push("std::numeric_limits<long long>::min()");
        conn.Push("std::numeric_limits<long long>::max()");
        conn.Push("std::numeric_limits<unsigned long long>::min()");
        conn.Push("std::numeric_limits<unsigned long long>::max()");
        conn.PushCommand("HMGET");
        conn.Push("test number");
        conn.Push("std::numeric_limits<char>::min()");
        conn.Push("std::numeric_limits<char>::max()");
        conn.Push("std::numeric_limits<unsigned char>::min()");
        conn.Push("std::numeric_limits<unsigned char>::max()");
        conn.Push("std::numeric_limits<short>::min()");
        conn.Push("std::numeric_limits<short>::max()");
        conn.Push("std::numeric_limits<unsigned short>::min()");
        conn.Push("std::numeric_limits<unsigned short>::max()");
        conn.Push("std::numeric_limits<long>::min()");
        conn.Push("std::numeric_limits<long>::max()");
        conn.Push("std::numeric_limits<unsigned long>::min()");
        conn.Push("std::numeric_limits<unsigned long>::max()");
        conn.Push("std::numeric_limits<long long>::min()");
        conn.Push("std::numeric_limits<long long>::max()");
        conn.Push("std::numeric_limits<unsigned long long>::min()");
        conn.Push("std::numeric_limits<unsigned long long>::max()");
        conn.PushCommand("HMGET");
        conn.Push("test number");
        conn.Push("std::numeric_limits<char>::min()");
        conn.Push("std::numeric_limits<char>::max()");
        conn.Push("std::numeric_limits<unsigned char>::min()");
        conn.Push("std::numeric_limits<unsigned char>::max()");
        conn.Push("std::numeric_limits<short>::min()");
        conn.Push("std::numeric_limits<short>::max()");
        conn.Push("std::numeric_limits<unsigned short>::min()");
        conn.Push("std::numeric_limits<unsigned short>::max()");
        conn.Push("std::numeric_limits<long>::min()");
        conn.Push("std::numeric_limits<long>::max()");
        conn.Push("std::numeric_limits<unsigned long>::min()");
        conn.Push("std::numeric_limits<unsigned long>::max()");
        conn.Push("std::numeric_limits<long long>::min()");
        conn.Push("std::numeric_limits<long long>::max()");
        conn.Push("std::numeric_limits<unsigned long long>::min()");
        conn.Push("std::numeric_limits<unsigned long long>::max()");
        conn.PushCommand("HGET");
        conn.Push("test number");
        conn.Push("std::numeric_limits<char>::min()");
        conn.PushCommand("HMGET");
        conn.Push("test number");
        conn.Push("std::numeric_limits<char>::min()");
        conn.Push("std::numeric_limits<char>::max()");
        conn.Push("std::numeric_limits<unsigned char>::min()");
        conn.Push("std::numeric_limits<unsigned char>::max()");
        conn.Push("std::numeric_limits<short>::min()");
        conn.Push("std::numeric_limits<short>::max()");
        conn.Push("std::numeric_limits<unsigned short>::min()");
        conn.Push("std::numeric_limits<unsigned short>::max()");
        conn.Push("std::numeric_limits<long>::min()");
        conn.Push("std::numeric_limits<long>::max()");
        conn.Push("std::numeric_limits<unsigned long>::min()");
        conn.Push("std::numeric_limits<unsigned long>::max()");
        conn.Push("std::numeric_limits<long long>::min()");
        conn.Push("std::numeric_limits<long long>::max()");
        conn.Push("std::numeric_limits<unsigned long long>::min()");
        conn.Push("std::numeric_limits<unsigned long long>::max()");

        r = conn.GetReply();
        assert(r[0].convert<char>() == std::numeric_limits<char>::min());
        assert(r[1].convert<char>() == std::numeric_limits<char>::max());
        assert(r[2].convert<unsigned char>() == std::numeric_limits<unsigned char>::min());
        assert(r[3].convert<unsigned char>() == std::numeric_limits<unsigned char>::max());
        assert(r[4].convert<short>() == std::numeric_limits<short>::min());
        assert(r[5].convert<short>() == std::numeric_limits<short>::max());
        assert(r[6].convert<unsigned short>() == std::numeric_limits<unsigned short>::min());
        assert(r[7].convert<unsigned short>() == std::numeric_limits<unsigned short>::max());
        assert(r[8].convert<long>() == std::numeric_limits<long>::min());
        assert(r[9].convert<long>() == std::numeric_limits<long>::max());
        assert(r[10].convert<unsigned long>() == std::numeric_limits<unsigned long>::min());
        assert(r[11].convert<unsigned long>() == std::numeric_limits<unsigned long>::max());
        assert(r[12].convert<long long>() == std::numeric_limits<long long>::min());
        assert(r[13].convert<long long>() == std::numeric_limits<long long>::max());
        assert(r[14].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::min());
        assert(r[15].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::max());
        r = conn.GetReply();
        assert(r[0].convert<char>() == std::numeric_limits<char>::min());
        assert(r[1].convert<char>() == std::numeric_limits<char>::max());
        assert(r[2].convert<unsigned char>() == std::numeric_limits<unsigned char>::min());
        assert(r[3].convert<unsigned char>() == std::numeric_limits<unsigned char>::max());
        assert(r[4].convert<short>() == std::numeric_limits<short>::min());
        assert(r[5].convert<short>() == std::numeric_limits<short>::max());
        assert(r[6].convert<unsigned short>() == std::numeric_limits<unsigned short>::min());
        assert(r[7].convert<unsigned short>() == std::numeric_limits<unsigned short>::max());
        assert(r[8].convert<long>() == std::numeric_limits<long>::min());
        assert(r[9].convert<long>() == std::numeric_limits<long>::max());
        assert(r[10].convert<unsigned long>() == std::numeric_limits<unsigned long>::min());
        assert(r[11].convert<unsigned long>() == std::numeric_limits<unsigned long>::max());
        assert(r[12].convert<long long>() == std::numeric_limits<long long>::min());
        assert(r[13].convert<long long>() == std::numeric_limits<long long>::max());
        assert(r[14].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::min());
        assert(r[15].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::max());
        r = conn.GetReply();
        assert(r[0].convert<char>() == std::numeric_limits<char>::min());
        assert(r[1].convert<char>() == std::numeric_limits<char>::max());
        assert(r[2].convert<unsigned char>() == std::numeric_limits<unsigned char>::min());
        assert(r[3].convert<unsigned char>() == std::numeric_limits<unsigned char>::max());
        assert(r[4].convert<short>() == std::numeric_limits<short>::min());
        assert(r[5].convert<short>() == std::numeric_limits<short>::max());
        assert(r[6].convert<unsigned short>() == std::numeric_limits<unsigned short>::min());
        assert(r[7].convert<unsigned short>() == std::numeric_limits<unsigned short>::max());
        assert(r[8].convert<long>() == std::numeric_limits<long>::min());
        assert(r[9].convert<long>() == std::numeric_limits<long>::max());
        assert(r[10].convert<unsigned long>() == std::numeric_limits<unsigned long>::min());
        assert(r[11].convert<unsigned long>() == std::numeric_limits<unsigned long>::max());
        assert(r[12].convert<long long>() == std::numeric_limits<long long>::min());
        assert(r[13].convert<long long>() == std::numeric_limits<long long>::max());
        assert(r[14].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::min());
        assert(r[15].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::max());
        r = conn.GetReply();
        assert(r[0].convert<char>() == std::numeric_limits<char>::min());
        assert(r[1].convert<char>() == std::numeric_limits<char>::max());
        assert(r[2].convert<unsigned char>() == std::numeric_limits<unsigned char>::min());
        assert(r[3].convert<unsigned char>() == std::numeric_limits<unsigned char>::max());
        assert(r[4].convert<short>() == std::numeric_limits<short>::min());
        assert(r[5].convert<short>() == std::numeric_limits<short>::max());
        assert(r[6].convert<unsigned short>() == std::numeric_limits<unsigned short>::min());
        assert(r[7].convert<unsigned short>() == std::numeric_limits<unsigned short>::max());
        assert(r[8].convert<long>() == std::numeric_limits<long>::min());
        assert(r[9].convert<long>() == std::numeric_limits<long>::max());
        assert(r[10].convert<unsigned long>() == std::numeric_limits<unsigned long>::min());
        assert(r[11].convert<unsigned long>() == std::numeric_limits<unsigned long>::max());
        assert(r[12].convert<long long>() == std::numeric_limits<long long>::min());
        assert(r[13].convert<long long>() == std::numeric_limits<long long>::max());
        assert(r[14].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::min());
        assert(r[15].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::max());
        r = conn.GetReply();
        assert(r.convert<char>() == std::numeric_limits<char>::min());
        r = conn.GetReply();
        assert(r[0].convert<char>() == std::numeric_limits<char>::min());
        assert(r[1].convert<char>() == std::numeric_limits<char>::max());
        assert(r[2].convert<unsigned char>() == std::numeric_limits<unsigned char>::min());
        assert(r[3].convert<unsigned char>() == std::numeric_limits<unsigned char>::max());
        assert(r[4].convert<short>() == std::numeric_limits<short>::min());
        assert(r[5].convert<short>() == std::numeric_limits<short>::max());
        assert(r[6].convert<unsigned short>() == std::numeric_limits<unsigned short>::min());
        assert(r[7].convert<unsigned short>() == std::numeric_limits<unsigned short>::max());
        assert(r[8].convert<long>() == std::numeric_limits<long>::min());
        assert(r[9].convert<long>() == std::numeric_limits<long>::max());
        assert(r[10].convert<unsigned long>() == std::numeric_limits<unsigned long>::min());
        assert(r[11].convert<unsigned long>() == std::numeric_limits<unsigned long>::max());
        assert(r[12].convert<long long>() == std::numeric_limits<long long>::min());
        assert(r[13].convert<long long>() == std::numeric_limits<long long>::max());
        assert(r[14].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::min());
        assert(r[15].convert<unsigned long long>() == std::numeric_limits<unsigned long long>::max());


        conn.PushCommand("EVAL");
        conn.Push("return {{{{{{1,2,3,4,5},{{{{{{6,7,8},20}, 21},22}}}}}}}, {{{{{{{10, 11,12}}}}}}}, 13, 14, 15, 16}");
        conn.Push(0);
        //
        r = conn.GetReply();
        //r.PrintDetial();
		}


    } catch(redis::Exception &e) {
        printf("%s\n", e.what());
    }
}