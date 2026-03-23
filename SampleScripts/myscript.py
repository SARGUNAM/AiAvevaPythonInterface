import AiAvevaPythonInterface

pml  = AiAvevaPythonInterface.PML()
pipe = AiAvevaPythonInterface.PIPE()
db   = AiAvevaPythonInterface.DB()
common = AiAvevaPythonInterface.COMMON()

# --- Print current MDB name ---
print("MDB:", common.mdb())

# --- Get all pipes in project ---
pipes = pipe.getAllPipesFromProject()
print(f"Total pipes found: {len(pipes)}")

# --- Send results back to PML as a global array ---
pml.Run("!!pyPipes = array()")
for i, name in enumerate(pipes, 1):
    pml.Run(f"!!pyPipes[{i}] = '{name}'")

print("Results stored in PML variable: !!pyPipes")
