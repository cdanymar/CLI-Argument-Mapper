import std;
import cli;

int main()
{
    cli::args
        .on("foo", +[](char c) -> void
        {
            std::cout << c;
        })
        .on("bar", +[](unsigned c) -> void
        {
            std::cout << c;
        })
        .on("baz", +[](float c) -> void
        {
            std::cout << c;
        })
        .on("biz", +[](bool c) -> void
        {
            std::cout << c;
        })
        .on("fiz", +[](std::string c) -> void
        {
            std::cout << c;
        })
        .on("fiz1", +[](std::string_view c) -> void
        {
            std::cout << c;
        });

    return 0;
}
