
#include "TreeTestCase.h"
#include "Tree.h"
#include <filesystem>
#include<fstream>
namespace fs = std::filesystem;

std::string nameFile;
std::string nameDir;
std::string nameChildDir;

void make_tmp_dir() {
  nameDir = std::string(fs::temp_directory_path()) + "/testing_ATP";
  nameFile = nameDir + "/file.txt";
  nameChildDir = nameDir + "/son_dir";
  fs::create_directory(nameDir);
  fs::create_directory(nameChildDir);
  std::ofstream File(nameFile);
}

void delete_tmp_dir() {
  fs::remove(nameFile);
  fs::remove(nameChildDir);
  fs::remove(nameDir);
}

TEST(TreeCase, UnexistablePath) {
  EXPECT_ANY_THROW(GetTree("/aboba", true));
}
TEST(TreeCase, NotDir) {
  make_tmp_dir();
  EXPECT_ANY_THROW(GetTree(nameFile, true));
  delete_tmp_dir();
}
TEST(TreeCase, OperatorEqual) {
  make_tmp_dir();
  FileNode correct_answer = {fs::path(nameDir).filename().string(), true, {}};
  correct_answer.children.push_back({fs::path(nameFile).filename().string(), false, {}});
  EXPECT_FALSE(GetTree(nameDir, false) == correct_answer);
  delete_tmp_dir();
}
TEST(TreeCase, NodeFilter) {
  make_tmp_dir();
  FilterEmptyNodes(GetTree(nameDir, false), nameDir);
  delete_tmp_dir();
}

TEST(TreeCase, NotDirsOnly) {
  make_tmp_dir();
  FileNode correct_answer = {fs::path(nameDir).filename().string(), true, {}};
  correct_answer.children.push_back({fs::path(nameFile).filename().string(), false, {}});
  EXPECT_FALSE(GetTree(nameDir, false) == correct_answer);
  delete_tmp_dir();
}

TEST(TreeCase, DirsOnly) {
  make_tmp_dir();
  FileNode correct_answer = {fs::path(nameDir).filename().string(), true, {}};
  EXPECT_FALSE(GetTree(nameDir, true) == correct_answer);
  delete_tmp_dir();
}





