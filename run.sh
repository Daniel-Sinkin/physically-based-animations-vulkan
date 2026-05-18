#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "${repo_root}"

build_dir="${PBA_BUILD_DIR:-build}"
target="physically_based_animations_vulkan"

if [[ ! -f "${build_dir}/CMakeCache.txt" ]]; then
    cmake -S . -B "${build_dir}"
fi

build_log="$(mktemp "${TMPDIR:-/tmp}/pba_build.XXXXXX")"
cleanup() {
    rm -f "${build_log}"
}
trap cleanup EXIT

if ! cmake --build "${build_dir}" --target "${target}" -j >"${build_log}" 2>&1; then
    cat "${build_log}" >&2
    exit 1
fi

exec "${build_dir}/${target}" "$@"
