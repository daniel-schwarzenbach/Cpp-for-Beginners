#!/usr/bin/env julia
include("../scripts/update_args.jl")
include("../scripts/update_program.jl")
include("../scripts/update_task.jl")

update_launch_args(["31.342", "asdf", "hello world"])
update_launch_program("\${workspaceFolder}/lesson1/isPrime")
update_task("./lesson1/compile.sh")