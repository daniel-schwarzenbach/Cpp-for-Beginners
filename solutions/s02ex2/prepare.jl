#!/usr/bin/env julia

programname="describe-moves"
args = ["Pe2e4", "Ke1e2", "nb8xe2", "Xc4", "''", "ke1e8=N"]

path::String = @__DIR__
include("../../scripts/update_args.jl")
include("../../scripts/update_program.jl")
include("../../scripts/update_task.jl")

update_launch_args(args)
update_launch_program(path * "/" * programname)
update_task(path * "/compile.sh")