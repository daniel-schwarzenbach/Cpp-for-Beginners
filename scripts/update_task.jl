#!/usr/bin/env julia

using JSON

function update_task(new_target::String)
  # Read the launch.json file as text and then parse it as JSON
  filename = ".vscode/tasks.json"
  file_content = read(filename, String)
  parsed = JSON.parse(file_content)
  
  # update the "args" field of each configuration.
  for task ∈ parsed["tasks"]
    task["command"] = new_target
  end

  # Write the updated JSON back to the file with pretty printing
  open(filename, "w") do f
    write(f, JSON.json(parsed, 4))
  end
  println("Updated task.json command to: bash ", new_target)
end

function main()
  if length(ARGS) < 1
  else
    # Use ARGS as the new arguments
    println("updating task to: ", ARGS)
    update_launch_args(ARGS)
  end
end

main()