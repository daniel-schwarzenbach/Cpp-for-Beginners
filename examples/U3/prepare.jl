#!/usr/bin/env julia
args = [""]

path::String = @__DIR__
include("../../scripts/update_args.jl")
include("../../scripts/update_program.jl")
include("../../scripts/update_task.jl")

update_launch_args(args)
update_launch_program(path * "/" * "\${fileBasenameNoExtension}")
update_task(path * "/compile.sh")