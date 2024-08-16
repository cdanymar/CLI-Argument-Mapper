<a id="readme-top"></a>

<div align="center">
    <h1>CLI Argument Mapper</h1>
    <p>Library for mapping CLI options to functions with automatic parsing of the values.</p>
    <p>
        <a href="">
            <img src="https://img.shields.io/github/last-commit/cdanymar1/CLI-Argument-Mapper" alt="last commit">
        </a>
        <a href="https://github.com/cdanymar1/CLI-Argument-Mapper/network/members">
            <img src="https://img.shields.io/github/forks/cdanymar1/CLI-Argument-Mapper" alt="forks">
        </a>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codese/stargazers">
            <img src="https://img.shields.io/github/stars/cdanymar1/CLI-Argument-Mapper" alt="stars">
        </a>
        <br>
        <a href="https://github.com/cdanymar1/CLI-Argument-Mapper/issues/">
            <img src="https://img.shields.io/github/issues/cdanymar1/CLI-Argument-Mapper" alt="open issues">
        </a>
        <a href="https://github.com/cdanymar1/CLI-Argument-Mapper/blob/master/LICENSE">
            <img src="https://custom-icon-badges.demolab.com/badge/license-MIT-yellow?logo=law" alt="license">
        </a>
        <img src="https://custom-icon-badges.demolab.com/badge/ISO-23-blue?logo=cplusplus" alt="C++ ISO">
    </p>
    <h4>
        <a href="https://github.com/cdanymar1/CLI-Argument-Mapper/tree/master/example">Examples</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/CLI-Argument-Mapper/tree/master/docs">Documentation</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/CLI-Argument-Mapper/issues">Report Bug</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/CLI-Argument-Mapper/issues">Request Feature</a>
    </h4>
</div>
<br>
<details>
    <summary>Table of Contents</summary>
    <ol>
        <li><a href="#usage">Usage</a></li>
        <li><a href="#license">License</a></li>
    </ol>
</details>


## Usage

```c++
cli::args
    .on("help", help)
    .on("add", +[](int a, int b)
    {
        std::cout << a + b;
    });
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License
This library is under [MIT license](https://github.com/cdanymar1/CLI-Argument-Mapper/blob/master/LICENSE).
<p align="right">(<a href="#readme-top">back to top</a>)</p>
