/* SPDX-FileCopyrightText: 2024 Google LLC */
/* SPDX-License-Identifier: Apache-2.0 */

#pragma once

#include <applib/ui/window.h>
#include <shell/normal/quick_launch.h>

typedef enum QuickLaunchMenuCategory {
  //! Entries that are only visible in Quick Launch, e.g. the system toggles.
  QuickLaunchMenuCategoryActions,
  //! Regular launcher apps.
  QuickLaunchMenuCategoryApps,
} QuickLaunchMenuCategory;

typedef enum QuickLaunchBindingType {
  QuickLaunchBindingHold,
  QuickLaunchBindingTap,
  QuickLaunchBindingCombo,
} QuickLaunchBindingType;

//! One Quick Launch trigger: a held or tapped button, or a two-button combo.
typedef struct QuickLaunchBinding {
  QuickLaunchBindingType type;
  union {
    ButtonId button; //!< For holds and taps
    QuickLaunchCombo combo;
  };
} QuickLaunchBinding;

//! The app or action the binding launches, or INSTALL_ID_INVALID.
AppInstallId quick_launch_binding_get_app(QuickLaunchBinding binding);

//! Binds an app or action, or with INSTALL_ID_INVALID unassigns and disables the binding.
void quick_launch_binding_set_app(QuickLaunchBinding binding, AppInstallId app_id);

//! @param binding The binding being edited.
//! @param category Which kind of target the menu lists.
//! @param parent The category menu to unwind along with this one on selection.
void quick_launch_app_menu_window_push(QuickLaunchBinding binding, QuickLaunchMenuCategory category,
                                       Window *parent);
