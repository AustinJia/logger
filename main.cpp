#include "include/writer.h"
#include "include/logger.h"
#include "gtest/gtest.h"
#include <stdio.h>
#include <thread>
#include <chrono>

// Test 1: testing file exist
TEST(File_Exist_Test,TEST_ONE)
{
  // clear up the test1.txt file in the current folder
  std::string s = "test1.txt";
  remove(s.c_str());
  // create a txt file
  auto file_name = std::make_shared<logger>(s);
  writer writer1(file_name);
  std::ifstream ifile(s.c_str());
  remove(s.c_str());
  EXPECT_TRUE((bool)ifile);
}

// Test 2: testing file has specific text
TEST(Writing,TEST_TWO)
{
  std::string s = "test2.txt";
  auto file_name = std::make_shared<logger>(s);
  writer writer1(file_name);
  std::ifstream ifile(s.c_str());
  writer1.writer_to_file("test1");
  writer1.writer_to_file("test2");

  // check each line
  std::string line;
  bool test1_check = false;
  bool test2_check = false;
  while(ifile >> line)
  {
    if(line=="test1")
    {
      test1_check = true;
    }
    else if(line=="test2")
    {
      test2_check = true;
    }
  }
  remove(s.c_str());
  EXPECT_TRUE(test1_check&&test2_check);
}

// Test 3: testing file has specific text
TEST(Writing_From_Diff_Writer,TEST_THREE)
{
  std::string s = "test3.txt";
  auto file_name = std::make_shared<logger>(s);
  writer writer1(file_name);
  writer writer2(file_name);
  std::ifstream ifile(s.c_str());
  writer1.writer_to_file("test1");
  writer2.writer_to_file("test2");

  // check each line
  std::string line;
  bool test1_check = false;
  bool test2_check = false;
  while(ifile >> line)
  {
    if(line=="test1")
    {
      test1_check = true;
    }
    else if(line=="test2")
    {
      test2_check = true;
    }
  }
  remove(s.c_str());
  EXPECT_TRUE(test1_check&&test2_check);
}


// Test 4: testing file has specific text
void write_to_file(std::string s, std::string line)
{
  auto file_name = std::make_shared<logger>(s);
  writer writer1(file_name);
  std::ifstream ifile(s.c_str());
  writer1.writer_to_file(line);
}

TEST(Writing_From_Diff_Threads,TEST_FOUR)
{
  std::string line1 = "Hey, Buddy";
  std::string line2 = "Hello, Man!!";
  std::string s = "test4.txt";
  std::thread t1(write_to_file, s, line1);
  // std::this_thread::sleep_for (std::chrono::seconds(1));
  std::thread t2(write_to_file, s, line2);
  t1.join();
  t2.join();
  // check each line
  std::string line;
  std::ifstream ifile(s.c_str());
  bool test1_check = false;
  bool test2_check = false;
  while(std::getline(ifile,line))
  {
    if(line == line1)
    {
      test1_check = true;
    }
    else if(line == line2)
    {
      test2_check = true;
    }
  }
  remove(s.c_str());
  EXPECT_TRUE(test1_check&&test2_check);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}