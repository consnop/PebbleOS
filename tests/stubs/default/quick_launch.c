/* SPDX-FileCopyrightText: 2024 Google LLC */
/* SPDX-License-Identifier: Apache-2.0 */

#include <pbl/kernel/compiler.h>

#include <shell/normal/quick_launch.h>

void PBL_WEAK quick_launch_remove_app(const Uuid *uuid) {
}

AppInstallId PBL_WEAK quick_launch_get_app(ButtonId button) {
  return 0;
}

AppInstallId PBL_WEAK quick_launch_single_click_get_app(ButtonId button) {
  return 0;
}

AppInstallId PBL_WEAK quick_launch_combo_get_app(QuickLaunchCombo combo) {
  return 0;
}
