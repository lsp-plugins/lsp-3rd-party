#!/bin/bash

find . -type f -iname "*.h" -exec sed -i -E 's|#include <pipewire/|#include <pw-headers/pipewire/|g' {} +
find . -type f -iname "*.h" -exec sed -i -E 's|#include <spa/|#include <pw-headers/spa/|g' {} +
find . -type f -iname "*.h" -exec sed -i -E 's|#include <wp/|#include <pw-headers/wp/|g' {} +
