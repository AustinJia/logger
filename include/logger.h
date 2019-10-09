#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>
#include <memory>

class logger {
private:
  char dst[52];
  std::mutex writer_mutex;
  std::ofstream my_file;
public:
  logger (const std::string& path);
  ~logger ();
  void write (const std::string& s);
};
#endif