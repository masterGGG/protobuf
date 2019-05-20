import data_pb2
from google.protobuf.json_format import MessageToJson, Parse

import os
import sys

if __name__ == "__main__":
    with open("./test", "r") as f:
        buf = f.read() 
        bstr = buf[0:len(buf)-1]
        data = data_pb2.user()
        data.ParseFromString(bstr)
        print data.name
        print data.pwd
        print data.ret
        print data.sex

#data.me
        for num in data.me.photo:
            print num
        print data.me.addrno
        print data.me.cityno
        f.close()
