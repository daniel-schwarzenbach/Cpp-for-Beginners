#!/usr/bin/env julia

using JSON

function update_launch_args(new_args::Vector{String})
  # Read the launch.json file as text and then parse it as JSON
  filename = ".vscode/launch.json"
  file_content = read(filename, String)
  parsed = JSON.parse(file_content)
  
  # update the "args" field of each configuration.
  for config ∈ parsed["configurations"]
    config["args"] = new_args
  end

  # Write the updated JSON back to the file with pretty printing
  open(filename, "w") do f
    write(f, JSON.json(parsed, 4))
  end
  println("Updated launch.json args to: ", new_args)
end

function main()
  if length(ARGS) < 1
  else
    # Use ARGS as the new arguments
    println("updating args to: ", ARGS)
    update_launch_args(ARGS)
  end
end

main()