#!/usr/bin/env julia

path::String = @__DIR__
include("../scripts/update_args.jl")
include("../scripts/update_program.jl")
include("../scripts/update_task.jl")

update_launch_args([""])
update_launch_program(path * "/test")
update_task("bash " * path * "/compile.sh")