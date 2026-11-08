/* SPDX-FileCopyrightText: 2024 Google LLC */
/* SPDX-License-Identifier: Apache-2.0 */

#pragma once

#include <pbl/drivers/button_id.h>
#include <pbl/util/uuid.h>

#include <process_management/app_install_types.h>

bool quick_launch_is_enabled(ButtonId button);
AppInstallId quick_launch_get_app(ButtonId button);
void quick_launch_set_app(ButtonId button, AppInstallId app_id);
void quick_launch_set_enabled(ButtonId button, bool enabled);
void quick_launch_set_quick_launch_setup_opened(uint8_t version);
uint8_t quick_launch_get_quick_launch_setup_opened(void);

bool quick_launch_single_click_is_enabled(ButtonId button);
AppInstallId quick_launch_single_click_get_app(ButtonId button);
void quick_launch_single_click_set_app(ButtonId button, AppInstallId app_id);
void quick_launch_single_click_set_enabled(ButtonId button, bool enabled);

//! Two buttons held together on the watchface.
typedef enum QuickLaunchCombo {
  QuickLaunchComboBackUp,
  QuickLaunchComboUpDown,
  QuickLaunchComboBackSelect,
  QuickLaunchComboBackDown,
  QuickLaunchComboUpSelect,
  QuickLaunchComboSelectDown,

  QuickLaunchComboCount,
} QuickLaunchCombo;

//! Bitmask of the combo's buttons, one bit per ButtonId.
uint8_t quick_launch_combo_get_buttons(QuickLaunchCombo combo);
bool quick_launch_combo_is_enabled(QuickLaunchCombo combo);
AppInstallId quick_launch_combo_get_app(QuickLaunchCombo combo);
void quick_launch_combo_set_app(QuickLaunchCombo combo, AppInstallId app_id);
void quick_launch_combo_set_enabled(QuickLaunchCombo combo, bool enabled);