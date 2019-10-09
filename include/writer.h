#ifndef WRITER_H
#define WRITER_H
#include "logger.h"
class writer {
private:
  std::shared_ptr<logger> sf;
public:
  writer (std::shared_ptr<logger> sf);

  void writer_to_file (std::string s);
};
#endif