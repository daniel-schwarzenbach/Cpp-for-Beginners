#!/usr/bin/env julia

using JSON

function update_launch_program(program::String)
  # Read the launch.json file as text and then parse it as JSON
  filename = ".vscode/launch.json"
  file_content = read(filename, String)
  parsed = JSON.parse(file_content)
  
  # update the "program" field of each configuration.
  for config ∈ parsed["configurations"]
    config["program"] = "\${fileDirname}/" * program
  end

  # Write the updated JSON back to the file with pretty printing
  open(filename, "w") do f
    write(f, JSON.json(parsed, 4))
  end
  println("Updated launch.json program to: ", program)
end

function main()
  if length(ARGS) < 1
  else
    # Use ARGS as the new arguments
    println("updating program to: ", ARGS[1])
    update_launch_program(ARGS[1])
  end
end

main()