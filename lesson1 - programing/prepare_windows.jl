#!/usr/bin/env julia

path::String = @__DIR__
include("../scripts/update_args.jl")
include("../scripts/update_program.jl")
include("../scripts/update_task.jl")

update_launch_args(["31.342", "asdf", "hello world"])
update_launch_program("\${workspaceFolder}/lesson1/isPrime.exe")
update_task("./lesson1/compile.bat")
# OR more modular
# update_launch_program(path * "/isPrime.exe")
# update_task(path * "/compile.bat")
