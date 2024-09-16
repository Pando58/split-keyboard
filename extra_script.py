import os
Import("env")

env.Replace(COMPILATIONDB_INCLUDE_TOOLCHAIN=True) # Include toolchain paths
env.Replace(COMPILATIONDB_PATH="compile_commands.json") # Override compilation DB path
