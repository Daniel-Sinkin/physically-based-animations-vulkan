<!-- README.md -->
# physically-based-animations-vulkan

Realtime rigid-body / physically based animation visualization app using `ds-vk`.

## Dependency

`ds-vk` is fetched by CMake from `git@github.com:Daniel-Sinkin/ds-vk.git` and pinned to commit `62a43e99905177aef79099308976f70a2bd76a54`.

Private or redistribution-sensitive assets belong in ignored `local/assets/`.

## Build

```sh
cmake -S . -B build
cmake --build build --target physically_based_animations_vulkan
./run.sh
```
