/// @file cli.cxx
/// @author Danylo Marchenko (cdanymar)
/// @brief Command line arguments parsing tools.
/// @version 1.0
/// @date 2024-08-14
/// @copyright Copyright (c) 2024
module cli;

cli::args::args(const std::initializer_list<std::string> values)
    : m_args(parse(join(values)))
{
}

cli::args::args(const std::vector<std::string>& values)
    : m_args(parse(join(values)))
{
}

cli::args::args(const int argc, const char* const argv[])
    : m_args(parse(join(argc, argv)))
{
}

auto cli::args::join(const int argc, const char* const argv[]) -> std::string
{
    std::ostringstream result;

    for (int i = 0; i < argc; ++i)
    {
        if (result.tellp() != 0)
            result << " ";

        if (std::count_if(argv[i], argv[i] + std::strlen(argv[i]), [](const char c) -> bool
        {
            return std::isspace(c);
        }) > 0)
        {
            result << '"';
            result << argv[i];
            result << '"';
        }
        else result << argv[i];
    }

    return result.str();
}

auto cli::args::join(const std::span<const std::string> values) -> std::string
{
    std::ostringstream result;

    for (const std::string& arg : values)
    {
        if (result.tellp() != 0)
            result << " ";

        if (std::ranges::count_if(arg, [](const char c) -> bool
        {
            return std::isspace(c);
        }) > 0)
        {
            result << '"';
            result << arg;
            result << '"';
        }
        else result << arg;
    }

    return result.str();
}

auto cli::args::parse(const std::string_view text) -> std::vector<std::string>
{
    if (text.empty())
        return {};

    std::vector<std::string> values;
    std::string arg;

    bool in_quotes = false;

    for (const char c : text)
    {
        if (c == '"')
            in_quotes = !in_quotes;
        else if (in_quotes)
            if (c == '"' && arg.size() > 1)
            {
                in_quotes = false;
                if (arg.front() == '"' && arg.back() == '"')
                    arg = arg.substr(1, arg.length() - 2);
            }
            else arg += c;
        else if (std::isspace(c) || c == '=')
        {
            if (!arg.empty())
            {
                values.push_back(arg);
                arg.clear();
            }
        }
        else arg += c;
    }

    if (!arg.empty())
        values.push_back(arg);

    return values;
}
