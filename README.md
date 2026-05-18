<!-- README.md -->
# physically-based-animations-vulkan

Realtime rigid-body / physically based animation visualization app using `ds-vk`.

## Dependency

`ds-vk` is fetched by CMake from `git@github.com:Daniel-Sinkin/ds-vk.git` and pinned to commit `c8fd46f192aefbdd06572e93f9228e9b5f40c374`.

Private or redistribution-sensitive assets belong in ignored `local/assets/`.

## Build

```sh
cmake -S . -B build
cmake --build build --target physically_based_animations_vulkan
./run.sh
```
