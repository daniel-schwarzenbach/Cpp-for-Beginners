#!/usr/bin/env julia
include("../scripts/update_args.jl")
include("../scripts/update_program.jl")

update_launch_args(["31.342", "asdf", "hello world"])
update_launch_program("isPrime")