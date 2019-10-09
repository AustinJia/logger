#include "include/writer.h"
writer::writer (std::shared_ptr<logger> sf)
{
  this->sf = sf;
}

void writer::writer_to_file (std::string s) 
{
  sf->write(s);
}