#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>
#include <charconv>

std::mutex cout_mutex;

void worker(int id) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Поток № " << id << " выполняет свою работу\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <N>\n";
        return 1;
    }

    std::string arg = argv[1];
    int n = 0;
    auto [ptr, ec] = std::from_chars(arg.data(), arg.data() + arg.size(), n);
    if (ec != std::errc() || ptr != arg.data() + arg.size() || n <= 0) {
        std::cerr << "Ошибка: N должно быть положительным целым числом\n";
        return 1;
    }

    std::vector<std::jthread> threads;
    threads.reserve(static_cast<std::size_t>(n));

    for (int i = 1; i <= n; ++i) {
        threads.emplace_back(worker, i);
    }

    return 0;
}