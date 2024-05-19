#include <gtest/gtest.h>
#include <sstream>
#include "ConceptualExample01.cpp"

// Тестовый случай для проверки метода operation класса Target
TEST(TargetTest, OperationTest) {
    // Подготовка
    std::string expected_request = "Тестовый запрос";
    std::stringstream out;
    std::streambuf* coutBuf = std::cout.rdbuf(); // Сохранение буфера cout
    std::cout.rdbuf(out.rdbuf()); // Перенаправление cout на stringstream

    ConceptualExample01::Target target;

    // Действие
    target.operation(expected_request);

    // Проверка
    std::string output = out.str();
    std::size_t found = output.find(expected_request);
    std::cout.rdbuf(coutBuf); // Восстановление буфера cout
    EXPECT_NE(found, std::string::npos); // Проверка, найдена ли строка запроса в выводе
}

// Второй тестовый случай для проверки метода setTarget класса FilterChain
TEST(TargetTest, SetTargetTest) {
    // Подготовка
    ConceptualExample01::Target target;

    // Действие
    std::shared_ptr<ConceptualExample01::Target> new_target = std::make_shared<ConceptualExample01::Target>();
    target.setTarget(new_target);

    // Проверка
    EXPECT_EQ(target.getTarget(), new_target); // Проверка, установлен ли новый объект-цель
}

// Третий тестовый случай для проверки метода executeRequest класса FilterChain
TEST(TargetTest, ExecuteRequestTest) {
    // Подготовка
    ConceptualExample01::Target target;

    // Действие
    std::string request = "Test Request";
    target.executeRequest(request);

    // Проверка: в этом случае проверка будет зависеть от конкретной реализации метода executeRequest
    // Допустим, если метод выводит что-то в стандартный поток вывода, то мы можем захватить его и проверить наличие ожидаемой строки
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find(request), std::string::npos); // Проверка, найдена ли строка запроса в выводе
}

// Основная функция для запуска тестов
int main(int argc, char** argv) {
    // Инициализация Google Test
    ::testing::InitGoogleTest(&argc, argv);
    // Запуск тестов
    return RUN_ALL_TESTS();
}

