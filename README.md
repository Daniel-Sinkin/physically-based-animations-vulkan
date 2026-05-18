<!-- README.md -->
# physically-based-animations-vulkan

Realtime rigid-body / physically based animation visualization app using `ds-vk`.

## Dependency

`ds-vk` is pulled in as a Git submodule at `external/ds-vk`:

```sh
git submodule update --init --recursive
```

Private or redistribution-sensitive assets belong in ignored `local/assets/`.

## Build

```sh
cmake -S . -B build
cmake --build build --target physically_based_animations_vulkan
./run.sh
```
