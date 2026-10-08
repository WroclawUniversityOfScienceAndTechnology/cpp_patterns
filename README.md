# cpp_patterns

C++ design pattern examples for teaching with pwrforge and an x86 target.
The repository uses one host Python environment, one shared Docker image, and
one container session for building and running different examples.

Pattern examples included in this repository:

- [Adapter](src/adapter/README.md)
- [Bridge](src/bridge/README.md)
- [Builder](src/builder/README.md)
- [Chain of Responsibility](src/chain_of_responsibility/README.md)
- [Command](src/command/README.md)
- [Composite](src/composite/README.md)
- [Decorator](src/decorator/README.md)
- [Facade](src/facade/README.md)
- [Factory](src/factory/README.md)
- [Flyweight](src/flyweight/README.md)
- [Interpreter](src/interpreter/README.md)
- [Iterator](src/iterator/README.md)
- [Mediator](src/mediator/README.md)
- [Memento](src/memento/README.md)
- [Observer](src/observer/README.md)
- [Prototype](src/prototype/README.md)
- [Proxy](src/proxy/README.md)
- [Singleton](src/singleton/README.md)
- [State](src/state/README.md)
- [Strategy](src/strategy/README.md)
- [Template Method](src/template_method/README.md)
- [Visitor](src/visitor/README.md)

## Prepare the environment on the host

Docker is the default, following the generated `x86test` project structure.
Install Python 3.12 with venv support and Docker with Docker Compose. At the
repository root, run:

```bash
python3.12 -m venv .venv
source .venv/bin/activate
pip install pwrforge
pwrforge update
pwrforge docker run -- --rm
```

`pwrforge update` generates the project files and pulls or builds the shared
Docker image. If you use a locally built pwrforge release, install its wheel in
`.venv` instead of the PyPI release. No Python configuration helper is needed.

The last command opens a shell in `/workspace`, with this repository mounted
there. Keep that shell open and run the commands below **inside the container**.
The image already contains pwrforge and its Python environment; no additional
venv setup is needed inside it. `--rm` removes the container when you exit;
the shared image, source edits, and repository build caches remain available.

For later sessions, the host commands are simply:

```bash
source .venv/bin/activate
pwrforge docker run -- --rm
```

Run `pwrforge update` again when you change the project configuration. A second
host terminal can join the running container with `pwrforge docker exec`.

## Build and run examples inside the container

The default demo is `decorator/decorator1`. These commands select, build, and run
three different demos in the same container:

```bash
EXAMPLE=decorator/decorator1 pwrforge run --build
EXAMPLE=bridge/pimpl pwrforge run --build
EXAMPLE=builder/builder3 pwrforge run --build
```

Some demos, including `builder/builder3`, wait for **Enter** before returning
to the shell.

To keep one example selected for subsequent commands in that shell:

```bash
export EXAMPLE=decorator/decorator1
pwrforge build --target x86 --profile Debug
pwrforge run
```

Edit `src/decorator/decorator1/decorator1.cpp`, then repeat `pwrforge build` and
`pwrforge run`. This demo shows a decorated circle before and after resizing
its underlying circle. Ordinary demos do not need GoogleTest; some `_ex`
exercises and the separate generated test scaffolding use it. See
[running exercise tests](#run-the-selected-examples-tests) below.

`--target x86` selects the architecture; `EXAMPLE` selects a directory relative
to `src/`. Only that example is configured and compiled. Its executable is
copied to `build/x86/Debug/bin/cpp_patterns.elf`, which `pwrforge run` finds
automatically. Switching back to a previously built example reuses its object
files and refreshes this executable. A run without `--build` executes the last
successful build for the requested profile.

All four standard profiles are available: `Debug`, `Release`, `RelWithDebInfo`,
and `MinSizeRel`. For example, still inside the same container:

```bash
EXAMPLE=builder/builder3 pwrforge build --profile Release
pwrforge run --profile Release
```

Pass program arguments after `--` when the selected program accepts them.
Use `exit` when you finish the container session.

For a repository-wide default, change this table in `pwrforge.toml`:

```toml
[project.cmake-variables]
PATTERN_EXAMPLE = "bridge/pimpl"
```

Then run `pwrforge update`, `unset EXAMPLE` if you exported it, and
`pwrforge run --build`. The shell's `EXAMPLE` overrides the configured default.

## Run the selected example's tests

The `_ex` exercises contain GoogleTest tests in the example executable itself.
Selecting an exercise and running it executes its tests. The shared Docker
image already includes GoogleTest; use these commands **inside your running
container**, from `/workspace`:

```bash
EXAMPLE=adapter/adapter_ex pwrforge run --build
EXAMPLE=bridge/bridge_ex pwrforge run --build
EXAMPLE=builder/builder_ex pwrforge run --build
EXAMPLE=decorator/decorator_ex pwrforge run --build
```

For one exercise that you will edit repeatedly, keep its selection in the shell:

```bash
export EXAMPLE=builder/builder_ex
pwrforge run --build
```

Pass GoogleTest options after `--` to list tests or run one test:

```bash
pwrforge run -- --gtest_list_tests
pwrforge run -- --gtest_filter=Evaluate.PersonTest
pwrforge run --build -- --gtest_filter='Evaluate.*'
```

These commands apply to the selected Builder exercise. Rebuild after changing
the source or choosing another example; without `--build`, `pwrforge run` uses
the last built executable for that profile. Test output shows `[ RUN ]`,
`[ OK ]`, and the final `[ PASSED ]` or `[ FAILED ]` summary.
See the [GoogleTest options](https://google.github.io/googletest/advanced.html#running-test-programs-advanced-options)
for more filtering and execution options.

`pwrforge test` builds and runs the separate project-level suite under `tests/`.
It does not use `EXAMPLE` to select these exercise executables. For tests already
embedded in an example, use `pwrforge run --build` as shown above.

## Source layout and generated files

All pattern folders live under `src/`, with their existing code, local CMake
files, and teaching notes kept together. For example:

```text
src/
  CMakeLists.txt
  decorator/
    README.md
    decorator1/
      CMakeLists.txt
      decorator1.cpp
  builder/
  bridge/
  ...
```

This follows pwrforge's generated source layout: its checks scan `src/` and its
Conan recipe exports `src/*`. Example selections remain `decorator/decorator1`,
`builder/builder3`, etc.; do not add `src/` to `EXAMPLE`.
After updating an older checkout with examples at the repository root, run
`pwrforge clean` once before rebuilding to discard the old CMake paths.
Historical build outputs moved with the folders remain on disk but are ignored
at their new paths by the standard `.gitignore` rules.

The root CMake/Conan files, all four build profiles, Docker configuration,
VS Code tasks, test scaffolding, and the full GitLab CI pipeline are generated
by `pwrforge update`. The custom selection logic lives in `src/CMakeLists.txt`.
That file, this README, and `.vscode/launch.json` are protected through
`update-exclude`.

`.devcontainer/Dockerfile-custom` adds the examples' Boost, cpprestsdk, and
GoogleTest system libraries to the standard Docker environment. Source edits
and example selection reuse the same `cpp_patterns-dev:1.0` image. The entire
repo shares `.venv/`, `.conan2/`, and `build/`; `max-build-jobs = 2` limits
compilation parallelism. The full generated `.gitignore` is retained, with
local venv/wheel ignores and an exception for the shared debugger configuration
appended. The CI custom layer corrects the x86 artifact paths while retaining
the generated pipeline stages and jobs.

The custom CMake layer also keeps the compiler's default C++ library ABI so
examples can link the Ubuntu system libraries; the generated Conan profiles
otherwise force the legacy ABI, which breaks Boost serialization linkage.

Some archived projects need source/build repairs: `facade/facade1` and
`interpreter/interpreter2` contain Windows projects, and
`chain_of_responsibility/chain1` has its `main` commented out. Examples without
a `CMakeLists.txt` need one before they can be selected. To list existing
projects, from either the host or the container:

```bash
find src -name CMakeLists.txt
```

## Optional native builds

Native users must install the dependencies listed in the generated
`.devcontainer/Dockerfile`, `.devcontainer/Dockerfile-custom`, and
`.devcontainer/requirements.txt` themselves. On Ubuntu 24.04:

```bash
sudo apt-get update
sudo apt-get install -y python3 python3-pip python3.12-venv git build-essential \
  pkg-config graphviz sudo cppcheck lib32z1 make cmake clang clang-format \
  clang-tidy doxygen libcmocka0 libcmocka-dev gdb screen wget curl openssh-server \
  libboost-system-dev libboost-serialization-dev libcpprest-dev libgtest-dev
python3.12 -m venv .venv
source .venv/bin/activate
pip install pwrforge
pip install -r .devcontainer/requirements.txt
```

Set `build-env = "native"` in `pwrforge.toml`, then run:

```bash
pwrforge clean
pwrforge update
EXAMPLE=decorator/decorator1 pwrforge run --build
```

Use `pwrforge clean` before switching between host and container builds so CMake
can regenerate its cached paths for the new environment.

## References

These teaching examples are based on
[Design Patterns in Modern C++](https://www.udemy.com/course/patterns-cplusplusout/).

## Debug with VS Code in the running container

1. Start the container with `pwrforge docker run -- --rm` as above and leave
   its shell open.
2. Install the **Dev Containers** extension (`ms-vscode-remote.remote-containers`)
   in VS Code on the host. Open the Command Palette and choose
   **Dev Containers: Attach to Running Container...**, then select the running
   container using the `cpp_patterns-dev:1.0` image.
3. In the attached VS Code window, open `/workspace` and install the Microsoft
   **C/C++** extension (`ms-vscode.cpptools`) **in the container**.
4. In that window's terminal, build the example with debug symbols:

   ```bash
   EXAMPLE=decorator/decorator1 pwrforge build --target x86 --profile Debug
   ```

5. Open `src/decorator/decorator1/decorator1.cpp` and set a breakpoint on
   `circle.resize(2);`. In **Run and Debug**, select **C++ example (Docker)**
   and press **F5**. Inspect `circle.radius`: it is `2` at the breakpoint and
   becomes `4` after **F10** steps over the resize. **F5** continues execution;
   **Shift+F5** stops debugging.

The shared `.vscode/launch.json` launches
`build/x86/Debug/bin/cpp_patterns.elf` with the container's `/usr/bin/gdb`.
Build the desired example in `Debug` before each debugging session; **F5**
runs the last Debug executable without rebuilding it. The same configuration
works for other examples after you build them. Add arguments to its `args`
array when needed. VS Code attaches to the existing container, so building,
running, and debugging share the same environment and source files.

For a terminal debugger in the same container, build the Debug example and
run `pwrforge debug --target x86`.

See the official VS Code instructions for
[attaching to a running container](https://code.visualstudio.com/docs/devcontainers/attach-container)
and [C++ debugging configuration](https://code.visualstudio.com/docs/cpp/launch-json-reference).
