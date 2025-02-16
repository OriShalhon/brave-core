/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_rewards/core/engine/state/state_migration_v3.h"

#include <utility>

namespace brave_rewards::internal::state {

StateMigrationV3::StateMigrationV3() = default;

StateMigrationV3::~StateMigrationV3() = default;

void StateMigrationV3::Migrate(ResultCallback callback) {
  // In this migration we migrated anon address to uphold wallet in preferences
  // because anon address was removed we can also remove this step
  // Ref: https://github.com/brave/brave-browser/issues/11150
  std::move(callback).Run(mojom::Result::OK);
}

}  // namespace brave_rewards::internal::state
