#ifndef TINYRPC_NET_CODEC_H
#define TINYRPC_NET_CODEC_H

#include <string>
#include "tcp/tcp_buffer.h"


namespace tinyrpc {

enum CodeCType {
  CODEC_HTTP = 1,
  CODEC_TINYPB = 2,
};



class CodeC {

 public:

  CodeC() {}

  virtual ~CodeC() {}

  virtual void encode(TcpBuffer::ptr buf) = 0;

  virtual void decode(TcpBuffer::ptr buf) = 0;

  virtual CodeCType type() const = 0;

  static std::string GetCodeCType(CodeCType type) {
    switch (type)
    {
    case CodeCType::CODEC_HTTP:
      return "http";

    case CodeCType::CODEC_TINYPB:
      return "tinypb";

    default:
      return "unknown code type";
    }
}

};

}

#endif