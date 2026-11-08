# consnop/PebbleOS: patched firmware pipeline

This branch holds no PebbleOS code, only what turns upstream releases into patched firmware for a
Pebble Time 2:

- `patches/`: the changes, as `git format-patch` files, applied in order with `git am`.
- `pipeline.env`: which upstream release line to follow, and the board.
- `.github/workflows/firmware.yml`: daily, and whenever this branch changes, it takes the newest
  matching release of [coredevices/PebbleOS](https://github.com/coredevices/PebbleOS), applies the
  patches, builds the watch firmware in upstream's own build image (release config, slot 0), and
  publishes a release here named `<upstream tag>-consnop-<patch id>`. The watch reports that name
  as its firmware version. A release that already exists is not rebuilt.

If the patches stop applying, the run fails and opens an issue here.

## Current patches

- `0001`: Quick Launch on all six two-button combos, with a row for each in the watch's
  Settings → Quick Launch. Developed on the `combos` branch.

## Changing the patches

Work on a branch based on the upstream tag, then regenerate the files:

```sh
git format-patch <upstream tag>..<branch> -o patches/
```

## Flashing a release

With the phone's Developer Connection on and its port forwarded (`adb forward tcp:9000 tcp:9000`),
from a PebbleOS checkout: `pbl run -r phone --address 127.0.0.1` for a local build, or
`pebble fw install <file>.pbz --phone 127.0.0.1` for a downloaded bundle.

Scheduled workflows stop after 60 days without commits on this repo; GitHub emails before that.
