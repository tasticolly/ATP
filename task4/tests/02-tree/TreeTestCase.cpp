
#include "TreeTestCase.h"
#include "Tree.h"
#include <filesystem>
#include<fstream>
namespace fs = std::filesystem;
void make_tmp_dir(){
  fs::create_directory("tmp");
  fs::create_directory("tmp/son_tmp");
  std::ofstream File("tmp/file.txt");
}

void delete_tmp_dir(){
  fs::remove("tmp/file.txt");
  fs::remove("tmp/son_tmp");
  fs::remove("tmp");
}

TEST(TreeCase, UnexistablePath){
  EXPECT_ANY_THROW(GetTree("/aboba",true));
}
TEST(TreeCase,NotDir){
  make_tmp_dir();
  EXPECT_ANY_THROW(GetTree("tmp/file.txt",true));
  delete_tmp_dir();
}
TEST(TreeCase, OperatorEqual) {
  make_tmp_dir();
  FileNode correct_answer = {fs::path("tmp").filename().string(), true, {}};
  correct_answer.children.push_back({fs::path("tmp/file.txt").filename().string(), false, {}});
  EXPECT_FALSE(GetTree("tmp", false) == correct_answer);
  delete_tmp_dir();
}
TEST(TreeCase, NodeFilter){
  make_tmp_dir();
  FilterEmptyNodes(GetTree("tmp", false), "tmp");
  delete_tmp_dir();
}

TEST(TreeCase, NotDirsOnly) {
  make_tmp_dir();
  FileNode correct_answer = {fs::path("tmp").filename().string(), true, {}};
  correct_answer.children.push_back({fs::path("tmp/file.txt").filename().string(), false, {}});
  EXPECT_FALSE(GetTree("tmp", false) == correct_answer);
  delete_tmp_dir();
}

TEST(TreeCase, DirsOnly) {
  make_tmp_dir();
  FileNode correct_answer = {fs::path("tmp").filename().string(), true, {}};
  EXPECT_FALSE(GetTree("tmp", true) == correct_answer);
  delete_tmp_dir();
}





