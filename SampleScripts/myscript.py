import AiAvevaPythonInterface

pml    = AiAvevaPythonInterface.PML()
pipe   = AiAvevaPythonInterface.PIPE()
common = AiAvevaPythonInterface.COMMON()

# --- Print current MDB name ---
print("MDB:", common.mdb())

# --- Get bore of the current element ---
currentElement = common.ce
bore = pipe.getAttribute(currentElement, "BORE")
print(f"Current element : {currentElement}")
print(f"Bore            : {bore}")

# --- Send !!resultBore back to PML ---
pml.Run(f"!!resultBore = {bore}")
print("!!resultBore set in PML")

# --- Get all pipes in project ---
pipes = pipe.getAllPipesFromProject()
print(f"Total pipes found: {len(pipes)}")

# --- Send pipe list back to PML as !!pyPipes array ---
pml.Run("!!pyPipes = array()")
for i, name in enumerate(pipes, 1):
    pml.Run(f"!!pyPipes[{i}] = '{name}'")
print("!!pyPipes array set in PML")
