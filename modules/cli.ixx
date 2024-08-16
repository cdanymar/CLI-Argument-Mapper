/// @file cli.ixx
/// @author Danylo Marchenko (cdanymar)
/// @brief Command line arguments parsing tools.
/// @version 1.0
/// @date 2024-08-14
/// @copyright Copyright (c) 2024

/// @brief Command line arguments parsing tools.
export module cli;

import <cstdlib>;
import "parse.tpp";
import std;

/// @brief Command line arguments parsing tools.
export namespace cli
{
    /// @brief Container with the parsing tools for the command line arguments.
    class args final
    {
    public:
        /// @brief Initializes CLI arguments.
        explicit args(std::initializer_list<std::string>);

        /// @brief Initializes CLI arguments.
        explicit args(const std::vector<std::string>&);

        /// @brief Initializes CLI arguments.
        explicit args(int, const char* const[]);


        /// @returns Parses text into array of texts. Takes into account values separated by the equals sign, unlike Windows.
        /// @param text Raw input.
        static auto parse(std::string_view text) -> std::vector<std::string>;


        /// @brief Maps verbatim option to the first argument.
        /// @tparam Args Callback function arguments.
        /// @tparam T Callback function return value.
        /// @param option The option to match.
        /// @param function The callback function to call.
        template <typename... Args, typename T>
        auto on(const std::string_view option, T (*function)(Args...)) -> args&
        {
            if (auto arg = m_args.cbegin(); m_args.size() >= sizeof...(Args) + 1 && *arg == option)
                std::apply([&](Args&&... args)
                {
                    ((args = *parse::to<Args>(*++arg)), ...);
                    function(args...);
                }, std::tuple<Args...>());

            return *this;
        }

        /// @brief Maps verbatim option to the first argument.
        /// @tparam Args Callback function arguments.
        /// @tparam Lambda The callback lambda to call. Parameters types must be explicit.
        /// @param option The option to match.
        /// @param lambda The callback lambda to call. Parameters types must be explicit.
        template <typename... Args, typename Lambda>
        auto on(const std::string_view option, Lambda lambda) -> args&
        {
            if (auto arg = m_args.cbegin(); m_args.size() >= sizeof...(Args) + 1 && *arg == option)
                std::apply([&](Args&&... args)
                {
                    ((args = *parse::to<Args>(*++arg)), ...);
                    lambda(args...);
                }, std::tuple<Args...>());

            return *this;
        }

    private:
        /// @brief Parsed arguments values.
        std::vector<std::string> m_args;


        /// @brief Joins OS arguments into a single string.
        static auto join(int, const char* const[]) -> std::string;

        /// @brief Joins OS arguments into a single string.
        static auto join(std::span<const std::string>) -> std::string;
    } args(__argc - 1, __argv + 1);
}
