Project = {
  name = "todo",
  kind = "ConsoleApp",
  language = "C++",
  dialect = "20",

  pch = "src/tdpch.h",

  files = {
    "src/*.cpp",
    "src/*.h",
  },

  includedirs = {
    "src",
    "${WORKSPACEDIR}vendor/spdlog/include",
    "${WORKSPACEDIR}vendor/Spider/Spider/src",
  },

  links = {
    "spider"
  }
}
