#include <gtest/gtest.h>
#include "ConceptualExample01.cpp"

using namespace ConceptualExample01;

// Тестирование метода execute класса DebugFilter
TEST(DebugFilterTest, ExecuteTest) {
    DebugFilter debugFilter;
    testing::internal::CaptureStdout(); // Захват вывода в стандартный поток вывода
    debugFilter.execute("Test Request");
    std::string output = testing::internal::GetCapturedStdout(); // Получение захваченного вывода
    EXPECT_EQ(output, "[Log Request: Test Request]\n");
}

// Тестирование метода execute класса DebugFilter с пустым запросом
TEST(DebugFilterTest, ExecuteEmptyRequestTest) {
    DebugFilter debugFilter;
    testing::internal::CaptureStdout();
    debugFilter.execute("");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[Log Request: ]\n");
}

// Тестирование метода execute класса DebugFilter с запросом содержащим специальные символы
TEST(DebugFilterTest, ExecuteSpecialCharactersTest) {
    DebugFilter debugFilter;
    testing::internal::CaptureStdout();
    debugFilter.execute("Special Characters: !@#$%^&*()");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[Log Request: Special Characters: !@#$%^&*()]\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
